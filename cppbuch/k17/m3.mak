.PHONY: all clean

CXX := g++
CXXFLAGS := -c -g -Wall
LDFLAGS := -g
objs := $(patsubst %.cpp,%.o,$(wildcard *.cpp))
HEADERS := $(wildcard *.h)

all: projekt.exe

projekt.exe: $(objs) 
	$(CXX) $(LDFLAGS) -o $@ $^

%.o: %.cpp $(HEADERS)   # (noch) nicht optimal, s. Buch
	$(CXX) $(CXXFLAGS) $<

clean:
	rm -f $(objs)

