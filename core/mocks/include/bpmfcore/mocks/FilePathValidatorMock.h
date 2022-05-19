#pragma once

#include <gmock/gmock.h>

#include <bpmfcore/IFilePathValidator.h>

namespace bpmf::core
{
    class FilePathValidatorMock : public IFilePathValidator
    {
        public:
        ~FilePathValidatorMock() = default;

        MOCK_METHOD(std::optional<std::filesystem::path>, getFilePath, (), (const, override));
    };

}  // namespace bpmf::core

