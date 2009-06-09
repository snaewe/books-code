
include ../../../make/makeProject
INCLUDE+=-I$(BOOSTINCLUDE)
LDFLAGS+=-L$(BOOSTLIBDIR) -l$(BOOSTSYSTEMLIB)  -l$(BOOSTFSLIB) -l$(BOOSTTHREADLIB)
ifeq "$(findstring Windows,$(OS))" "Windows"
LDFLAGS+=-lWs2_32
endif
EXE=server.exe


