#pragma once

#include <vector>

#include <bpmfcore/IAnalyzer.h>

namespace bpmf
{
    class Analyzer : public core::IAnalyzer
    {
    public:
        Analyzer(float sampleRate, const std::vector<float>& samples);

        ~Analyzer() override = default;

        const std::optional<double>& getBPM() override;

    private:
        std::optional<double> result_;
    };
}
