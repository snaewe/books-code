.PHONY: clean

CXX := g++
CXXFLAGS := -c -g -Wall
LIBPROJEKT := ../libprojekt
LIBDIR := $(LIBPROJEKT)/lib
LDFLAGS := -g -static -L$(LIBDIR) -lrational

projekt.exe: main.o
	$(MAKE) -C  $(LIBPROJEKT)
	$(CXX) -o projekt.exe main.o $(LDFLAGS)

main.o: main.cpp  rational.h
	$(CXX) $(CXXFLAGS) main.cpp

clean:
	rm -f projekt.exe main.o

