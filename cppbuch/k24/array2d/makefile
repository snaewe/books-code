# GNU C++ wird als Compiler angenommen
# -fno-elide-constructors sorgt dafür, dass Kopierkonstruktor-
# aufrufe nicht wegoptimiert werden (um sie hier protokollieren zu können)
CXX := g++
INCLUDE := -I../../include
CXXFLAGS := -g -Wall -c -std=c++0x -fno-elide-constructors
LDFLAGS := -g 
EXE := projekt.exe

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

