SRCDIR := src
verz := $(foreach dir,$(SRCDIR),$(wildcard $(dir)/*))
cppfiles := $(foreach dir,$(verz),$(wildcard $(dir)/*.cpp))

include include.mak
