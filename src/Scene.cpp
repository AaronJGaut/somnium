#include "somnium/Scene.h"
#include "somnium/impl/Context.h"

namespace somnium
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
