#include "FilePathValidator.h"

namespace bpmf::core
{
    using namespace std::filesystem;

    FilePathValidator::FilePathValidator(const std::string &file)
    {
        auto filePath = path(file);
        if(!exists(filePath))
        {
            validatedFilePath_ = std::nullopt;
            return;
        }

        if(!is_regular_file(filePath))
        {
            validatedFilePath_ = std::nullopt;
            return;
        }

        validatedFilePath_ = filePath;
    }


    std::optional<std::filesystem::path> FilePathValidator::getFilePath() const
    {
        return validatedFilePath_;
    }
}