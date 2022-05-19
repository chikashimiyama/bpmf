#pragma once

#include <gmock/gmock.h>

#include <bpmfcore/IAnalyzer.h>

namespace bpmf::core
{
    class AnalyzerMock : public IAnalyzer
    {
        public:

        ~AnalyzerMock() = default;

        MOCK_METHOD(const std::optional<double>&, getBPM, (), (override));
    };

}  // namespace bpmf::core

