#pragma once

#include <vector>
#include <algorithm>
#include <filesystem>

#include "IFactory.h"
#include "Configuration.h"
#include "Result.h"

namespace bpmf::core
{
    std::optional<Configuration> parse(int argc, const char* const* argv, std::string& instruction);

    std::vector<Result> process(const Configuration& configuration, const IFactory& factory);

    std::string print(const Configuration& configuration, const std::vector<Result>& results, const IFactory& factory);
}
