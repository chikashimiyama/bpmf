#include "Application.h"

namespace bpmf::core
{
    Application::Application(int argc, char **argv, const IFactory &factory)

    {

    }

    const std::vector<std::filesystem::path>& Application::getFiltered()
    {
        return result_;
    }
}