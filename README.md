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
> cmake -DCMAKE_C_COMPILER=gcc-9 -DCMAKE_CXX_COMPILER=g++-9 ..  
> cmake --build .  

then you should be able to find bpmf binary in the build directory.  
Note: we need to use gcc-9 because gcc-8 has a  [bug in std::filesytem](https://gcc.gnu.org/bugzilla/show_bug.cgi?id=90050) 

## Test the functionality with audio samples
in the build folder

> ./bpmf -v 120 140 ../audiosamples/*.mp3

you will see in the terminal estimated BPM of each mp3 files and whether the files meet the criteria (BPM between 120 and 140)

## How to use bpmf in the real world context

If you want to copy all mp3 files whose BPM is between 120 140 to extract directory.
you can combine bpmf with find and xarg.

> mkdir extract && find ~/ -name *.mp3  -printf '"%p" ' | xargs ./bpmf 120 140 | xargs -n 1 -I % cp % extract

this command make extract folder, find all mp3 files under your home directory filter them with bpmf and copy it to extract directory

## Program options

> ./bpmf -h

shows you the list of options

## Rubric Points

- The project demonstrates an understanding of C++ functions and control structures.
- The project reads data from a file and process the data, or the program writes data to a file.
- The project accepts user input and processes the input.
- The project uses Object Oriented Programming techniques.
- Classes use appropriate access specifiers for class members.
- Class constructors utilize member initialization lists.
- Classes abstract implementation details from their interfaces.
- Classes encapsulate behavior.
- Derived class functions override virtual base class functions.
- The project makes use of references in function declarations.
- The project uses move semantics to move data, instead of copying it, where possible.
- The project uses smart pointers instead of raw pointers.
- The project uses multithreading.
- A mutex or lock is used in the project.

## Dependencies

- libboost-program-options-dev for parsing command line options
- gtest (submodule) for unit tests
- minibpm (submodule) for loading mp3 files

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

