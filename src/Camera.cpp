#include "remwave/Camera.h"

namespace remwave
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
