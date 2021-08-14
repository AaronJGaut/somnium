#include "somnium/Camera.h"

namespace somnium
{

class Camera::Impl
{
};

Camera::Camera()
    : _M_impl(std::make_unique<Camera::Impl>())
{}
Camera::~Camera() = default;
Camera::Camera(Camera&& other) = default;
Camera& Camera::operator=(Camera&& other) = default;

}
