#pragma once
#include <memory>
#include "somnium/Scene.h"

namespace somnium
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
