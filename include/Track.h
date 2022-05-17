#pragma once

#include <filesystem>
#include <bpmfcore/ITrack.h>

namespace bpmf
{
    class Track : public core::ITrack
    {
    public:
        Track(const std::filesystem::path& path);

        ~Track() override = default;

        const std::vector<float>& getSamples() const override;

        float getSampleRate() const override;

    private:
        std::vector<float> samples_;
        float sampleRate_;
    };
}