# Compiliert und linkt alle .cpp-Dateien im aktuellen Verzeichnis als Projekt,
# d.h. es gibt danach EIN ausführbares Programm, so dass es nur exakt EIN 
# main-Programm im Verzeichnis geben darf

include ../../make/makeProject
INCLUDE+=-I$(BOOSTINCLUDE)
LDFLAGS+=-L$(BOOSTLIBDIR) -l$(BOOSTTESTLIB)
EXE:=testdatum.exe

