#include <iostream>

#include "Track.h"
#include "Analyzer.h"
#include <bpmfcore/Utils.h>

int main(int argc, char** argv)
{
    auto path = std::filesystem::path(argv[1]);
    auto track = bpmf::Track(path);
    auto audio = track.getAudio();
    auto analyzer = bpmf::Analyzer(audio.sampleRate, audio.samples);

    if(analyzer.getBPM().has_value())
      std::cout << analyzer.getBPM().value()<< std::endl;
    return 0;
}