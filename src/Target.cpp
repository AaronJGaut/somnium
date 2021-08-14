#include "somnium/Target.h"

namespace somnium
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
