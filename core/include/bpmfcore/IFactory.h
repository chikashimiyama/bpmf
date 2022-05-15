#pragma once

#include <filesystem>

#include "IAnalyzer.h"
#include "ITrack.h"

namespace bpmf::core
{
    class IFactory
    {
    public:
        virtual ~IFactory() = default;

        virtual AnalyzerPtr createAnalyzer(float sampleRate, const std::vector<float>& samples) const = 0;

        virtual TrackPtr createTrack(const std::filesystem::path& path) const = 0;

    };
}