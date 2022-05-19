# bpmf (Udacity C++ Capstone project)
bpmf is a command line tool that checks the BPM (Beat Per Minutes / the tempo of the song) of multiple mp3 audio files and filter out the files whose BPM is outside the range of BPM the user specifies.

## Motivation
It will be a very cumbersome work if you want to select only the tracks whose tempo (i.e. BPM) is between 125 and 140 from your large collection of mp3 files.  
This tool analyzes the audio data in mp3 files and detect the tempo and filters only the tracks whose BPM is within the range you specify. In other words, this tool helps you to create a playlist for your next dance party!

## Building (Tested on Ubuntu 20.04 LTS)

> sudo apt-get install libboost-program-options-dev  
> git clone --recurse-submodules (repo)  
> cd bpmf  
> mkdir build  
> cd build   
> cmake .. -DCMAKE_C_COMPILER=gcc-9 -DCMAKE_CXX_COMPILER=g++-9   
> cmake --build .  

then you should be able to find bpmf binary in the build directory.  
Note: we need to use gcc-9 because gcc-8 has a  [bug in std::filesytem](https://gcc.gnu.org/bugzilla/show_bug.cgi?id=90050) 

## Test the functionality with audio samples
audiosamples directory contains three mp3 files that contains the same drumloops with three different BPMs.
You can check the functionality of the program using those files.

To do this, in the build folder

> ./bpmf -v 120 140 ../audiosamples/*.mp3

you will see in the terminal estimated BPM of each mp3 files and whether the files meet the criteria (BPM between 120 and 140)

    --------------------------
            Input: ../audiosamples/house_BPM160.mp3
    Abs file path: /home/chikashi/Development/bpmf/build/../audiosamples/house_BPM160.mp3
    Estimated BPM: 159
    --------------------------
            Input: ../audiosamples/house_BPM125.mp3
    Abs file path: /home/chikashi/Development/bpmf/build/../audiosamples/house_BPM125.mp3
    Estimated BPM: 125
    --------------------------
            Input: ../audiosamples/house_BPM90.mp3
    Abs file path: /home/chikashi/Development/bpmf/build/../audiosamples/house_BPM90.mp3
    Estimated BPM: 89
    --------------------------
    == list of files whose BPM=120~140==
    "/home/chikashi/Development/bpmf/build/../audiosamples/house_BPM125.mp3"


## How to use bpmf in the real world context

If you want to copy all mp3 files whose BPM is between 120 140 to extract directory.
you can combine bpmf with find and xarg.

> mkdir extract && find ~/ -name *.mp3  -printf '"%p" ' | xargs ./bpmf 120 140 | xargs -n 1 -I % cp % extract

this command make extract folder, find all mp3 files under your home directory filter them with bpmf and copy the filtered results to extract directory

## Program options

> ./bpmf -h

shows you the list of options

## Rubric Points

- The project demonstrates an understanding of C++ functions and control structures. (core/Main.cpp)
- The project reads data from a file and process the data, or the program writes data to a file. (Track.cpp)
- The project accepts user input and processes the input. (core/Main.cpp)
- The project uses Object Oriented Programming techniques. (Track.cpp, Analyzer.cpp, Printer.cpp)
- Classes use appropriate access specifiers for class members. (Track.cpp, Analyzer.cpp, Printer.cpp)
- Class constructors utilize member initialization lists. (Printer.cpp)
- Classes abstract implementation details from their interfaces. (Track.cpp, Analyzer.cpp, Printer.cpp)
- Classes encapsulate behavior. (Track.cpp, Analyzer.cpp, Printer.cpp)
- Derived class functions override virtual base class functions. (Track.h, Analyzer.h, VerbosePrinter.h, Printer.h)
- The project makes use of references in function declarations. (Printer.h)
- The project uses move semantics to move data, instead of copying it, where possible. (Factory.cpp)
- The project uses smart pointers instead of raw pointers. (Factory.cpp)
- The project uses multithreading. (Main.cpp)
- A mutex or lock is used in the project. (Main.cpp)

## Dependencies

- [libboost-program-options-dev](https://www.boost.org/doc/libs/1_58_0/doc/html/program_options.html) for parsing command line options
- [googletest](https://github.com/google/googletest) for unit tests
- [dr_libs](https://github.com/mackron/dr_libs) for loading mp3
- [minibpm](https://github.com/breakfastquay/minibpm) for analyzing BPM

## File Structure

- bpmf
  - audiosamples ... contains some mp3 file to use for the test
  - core ... the pure business logic of application, no external dependencies thus code coverage of the test cases reaches 100%
    - include ... header files
    - source ... source files
    - mocks ... mock of the classes to be used in the unit test
    - test ... unit test
      - source ... unit test cases
  - dependencies ... external libraries used in the project 
    - dr_lib (submodule) ... to load mp3 files onto memory
    - googletest (submodule) ... test framework used for the unit test in the core
    - minibpm (submodule) ... the core algorithm to analyze bpm 
    - boost ... used for program option parsing 
  - include ... header files of the application
  - source ... source files of the application

