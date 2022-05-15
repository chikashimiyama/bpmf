#pragma once

#include <bpmfcore/IFactory.h>

namespace bpmf
{
    class Factory : public core::IFactory
    {
    public:
        ~Factory() override = default;

        core::AnalyzerPtr createAnalyzer(float sampleRate, const std::vector<float>& samples) const override;

        core::TrackPtr createTrack(const std::filesystem::path& path) const override;
    };
}