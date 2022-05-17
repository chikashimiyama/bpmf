#pragma once

#include <string>
#include <filesystem>
#include <optional>

namespace bpmf::core
{
    struct Result
    {
        std::string input;
        std::optional<std::filesystem::path> path;
        std::optional<size_t> estimatedBPM;
    };
}
