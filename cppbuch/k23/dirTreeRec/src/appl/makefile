
objs := main.o ../rational/rational.o
exe := ../../bin/projekt.exe

all: $(exe)

%.o : %.cpp
	@echo compiling  $<  .......
	-$(CXX) $(CXXFLAGS) $< -o $@

$(exe): $(objs)
	mkdir -p $(@D)
	@echo linking $^
	$(CXX) -o $@ $(objs) $(LDFLAGS)

clean:
	$(RM) $(objs)
