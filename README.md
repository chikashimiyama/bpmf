# bpmf (Udacity C++ Capstone project)
bpmf is a command line tool that checks the BPM (Beat Per Minutes / the tempo of the song) of multiple mp3 audio files and filter out the files whose BPM is outside the range of BPM the user specifies.

## Motivation
It will be a very cumbersome work if you want to select only the tracks whose tempo (i.e. BPM) is between 125 and 140 from your large collection of mp3 files.  
This tool analyzes the audio data in mp3 files and detect the tempo and filters only the tracks whose BPM is within the range you specify. In other words, this tool helps you to create a playlist for your next dance party!

## Dependencies
- libboost-program-options-dev for parsing command line options
- gtest (submodule) for unit tests
- minibpm for loading mp3 files

> sudo apt-get install libboost-program-options-dev

## Warning
The project has to be compiled with gcc-9 or later because
gcc-8 has a [bug in std::filesytem](https://gcc.gnu.org/bugzilla/show_bug.cgi?id=90050).  
To force cmake to use gcc 9, execute cmake command with the following option.

> cmake -DCMAKE_C_COMPILER=gcc-9 -DCMAKE_CXX_COMPILER=g++-9

## Test Environment
This project is tested on Ubuntu 20.04 LTS

## Usage

> bpmf --help

## File Structure

- bpmf 
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

