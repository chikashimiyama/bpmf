#include "Utils.h"

namespace bpmf::core
{
    std::vector<float> monauralize(const std::vector<float>& interleavedSamples, size_t channels)
    {
        auto monaural = std::vector<float>();
        const auto monoLength = interleavedSamples.size() / channels;
        monaural.reserve(monoLength);

        for (auto i = 0; i < monoLength; ++i)
        {
            auto sum = 0.0f;
            for (auto j = 0; j < channels; ++j)
                sum += interleavedSamples[i * channels + j];
            monaural.push_back(sum / static_cast<float>(channels));
        }
        return monaural;
    }
}