
GEOS cross-development files
TASM version

by Maciej 'YTM/Alliance' Witkowiak
24.06.1999



INTRO
You need registered version of TASM to use included files! It may be obtained from:
http://taboo.eu.org
It would be great if one could find a GNU 6502 crossassembler with similar capabilities.



INFO
In this directory you can find include files which will allow you to cross-compile almost any GEOS executable. There are also few example files written by me.

Note that GEOS has a bit different filesystem than DOS and you can't use the raw data output from assembler. GEOS needs header for each executable. I have prepared an example header that may be used for any GEOS executable file. The assembler output from a source file with header will be in standard Convert (*.cvt) format. You can transfer the file to the C64 and use Convert under GEOS or convert the file on the fly by simply copying a *.cvt file to a 1541 disk (physical or virtual) with Star Commander.



INCLUDE FILES
(do not include them in your source - header will do it)
Description is here to let you know where to search symbols.

CONST.INC	- contains all known constant values, extracted from geosSym
DISKDRV.INC	- disk driver jump and vector table (do not use vectors, Kernal does)
GEOSMAC.INC	- all macros from geosMac and few more, check it out
GEOSSYM.INC	- memory locations and areas for GEOS
GEOSSYM2.INC	- few locations defined in Kernal code
INPUTDRV.INC	- jump table for input drivers
JUMPTAB.INC	- Kernal jump table
PRINTDRV.INC	- printer driver jump table



TEMPLATES

SAMPLE.TAS	- simplest GEOS app
TEMPLATE.TAS	- this is the file of your interest - you will need to copy this with other name and edit for each GEOS executable to be created



EXAMPLES

Examples are located in \examples subdirectory (preety wise, eh?). Each source code has a header file with very similar name.



CREATING GEOS APPLICATION

Let's say that you are going to write a GEOS app on your PC. You need to write the source code. Save it as e.g. GEOSAP.TAS.
Then you need to make a header file for it. You have to copy TEMPLATE.TAS to e.g. GEOSAPHD.TAS and edit it. Check in the source what you can and what you can't edit. Remember that some strings (filenames etc.) have fixed length and it can not be bigger than I wrote in comments. Also remember to enter proper source code file name at the end of the header file.

Then you need to assemble the whole thing. Include files, source and the header have to be in the same directory (or in path). From DOS prompt you type:
TASM GEOSAPHD.TAS
(NOTE! You assemble _only_ header file.)
and if there were no errors you may rename output file (GEOSAPHD.O64) to real output name (GEOSAP.CVT) and move the file to a 1541 disk for use under GEOS.

Check examples, everything is shown there.



AUTHOR
Reverse engineer one could say :) But examples in /examples directory are written by me.

Maciej 'YTM/Alliance' Witkowiak
ytm@friko.onet.pl
