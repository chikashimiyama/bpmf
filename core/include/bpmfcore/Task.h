#include <string>
#include <filesystem>

#include "IFactory.h"
#include "Result.h"

namespace bpmf::core
{
    class Task
    {
    public:

        Task(const std::string& file, const IFactory& factory);

        Result execute() const;

    private:
        std::string file_;
        const IFactory& factory_;
    };
}
