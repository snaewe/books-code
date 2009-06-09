all:
# Windows
ifeq "$(findstring Windows,$(OS))" "Windows"
	g++ -o ihost.exe ihost.cpp -lwsock32
else
# Unix/Linux oder sonstwas
	g++ -o ihost.exe ihost.cpp
endif

clean:
	$(RM) ihost.exe
