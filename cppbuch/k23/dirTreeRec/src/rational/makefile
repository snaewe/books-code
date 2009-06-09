objs := rational.o
all: $(objs)
%.o : %.cpp
	@echo compiling  $<  .......
	-$(CXX) $(CXXFLAGS) $< -o $@
clean:
	rm -f $(objs)
