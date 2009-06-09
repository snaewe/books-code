
all:
	@echo make g++, make intel oder make vc aufrufen!

g++:
	g++ -c *.cpp
	g++ -o main.exe *.o
	ls -al *.o
	ls -al main.exe

intel:
	icpc -c *.cpp
	icpc -o main.exe *.o
	ls -al *.o
	ls -al main.exe

clean:
	rm -f *.exe
	rm -f *.o

