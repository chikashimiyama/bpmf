#pragma once

#include <filesystem>

#include "IAnalyzer.h"
#include "ITrack.h"
#include "IFilePathValidator.h"
#include "IPrinter.h"
#include "Result.h"

namespace bpmf::core
{
    class IFactory
    {
    public:
        virtual ~IFactory() = default;

        virtual FilePathValidatorPtr createFilePathValidator(const std::string& file) const = 0;

        virtual TrackPtr createTrack(const std::filesystem::path& path) const = 0;

        virtual AnalyzerPtr createAnalyzer(const ITrack& track) const = 0;

        virtual PrinterPtr createVerbosePrinter(const std::vector<Result>& results) const = 0;

    };
}