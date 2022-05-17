#pragma once

#include <vector>
#include <memory>

namespace bpmf::core
{
    class ITrack
    {
    public:

        virtual ~ITrack() = default;

        virtual float getSampleRate() const = 0;

        virtual const std::vector<float>& getSamples() const = 0;
    };

    using TrackPtr = std::unique_ptr<ITrack>;
}