#pragma once

#include <gmock/gmock.h>

#include <bpmfcore/IFactory.h>

namespace bpmf::core
{
    class FactoryMock : public IFactory
    {
    public:
        MOCK_METHOD(FilePathValidatorPtr, createFilePathValidator, (const std::string& file), (const, override));
        MOCK_METHOD(TrackPtr, createTrack, (const std::filesystem::path& path), (const, override));
        MOCK_METHOD(AnalyzerPtr, createAnalyzer, (const ITrack& track), (const, override));
        MOCK_METHOD(PrinterPtr, createVerbosePrinter, (const std::vector<Result> &results, const BPMRange& bpmRange),
                    (const, override));
        MOCK_METHOD(PrinterPtr, createPrinter, (const std::vector<Result> &result, const BPMRange& bpmRange),
                    (const, override));
    };

}  // namespace bpmf::core
