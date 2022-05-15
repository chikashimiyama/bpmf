#pragma once

#include <vector>
#include <algorithm>

namespace bpmf::core
{
    std::vector<float> monauralize(const std::vector<float>& interleavedSamples, size_t channels);
}
