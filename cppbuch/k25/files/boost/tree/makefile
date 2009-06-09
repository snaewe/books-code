# Compiliert alle .cpp-Dateien im aktuellen Verzeichnis, und zwar
# jede für sich, d.h. jede Datei muß eine main-Funktion enthalten

include ../../../../make/makeProject
INCLUDE+=-I$(BOOSTINCLUDE)
LDFLAGS+=-L$(BOOSTLIBDIR) -l$(BOOSTFSLIB) -l$(BOOSTSYSTEMLIB)
EXE := tree.exe

