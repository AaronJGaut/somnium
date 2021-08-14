#pragma once
#include <memory>

namespace remwave
{
    class Target
    {
        public:
        Target();
        ~Target();
        Target(Target&& other);
        Target& operator=(Target&& other);

        private:
        class Impl;
        std::unique_ptr<Impl> _M_impl;
    };
}
