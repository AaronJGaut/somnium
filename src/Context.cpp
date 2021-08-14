#include <iostream>
#include <vector>
#include <optional>

#include "remwave/impl/Context.h"

namespace
{
    struct QueueFamilyIndices
    {
        std::optional<uint32_t> graphics;

        explicit QueueFamilyIndices(const VkPhysicalDevice& device)
        {
            uint32_t queue_family_count = 0;
            vkGetPhysicalDeviceQueueFamilyProperties(device, &queue_family_count, nullptr);
            VkQueueFamilyProperties queue_families[queue_family_count];
            vkGetPhysicalDeviceQueueFamilyProperties(device, &queue_family_count, queue_families);
            for (size_t i = 0; i < queue_family_count; ++i)
            {
                if (queue_families[i].queueFlags & VK_QUEUE_GRAPHICS_BIT)
                {
                    graphics = i;
                }
                if (is_complete())
                {
                    break;
                }
            }
        }

        bool is_complete()
        {
            return graphics.has_value();
        }
    };
}

namespace remwave
{

class Context::Impl
{
    public:
    Impl()
        : _M_instance{}
        , _M_device{}
        , _M_graphics_queue{}
    {
        // create vulkan instance
        {
            uint32_t extension_count{};
            vkEnumerateInstanceExtensionProperties(nullptr, &extension_count, nullptr);
            std::cout << extension_count << " extensions supported" << std::endl;

            VkApplicationInfo app_info{};
            app_info.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
            app_info.pApplicationName = "remwave";
            app_info.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
            app_info.pEngineName = "No Engine";
            app_info.engineVersion = VK_MAKE_VERSION(1, 0, 0);
            app_info.apiVersion = VK_API_VERSION_1_0;

            VkInstanceCreateInfo create_info{};
            create_info.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
            create_info.pApplicationInfo = &app_info;
            if (vkCreateInstance(&create_info, nullptr, &_M_instance) != VK_SUCCESS)
            {
                throw std::runtime_error("failed to create vulkan instance");
            }
        }

        // pick physical device
        VkPhysicalDevice physical_device{VK_NULL_HANDLE};
        {
            uint32_t physical_device_count{};
            vkEnumeratePhysicalDevices(_M_instance, &physical_device_count, nullptr);
            std::cout << physical_device_count << " physical devices found with Vulkan support" << std::endl;

            std::vector<VkPhysicalDevice> physical_devices{physical_device_count};
            vkEnumeratePhysicalDevices(_M_instance, &physical_device_count, physical_devices.data());

            uint32_t best_score = 0;
            for (const auto& device: physical_devices)
            {
                QueueFamilyIndices queue_family_indices{device};
                if (!queue_family_indices.is_complete())
                {
                    continue;
                }

                VkPhysicalDeviceProperties properties;
                VkPhysicalDeviceFeatures features;
                vkGetPhysicalDeviceProperties(device, &properties);
                vkGetPhysicalDeviceFeatures(device, &features);

                uint32_t score = 1;
                if (properties.deviceType == VK_PHYSICAL_DEVICE_TYPE_DISCRETE_GPU)
                {
                    score += 1000;
                }
                if (score > best_score)
                {
                    physical_device = device;
                    best_score = score;
                }
            }
            if (physical_device == VK_NULL_HANDLE)
            {
                throw std::runtime_error("no suitable physical devices found");
            }
            VkPhysicalDeviceProperties properties;
            vkGetPhysicalDeviceProperties(physical_device, &properties);
            std::cout << "Using physical device " << properties.deviceName << std::endl;
        }

        // create logical device
        {
            QueueFamilyIndices indices{physical_device};
            VkDeviceQueueCreateInfo queue_create_info{};
            queue_create_info.sType = VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO;
            queue_create_info.queueFamilyIndex = indices.graphics.value();
            queue_create_info.queueCount = 1;
            float queue_priority = 1.0f;
            queue_create_info.pQueuePriorities = &queue_priority;
            VkPhysicalDeviceFeatures device_features{};
            VkDeviceCreateInfo create_info{};
            create_info.sType = VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO;
            create_info.pQueueCreateInfos = &queue_create_info;
            create_info.queueCreateInfoCount = 1;
            create_info.pEnabledFeatures = &device_features;
            if (vkCreateDevice(physical_device, &create_info, nullptr, &_M_device) != VK_SUCCESS)
            {
                throw std::runtime_error("failed to create logical device");
            }
            vkGetDeviceQueue(_M_device, indices.graphics.value(), 0, &_M_graphics_queue);
        }
    }
    ~Impl()
    {
        vkDestroyDevice(_M_device, nullptr);
        vkDestroyInstance(_M_instance, nullptr);
    }
    private:
    VkInstance _M_instance;
    VkDevice _M_device;
    VkQueue _M_graphics_queue;
};

Context::Context()
    : _M_impl(std::make_unique<Context::Impl>())
{}
Context::~Context() = default;
Context::Context(Context&& other) = default;
Context& Context::operator=(Context&& other) = default;

const Context& Context::get()
{
    static Context context{};
    return context;
}

}
