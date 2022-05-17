#include "Analyzer.h"

#include <MiniBpm.h>

namespace bpmf
{
    Analyzer::Analyzer(const core::ITrack& track)
    {
        auto miniBpm = breakfastquay::MiniBPM(track.getSampleRate());
        miniBpm.setBPMRange(50, 190);
        const auto& samples = track.getSamples();
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
