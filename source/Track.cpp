#include "Track.h"

#include <bpmfcore/Main.h>

#include <dr_mp3.h>

namespace bpmf
{
    namespace
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

        std::tuple<float, std::vector<float>> loadFromFile(const std::filesystem::path& path)
        {
            auto size = drmp3_uint64();
            auto config = drmp3_config();
            const auto* data = drmp3_open_file_and_read_pcm_frames_f32(path.c_str(), &config, &size, NULL);
            return {
                static_cast<float>(config.sampleRate),
                monauralize(std::vector<float>(data, (data + size / config.channels)), config.channels)
            };
        }
    }

    Track::Track(const std::filesystem::path& path)
    {
        auto [sampleRate, samples] = loadFromFile(path);
        sampleRate_ = sampleRate;
        samples_ = std::move(samples);
    }

    const std::vector<float>& Track::getSamples() const
    {
        return samples_;
    }

    float Track::getSampleRate() const
    {
        return sampleRate_;
    }
}
