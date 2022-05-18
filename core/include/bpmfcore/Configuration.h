#pragma once

#include <queue>
#include <deque>
#include <filesystem>

namespace bpmf::core
{
    struct BPMRange
    {
        const size_t min;
        const size_t max;
    };

    struct Configuration
    {
        const bool verbose;
        const BPMRange bpmRange;
        const std::queue<std::string> paths;
    };
}
