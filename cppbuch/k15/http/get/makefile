
include ../../../make/makeProject
INCLUDE+=-I$(BOOSTINCLUDE)
LDFLAGS+=-L$(BOOSTLIBDIR) -l$(BOOSTSYSTEMLIB) 
ifeq "$(findstring Windows,$(OS))" "Windows"
LDFLAGS+=-lWs2_32
endif
EXE=get.exe


