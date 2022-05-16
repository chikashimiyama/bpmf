#include "Parser.h"
#include <algorithm>
#include <string>
#include <vector>

namespace bpmf::core
{
    namespace
    {
        bool findVerbose(std::vector<std::string>& arguments)
        {
            const auto itr = std::find(arguments.cbegin(), arguments.cend(), "-v");
            const auto found = itr != arguments.cend();
            if(found)
                arguments.erase(itr);
            return found;
        }

        std::optional<size_t> findThreadCount(std::vector<std::string>& arguments)
        {
            const auto itr = std::find(arguments.cbegin(), arguments.cend(), "-t");
            if (itr == arguments.cend())
                return std::nullopt;
            if (std::distance(arguments.cbegin(), itr) == arguments.size())
                throw std::invalid_argument("-t requires number of threads after that");

            auto thread = std::stoi(*(itr+1));
            if (thread <= 0)
                throw std::invalid_argument("the number of requested threads should be greater than 0");

            arguments.erase(itr, itr+1);
            return thread;
        }
    }

    Configuration parse(int argc, const char** argv)
    {
        auto arguments = std::vector<std::string>();
        for(auto i = 0; i < argc; i++)
            arguments.emplace_back(std::string(argv[i]));

        auto applicationPath = std::filesystem::path(arguments[0]);
        arguments.erase(arguments.begin());
        auto verbose = findVerbose(arguments);
        auto threadCount = findThreadCount(arguments);

        if(argc <= 3)
            return Configuration{};

        const auto minBPM = std::stoi(arguments[0]);
        const auto maxBPM = std::stoi(arguments[1]);

        auto files = std::vector<std::filesystem::path>();
        std::for_each(arguments.cbegin()+2, arguments.cend(), [&files](const std::string& arg){
            files.emplace_back(std::filesystem::path(arg));
        });

        return Configuration{ true,
                              verbose,
                              threadCount.has_value() ? threadCount.value() : 4,
                              static_cast<size_t>(minBPM),
                              static_cast<size_t>(maxBPM),
                              applicationPath,
                              files
                             };
    }
}