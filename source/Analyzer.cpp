#include "Analyzer.h"

#include <MiniBpm.h>

namespace bpmf
{
    Analyzer::Analyzer(float sampleRate, const std::vector<float>& samples)
    {
        auto miniBpm = breakfastquay::MiniBPM(sampleRate);
        miniBpm.setBPMRange(50, 190);
        auto result = miniBpm.estimateTempoOfSamples(samples.data(), static_cast<int>(samples.size()));
        if(result == 0.0)
            result_ = std::nullopt;
        result_ = result;
    }

    const std::optional<double>& Analyzer::getBPM()
    {
        return result_;
    }
}
