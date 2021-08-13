#include "remwave.h"
int main()
{
    remwave::check();
    remwave::VulkanInstance instance;
    remwave::VulkanInstance instance2 = std::move(instance);
}
