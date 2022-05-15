#pragma once

#include <vector>
#include <memory>

namespace bpmf::core
{
    class ITrack
    {
    public:
        struct Audio
        {
            float sampleRate;
            std::vector<float> samples;
        };

        virtual ~ITrack() = default;

        virtual const Audio& getAudio() const = 0;
    };

    using TrackPtr = std::unique_ptr<ITrack>;
}