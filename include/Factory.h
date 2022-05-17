#pragma once

#include <bpmfcore/IFactory.h>

namespace bpmf
{
    class Factory : public core::IFactory
    {
    public:
        ~Factory() override = default;

        core::AnalyzerPtr createAnalyzer(const core::ITrack& track) const override;

        core::TrackPtr createTrack(const std::filesystem::path& path) const override;

        core::FilePathValidatorPtr createFilePathValidator(const std::string &file) const override;

        core::PrinterPtr createVerbosePrinter(const std::vector<core::Result>& results) const override;

    };
}