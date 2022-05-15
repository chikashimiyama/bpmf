#include "Track.h"

#include <bpmfcore/Utils.h>

#include <dr_mp3.h>

namespace bpmf
{
    namespace
    {
        Track::Audio loadFromFile(const std::filesystem::path& path)
        {
            auto size = drmp3_uint64();
            auto config = drmp3_config();
            const auto* data = drmp3_open_file_and_read_pcm_frames_f32(path.c_str(), &config, &size, NULL);
            return {
                static_cast<float>(config.sampleRate),
                core::monauralize(std::vector<float>(data, (data + size / config.channels)), config.channels)
            };
        }
    }

    Track::Track(const std::filesystem::path& path)
    : audio_(loadFromFile(path))
    {
    }

    const Track::Audio& Track::getAudio() const
    {
        return audio_;
    }
}
