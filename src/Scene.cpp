#include "remwave/Scene.h"
#include "remwave/impl/Context.h"

namespace remwave
{

class Scene::Impl
{
    public:
    Impl()
    {
        Context::get();
    }
};

Scene::Scene()
    : _M_impl(std::make_unique<Scene::Impl>())
{}
Scene::~Scene() = default;
Scene::Scene(Scene&& other) = default;
Scene& Scene::operator=(Scene&& other) = default;

}
