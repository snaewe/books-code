.PHONY: clean

CXX:= g++
CXXFLAGS := -c -g -Wall
objs := rational.o main.o

projekt.exe: $(objs)
	@echo 1  $^
	@echo 2  $@
	@echo 3  $<
	$(CXX) -o $@ $^

# geht auch ohne diese Regel (erkennt make automatisch,
# %.h wäre fehlerhaft, weil kein main.h existiert,
# und würde zur impliziten Regel führen
%.o: %.cpp rational.h
	$(CXX) $(CXXFLAGS) $<

clean:
	rm -f $(objs)

