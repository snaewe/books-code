##CXX :=/usr/local/gcc44/bin/g++
CXX := g++
CXXFLAGS := -g -Wall -c -std=c++0x

####   ANPASSEN:    ####
# diese Variablen werden in manchen Makefiles, die dieses Makefile 
# einschliessen,  benoetigt 
BOOSTINCLUDE=/usr/local/include/boost-1_38
BOOSTLIBDIR=/usr/local/lib
BOOSTVARIANTE=-gcc43-mt-1_38
####  Ende Anpassungsbereich             ####

CPPBUCHINCLUDE=$(CPPBUCH_HOME)/include
BOOSTREGEXLIB=boost_regex$(BOOSTVARIANTE)
BOOSTFSLIB=boost_filesystem$(BOOSTVARIANTE)
BOOSTSYSTEMLIB=boost_system$(BOOSTVARIANTE)
BOOSTTHREADLIB=boost_thread$(BOOSTVARIANTE)
BOOSTTESTLIB=boost_unit_test_framework$(BOOSTVARIANTE)
INCLUDE := -I$(CPPBUCHINCLUDE)  
LDFLAGS := -g 
