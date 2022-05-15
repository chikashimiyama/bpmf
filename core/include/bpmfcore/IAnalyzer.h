#pragma once
#include <optional>
#include <memory>

namespace bpmf::core
{
    class IAnalyzer
    {
    public:
        virtual ~IAnalyzer() = default;

        virtual const std::optional<double>& getBPM() = 0;
    };

    using AnalyzerPtr = std::unique_ptr<IAnalyzer>;
}
