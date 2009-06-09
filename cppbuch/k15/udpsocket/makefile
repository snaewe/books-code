# Compiliert alle .cpp-Dateien im aktuellen Verzeichnis, und zwar
# jede für sich, d.h. jede Datei muß eine main-Funktion enthalten

include ../../make/mf_alle
INCLUDE+=-I$(BOOSTINCLUDE)
LDFLAGS+=-L$(BOOSTLIBDIR) -l$(BOOSTSYSTEMLIB)
ifeq "$(findstring Windows,$(OS))" "Windows"
LDFLAGS+=-lWs2_32
endif


