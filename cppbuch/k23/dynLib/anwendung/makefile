.PHONY: run zeigeLibs clean

CXX := g++
CXXFLAGS := -c -g -Wall
LIBPROJEKT := ../libprojekt
LIBDIR := $(LIBPROJEKT)/lib
LDFLAGS := -g -L$(LIBDIR) -lrational
EXE := projekt.exe

$(EXE): main.o
	$(MAKE) -C  $(LIBPROJEKT)
	$(CXX) -o $(EXE) main.o $(LDFLAGS)

main.o: main.cpp  rational.h
	$(CXX) $(CXXFLAGS) main.cpp

zeigeLibs: $(EXE)
	ldd $(EXE)

run: $(EXE)
ifeq "$(findstring Windows,$(OS))" "Windows"
ifeq "$(findstring $(subst /,\,$(LIBDIR)),$(PATH))" ""
	@echo Keine Ausführung! $(LIBDIR) muss im Pfad liegen!
else
	$(EXE)
endif
else 
# Unix/Linux
	export LD_LIBRARY_PATH=$(LIBDIR);./$(EXE)
endif

clean:
	rm -f $(EXE) main.o

