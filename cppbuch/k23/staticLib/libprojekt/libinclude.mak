CXX := g++
CXXFLAGS := -g -Wall -c
INCLUDE := -I.
OBJDIR := obj
## neu 
LIB := lib/librational.a

objects := $(subst $(SRCDIR), $(OBJDIR), $(cppfiles:.cpp=.o))
deps := $(objects:.o=.d)

.PHONY: all clean dist

all: $(LIB)

-include $(deps)

$(OBJDIR)/%.d: $(SRCDIR)/%.cpp 
	mkdir -p $(@D)
	$(CXX) -MM -MG -MT "$@ $(patsubst %.d,%.o,$@)" -MF $@ $<

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp 
	$(CXX) $(CXXFLAGS) $(INCLUDE) $< -o $@

$(LIB): $(objects)
	mkdir -p $(@D)
	ar cru $(LIB) $(objects)

clean:
	rm -r -f $(OBJDIR)
	rm -r -f $(LIB)
