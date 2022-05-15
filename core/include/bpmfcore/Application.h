#pragma once

#include <vector>
#include <filesystem>

#include "IFactory.h"
#include "Parser.h"

namespace bpmf::core
{
    class Application
    {
    public:
        Application(int argc, char** argv, const IFactory& factory);

        const std::vector<std::filesystem::path>& getFiltered();

    private:
        std::vector<std::filesystem::path> result_;
    };
}
