#pragma once

#include <memory>
#include <optional>
#include <filesystem>

namespace bpmf::core
{
    class IFilePathValidator
    {
    public:
        virtual ~IFilePathValidator() = default;

        virtual std::optional<std::filesystem::path> getFilePath() const = 0;
    };

    using FilePathValidatorPtr = std::unique_ptr<IFilePathValidator>;
}
