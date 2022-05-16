#include <vector>
#include <filesystem>

namespace bpmf::core
{
    struct Configuration
    {
        const bool validity { false };
        const bool verbose { false };
        const size_t numThreads { 4 };
        const size_t minBPM { 40 };
        const size_t maxBPM { 200 };
        const std::filesystem::path applicationPath;
        const std::vector<std::filesystem::path> paths;
    };

    Configuration parse(int argc, const char** argv);
}
