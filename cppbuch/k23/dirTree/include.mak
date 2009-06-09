CXX := g++
CXXFLAGS := -g -Wall -c
INCLUDE := -I.
LDFLAGS := -g 
OBJDIR := obj
BINDIR := bin
DISTDIR := dist
EXEFILE := projekt.exe

objects := $(subst $(SRCDIR), $(OBJDIR), $(cppfiles:.cpp=.o))
deps := $(objects:.o=.d)

.PHONY: all clean dist


all: $(BINDIR)/$(EXEFILE)

-include $(deps)

$(OBJDIR)/%.d: $(SRCDIR)/%.cpp 
	mkdir -p $(@D)
	$(CXX) -MM -MT "$@ $(patsubst %.d,%.o,$@)" -MF $@ $<

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp 
	@echo compiling  $< ...
	$(CXX) $(CXXFLAGS) $(INCLUDE) $< -o $@

$(BINDIR)/$(EXEFILE): $(objects)
	mkdir -p $(BINDIR)
	$(CXX) -o $@ $^ $(LDFLAGS)

$(DISTDIR)/gezippt.zip: $(BINDIR)/$(EXEFILE)
	mkdir -p $(DISTDIR)
	zip $(DISTDIR)/gezippt.zip $(BINDIR)/$(EXEFILE)

dist: $(DISTDIR)/gezippt.zip

clean:
	$(RM) -r -f $(OBJDIR)

ultraclean:
	$(RM) -r -f $(OBJDIR)
	$(RM) -r -f $(DISTDIR)
	$(RM) -r -f $(BINDIR)



