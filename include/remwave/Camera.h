#pragma once
#include <memory>
#include "remwave/Scene.h"

namespace remwave
{
    class Camera
    {
        public:
        Camera();
        ~Camera();
        Camera(Camera&& other);
        Camera& operator=(Camera&& other);

        private:
        class Impl;
        std::unique_ptr<Impl> _M_impl;
    };
}
