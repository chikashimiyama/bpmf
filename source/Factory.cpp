#include "Factory.h"
#include "Analyzer.h"
#include "Track.h"

namespace bpmf
{

    core::AnalyzerPtr Factory::createAnalyzer(float sampleRate, const std::vector<float>& samples) const
    {
        return std::make_unique<Analyzer>(sampleRate, samples);
    }

    core::TrackPtr Factory::createTrack(const std::filesystem::path& path) const
    {
        return std::make_unique<Track>(path);
    }
}