#include "Factory.h"

#include <bpmfcore/FilePathValidator.h>
#include <bpmfcore/VerbosePrinter.h>
#include "Analyzer.h"
#include "Track.h"

namespace bpmf
{
    core::AnalyzerPtr Factory::createAnalyzer(const core::ITrack& track) const
    {
        return std::make_unique<Analyzer>(track);
    }

    core::TrackPtr Factory::createTrack(const std::filesystem::path& path) const
    {
        return std::make_unique<Track>(path);
    }

    core::FilePathValidatorPtr Factory::createFilePathValidator(const std::string &file) const
    {
        return std::make_unique<core::FilePathValidator>(file);
    }

    core::PrinterPtr Factory::createVerbosePrinter(const std::vector<core::Result>& results) const
    {
        return std::make_unique<core::VerbosePrinter>(results);
    }
}
