#pragma once
#include <vulkan/vulkan.h>
#include <memory>

namespace remwave
{
    class Context
    {
        public:
        static const Context& get();
        ~Context();
        Context(Context&& other);
        Context& operator=(Context&& other);
        const VkDevice& device();

        private:
        Context();
        class Impl;
        std::unique_ptr<Impl> _M_impl;
    };
}
