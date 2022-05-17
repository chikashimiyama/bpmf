# bpmf (Udacity C++ Capstone project)
bpmf is a command line tool that checks the BPM (Beat Per Minutes / the tempo of the song) of multiple mp3 audio files and filter the files whose BPM is outside the range of BPM the user specifies.

sudo apt-get install libboost-program-options-dev

## Warning
The project has to be compiled with gcc-9 or later because
gcc-8 has a [bug in std::filesytem](https://gcc.gnu.org/bugzilla/show_bug.cgi?id=90050).  
To force cmake to use gcc 9, execute cmake command with the following option.

> cmake -DCMAKE_C_COMPILER=gcc-9 -DCMAKE_CXX_COMPILER=g++-9

## Motivation
If you have a large collection of mp3 files (e.g. 10000 songs!) and you want to select only the files whose BPM are between 90 and 100, you may have to listen to each song and check the bpm by ears and fill an excel sheet. This is obviously a cumbersome and time-consuming work. This program checks the BPM of all your mp3 files and tells you if it is between 90 and 100 so that you can easily prepare a playlist for your next dance party!

## Test
This project is tested on Ubuntu 20.04 LTS

## Dependencies
- minimp3 ... mp3 loader

## Usage

bpmfil [OPTION]... MIN MAX [FILES]...

MIN ... minimal bpm e.g. 60  
MAX ... maxmimal bpm e.g. 120  
FILES ... files to be evaluated  
-t ... number of threads to be used  
-v ... verbose mode  

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
    - googletest ... test framework used for the unit test in the core
    - minibpm ... the core algorithm to analyze bpm 
  - include ... header files of the application
  - source ... source files of the application

