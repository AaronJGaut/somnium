#pragma once
#include <memory>
#include "somnium/Target.h"
#include "somnium/Scene.h"
#include "somnium/Camera.h"

namespace somnium
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
