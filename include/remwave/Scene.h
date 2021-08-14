#pragma once
#include <memory>

namespace remwave
{
    class Scene
    {
        public:
        Scene();
        ~Scene();
        Scene(Scene&& other);
        Scene& operator=(Scene&& other);

        private:
        class Impl;
        std::unique_ptr<Impl> _M_impl;
    };
}
