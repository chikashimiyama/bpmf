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

        const Audio& getAudio() const override;

    private:
        const Audio audio_;
    };
}