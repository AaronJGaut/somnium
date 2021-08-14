#include "remwave/Renderer.h"

namespace remwave
{

class Renderer::Impl
{
};

Renderer::Renderer()
    : _M_impl(std::make_unique<Renderer::Impl>())
{}
Renderer::~Renderer() = default;
Renderer::Renderer(Renderer&& other) = default;
Renderer& Renderer::operator=(Renderer&& other) = default;
void Renderer::render(Target& target, const Scene& scene, const Camera& camera)
{}

}
