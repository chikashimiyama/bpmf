# bpmf (Udacity C++ Capstone project)
bpmf is a command line tool that checks the BPM (Beat Per Minutes / the tempo of the song) of multiple mp3 audio files and filter the files whose BPM is outside the range of BPM the user specifies.


## Motivation
If you have a large collection of mp3 files (e.g. 10000 songs!) and you want to select only the files whose BPM are between 90 and 100, you may have to listen to each song and check the bpm by ears and fill an excel sheet. This is obviously a pain. This program checks the BPM of all your mp3 files and tells you if it is between 90 and 100 so that you can easily prepare a playlist for your next dance party!

## Dependency
- minimp3 ... mp3 loader

## Usage

bpmfil [OPTION]... MIN MAX [FILES]...

MIN ... minimal bpm e.g. 60
MAX ... maxmimal bpm e.g. 120
FILES ... files to be evaluated
-t ... number of threads to be used
-v ... verbose mode
