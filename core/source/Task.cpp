#include "Task.h"

namespace bpmf::core
{
    Task::Task(const std::string& file,  const IFactory& factory)
    : file_(file)
    , factory_(factory)
    {
    }

    Result Task::execute() const
    {
        const auto filePathValidator = factory_.createFilePathValidator(file_);
        const auto filePath = filePathValidator->getFilePath();
        if(!filePath.has_value())
            return {file_, std::nullopt, std::nullopt };

        const auto track = factory_.createTrack(filePath.value());
        const auto analyzer = factory_.createAnalyzer(*track);
        const auto bpm = analyzer->getBPM();

        return { file_, std::filesystem::absolute(filePath.value()), bpm };
    }
}


