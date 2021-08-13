#pragma once
#include <memory>

namespace remwave
{

void check();

class VulkanInstance
{
    public:
    VulkanInstance();
    ~VulkanInstance();
    VulkanInstance(VulkanInstance&& other);
    VulkanInstance& operator=(VulkanInstance&& other);

    private:
    class Impl;
    std::unique_ptr<Impl> _M_impl;
};

}
