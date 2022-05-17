#pragma once

#include <vector>

#include <bpmfcore/IAnalyzer.h>
#include <bpmfcore/ITrack.h>

namespace bpmf
{
    class Analyzer : public core::IAnalyzer
    {
    public:
        Analyzer(const core::ITrack& track);

        ~Analyzer() override = default;

        const std::optional<double>& getBPM() override;

    private:
        std::optional<double> result_;
    };
}
