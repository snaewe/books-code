# Compiliert alle .cpp-Dateien im aktuellen Verzeichnis, und zwar
# jede für sich, d.h. jede Datei muß eine main-Funktion enthalten

include ../../make/mf_alle
ifeq "$(findstring Windows,$(OS))" "Windows"
CXXFLAGS+= -DWIN32
endif

