# FilterWithBPM (Udacity C++ Capstone project)
bpmfilter is a command line tool that checks the BPM (Beat Per Minutes / the tempo of the song) of multiple mp3 audio files and filter the files whose BPM is outside the range of BPM the user specifies.


# Motivation
If you have a large collection of mp3 files (10000 songs!) and you want to select only the files whose BPM is between 90 and 100, it is usually hard because MP3 file do not offer such a metadata. This program checks the BPM and tells you if it is between 90 and 100 so that you can easily prepare a playlist for your next dance party!

# Dependency
- minimp3 ... mp3 loader

# Usage

bpmfil [OPTION]... MIN MAX [FILES]...

MIN ... minimal bpm e.g. 60
MAX ... maxmimal bpm e.g. 120
FILES ... files to be evaluated
-t ... number of threads to be used
-v ... verbose mode
