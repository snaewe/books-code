

Konventionen:

Der Verzeichnisname gibt das Kapitel an. Zum Beispiel enthält das
Verzeichnis "cppbuch/k5 die Beispiele aus Kapitel 5.

In jedem Verzeichnis, das makefile enthält, kann die Übersetzung
durch den Aufruf
 make
angestoßen werden.
 make clean
löscht alle erzeugten Dateien.

makemakefile erzeugt ein makefile für die Compilation *sämtlicher*
Beispiele. 

ACHTUNG: In den Dateien cppbuch/make/mf_alle,
cppbuch/make/makeProject und cppbuch/make/include.mak müssen die
Verzeichnisnamen Ihrem System entsprechend angepasst werden!

Anschließend mögliche Aufrufe:

      make
        übersetzt sämtliche Beispiele. Wenn Sie einen Multikern-
        prozessor haben, können Sie zum Beispiel
        make -j2 oder make -j4 für einen Dual- bzw. Quadcore-
        Rechner aufrufen, um den Vorgang zu bescchleunigen.

      make clean
        löscht sämtliche bei der Übersetzung erzeugte Dateien,
        soweit (noch) vorhanden

      make  2> error.log
        übersetzt sämtliche Beispiele und sammelt die Fehlermeldungen
        in der Datei error.log

      make > compile.log 2>&1
        übersetzt sämtliche Beispiele und sammelt alle Ausgaben
        einschließlich der Fehlermeldungen in der Datei compile.log

Erläuterungen zu makemakefile finden Sie im Abschnitt
"Makefile für rekursive Aufrufe erzeugen" des Buchs.

######## EINSCHRÄNKUNGEN BEI DER ÜBERSETZUNG! ############

Damit Sie sich nicht wundern, falls nicht alles übersetzt wird:
Die Beispiele sind alle mit dem GNU C++-Compiler 4.3 übersetzbar,
mit folgenden Ausnahmen/Einschränkungen:

1. Die Beispiele in den Verzeichnissen 
   k27/tuple
   k9/sharedptr
   k24/vermischtes
   k24/array2dmath/performancetest/array2d
   k24/array2dmath
   k33/uniqueptr
   setzen mindestens den GNU C++Compiler Version 4.4 voraus.
   (zur Zeit des Erscheinens des Buch nur für Linux erhältlich)
   Den richtigen Pfad zu dem Compiler bitte in der Datei
   make/mf_alle44
   korrigieren.

2. Das Beispiel mit static_assert DARF nicht übersetzbar sein 
   (siehe Text dazu).

3. Der Performance-Vergleich im Verzeichnis
   k24/array2dmath/performancetest
   setzt sowohl GNU C++ Version 4.4 als auch die Blitz-Bibliothek voraus. 
   Bitte beachten Sie dazu die Installationshinweise.
   
   Bei der Standardinstallation mit install.exe von der Buch-DVD
   wird die Blitz-Bibliothek automatisch mit installiert. Damit 
   sind die Beispiele in k24/array2dmath/performancetest
   uebersetzbar, einschliesslich
   k24/array2dmath/performancetest/array2d, falls G++ 4.4 installiert ist.





