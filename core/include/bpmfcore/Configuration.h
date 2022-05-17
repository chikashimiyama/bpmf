#pragma once

#include <queue>
#include <deque>
#include <filesystem>

namespace bpmf::core
{
    struct Configuration
    {
        const bool verbose;
        const size_t minBPM;
        const size_t maxBPM;
        const std::queue<std::string> paths;
    };
}
