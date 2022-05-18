#include "Main.h"

#include <mutex>
#include <thread>
#include <vector>
#include <queue>
#include <boost/program_options.hpp>

#include "Task.h"

namespace bpmf::core
{
        std::optional<Configuration> parse(int argc, const char* const* argv, std::string& instruction)
    {
        using namespace boost::program_options;

        auto optionsDescription = options_description("Arguments");
        optionsDescription.add_options()
                ("help,h", "produce help message")
                ("verbose,v", "verbose mode")
                ("threads,t", value<int>()->default_value(4), "number of threads")
                ("range", value<std::vector<int>>(), "BPM range")
                ("input-file", value<std::vector<std::string>>(), "input file. must be mp3 files");

        auto ss = std::stringstream();
        ss << optionsDescription;
        instruction = ss.str();

        auto positionalOptionDescription = positional_options_description();
        positionalOptionDescription.add("range", 2);
        positionalOptionDescription.add("input-file", -1);

        auto variablesMap = variables_map();

        try
        {
            store(command_line_parser(argc, argv)
            .options(optionsDescription)
            .positional(positionalOptionDescription).run(), variablesMap);
            notify(variablesMap);
        }
        catch(boost::program_options::invalid_option_value& )
        {
            return std::nullopt;
        }

        if(variablesMap.count("help"))
            return std::nullopt;
        if(!variablesMap.count("range"))
            return std::nullopt;
        if(!variablesMap.count("input-file"))
            return std::nullopt;

        const auto range = variablesMap["range"].as<std::vector<int>>();
        if(range.size() != 2)
            return std::nullopt;

        auto paths = variablesMap["input-file"].as<std::vector<std::string>>();
        const auto verbose = variablesMap.count("verbose") > 0;

        return core::Configuration{
            verbose,
            {static_cast<size_t>(range[0]), static_cast<size_t>(range[1])},
            std::queue<std::string>(std::deque<std::string>(paths.cbegin(), paths.cend()))
        };
    }

    std::vector<Result> process(const Configuration& configuration, const IFactory &factory)
    {
        auto mtx = std::mutex();
        const auto numThreads = std::thread::hardware_concurrency();

        auto filesToBeEvaluated = configuration.paths;
        auto threads = std::vector<std::thread>();
        auto results = std::vector<Result>();

        for(auto i = 0; i < numThreads; ++i)
        {
            threads.emplace_back(std::thread([&](){
                while(true)
                {
                    auto path = std::string();
                    {
                        const auto lock = std::lock_guard<std::mutex>(mtx);
                        if (filesToBeEvaluated.empty())
                            return;
                        path = filesToBeEvaluated.front();
                        filesToBeEvaluated.pop();
                    }

                    const auto task = Task(path, factory);
                    auto result = task.execute();

                    {
                        const auto lock = std::lock_guard<std::mutex>(mtx);
                        results.emplace_back(result);
                    }
                }
            }));
        }

        for(auto& thread : threads)
            thread.join();

        return results;
    }

    std::string print(const Configuration& configuration,
                      const std::vector<Result>& results, const IFactory& factory)
    {
        const auto printer = configuration.verbose ? factory.createVerbosePrinter(results, configuration.bpmRange)
                                                   : factory.createPrinter(results, configuration.bpmRange);
        return printer->print();
    }
}