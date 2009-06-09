
CXX := g++
INCLUDE := -I.
CXXFLAGS := -g -Wall -c -std=c++0x
LDFLAGS := -g 
EXE := formatcode.exe

OBJS := $(patsubst %.cpp,%.o,$(wildcard *.cpp))
HEADERS := $(wildcard *.h)
TEMPLATES := $(wildcard *.t)
.PHONY: clean

$(EXE): $(OBJS)
	-$(CXX) -o $(EXE) $(OBJS) $(LDFLAGS)

$(OBJS): %.o : %.cpp  $(HEADERS) $(TEMPLATES)
	-$(CXX) $(CXXFLAGS) $(INCLUDE) $< -o $@

clean:
	rm -f $(OBJS) $(EXE)

