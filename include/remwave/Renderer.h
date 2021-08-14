#pragma once
#include <memory>
#include "remwave/Target.h"
#include "remwave/Scene.h"
#include "remwave/Camera.h"

namespace remwave
{
    class Renderer
    {
        public:
        Renderer();
        ~Renderer();
        Renderer(Renderer&& other);
        Renderer& operator=(Renderer&& other);

        void render(Target& target, const Scene& scene, const Camera& camera);

        private:
        class Impl;
        std::unique_ptr<Impl> _M_impl;
    };
}
