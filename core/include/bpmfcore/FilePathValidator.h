#include "IFilePathValidator.h"

namespace bpmf::core
{
    class FilePathValidator : public IFilePathValidator
    {
    public:
        FilePathValidator(const std::string& file);

        std::optional<std::filesystem::path> getFilePath() const override;

    private:
        std::optional<std::filesystem::path> validatedFilePath_;
    };
}