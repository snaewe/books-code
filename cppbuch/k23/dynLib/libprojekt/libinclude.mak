CXX := g++
CXXFLAGS := -g -Wall -c
INCLUDE := -I.
LDFLAGS := -g 
OBJDIR := obj

ifeq "$(findstring Windows,$(OS))" "Windows"
DYNLIB := lib/librational.dll
else # Unix/Linux
DYNLIB := lib/librational.so
endif


objects := $(subst $(SRCDIR), $(OBJDIR), $(cppfiles:.cpp=.o))
deps := $(objects:.o=.d)

.PHONY: all clean dist

all: $(DYNLIB)

-include $(deps)

$(OBJDIR)/%.d: $(SRCDIR)/%.cpp 
	mkdir -p $(@D)
	$(CXX) -MM -MG -MT "$@ $(patsubst %.d,%.o,$@)" -MF $@ $<

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp 
	$(CXX) $(CXXFLAGS) $(INCLUDE) $< -o $@

$(DYNLIB): $(objects)
	mkdir -p $(@D)
	$(CXX) -shared -o $(DYNLIB) $(objects)

clean:
	rm -r -f $(OBJDIR)
	rm -r -f $(DYNLIB)
