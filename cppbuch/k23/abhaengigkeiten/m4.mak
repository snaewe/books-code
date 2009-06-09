.PHONY: all clean

CXX := g++
CXXFLAGS := -c -g -Wall
LDFLAGS := -g
objs := $(patsubst %.cpp,%.o,$(wildcard *.cpp))
deps := $(objs:.o=.d)

all: projekt.exe

-include $(deps)

projekt.exe: $(objs) 
	$(CXX) $(LDFLAGS) -o $@ $^

%.d: %.cpp
	$(CXX) -MM -MT "$@ $(patsubst %.d,%.o,$@)" -MF $@ $< 

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $<

clean:
	rm -f $(objs) $(deps)
