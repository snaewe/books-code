VORAUSSETZUNGEN

Boost muss installiert sein.

Blitz muss installiert sein. Dazu bitte blitz/README.txt
lesen.

Alternative: Installation von der CDROM, siehe Verzeichnis
linux/blitz, Datei installieren.txt


array2d/add.cpp und array2d/mult.cpp benötigen mindestens G++ 4.4. G++
4.3 reicht nicht.

Aus diesem Grund rufen die makefiles die entsprechenden makefiles im
Verzeichnis cppbuch/make auf. Die Makefiles in cppbuch/make sind Ihrem
System entsprechend anzupassen, sofern Sie nicht die
Standardinstallation vorgenommen haben.

make
übersetzt die Programme.

make runadd
startet die Matrix-Addition

make runmult
startet die Matrix-Multiplikation

Je nach System können die Ergebnisse einige Minuten auf sich
warten lassen.


