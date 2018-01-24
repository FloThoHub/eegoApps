Sampling reate = 512. Options for changing sampling rate will be added in the future.


Requirements:

To run the executable it is neccesary to:

- install Qt 5.8 (https://download.qt.io/development_releases/qt/5.8/5.8.0-rc/)
  qt-opensource-windows-x86-winrt-msvc2015-5.8.0-rc_699.exe is recommended, since I had issues with the other ones.
	
- set an environmental variable 
  QT_QPA_PLATFORM_PLUGIN_PATH 
  with the value(path where your platforms folder is), like this:
  "D:\Qt\5.8\winrt_x64_msvc2015\plugins\platforms"

- in some Qt-versions the qwindows.dll and the qwindowsd.dll files are missing in the platforms folder,
  just copy them from eegoApps\ALLinONEapp\qt_dll_files them into ...\plugins\platforms and it should work.


Electrode Positions/Caps:

if you are adding new caps, make sure that the 2D coordinates in the text file have the following form:

Fp1:	82.7	29.37
Fpz:	95	-0.1
Fp2:	82.7	-29.47
F7:	53.6	84.04
F3:	39.1	43.78
Fz:	35.5	-0.1
F4:	39.8	-43.88
F8:	53.8	-84.14
FC5:	16.1	77.33
FC1:	9.9	25.08
FC2:	10.5	-25.18
FC6:	16.8	-77.43
M1:	-50.6	134.86
T7:	-13.2	108.68
	.
	.
	.

make sure that there are only blanks between the coordinates.

Fp1  :	82.7	29.37 this would be not okay!
Fp1     	82.7  29.37 <-- okay
