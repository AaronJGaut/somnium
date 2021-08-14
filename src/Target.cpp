#include "remwave/Target.h"

namespace remwave
{

class Target::Impl
{
};

Target::Target()
    : _M_impl(std::make_unique<Target::Impl>())
{}
Target::~Target() = default;
Target::Target(Target&& other) = default;
Target& Target::operator=(Target&& other) = default;

}
