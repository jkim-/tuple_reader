CXX ?= g++
CXXFLAGS = -Wall -std=c++11
CXXFLAGS += -fPIC

# Postgre 
INCFLAGS = -I/usr/pgsql-9.4/include
LDFLAGS += -L/usr/pgsql-9.4/lib -lpq

# CERN ROOT
INCFLAGS += -I$(shell root-config --incdir)
LDFLAGS += $(shell root-config --libs)

# TupleReader
TR_ROOT_PATH = ../
INCFLAGS += -I$(TR_ROOT_PATH)
LDFLAGS += -L$(TR_ROOT_PATH) -lTupleReader

CXXFLAGS += $(INCFLAGS)

SOURCES = test1.cc
OBJS = $(patsubst %.cc, %.o, $(SOURCES))
BINARIES = $(patsubst %.cc, %, $(SOURCES))

.PHONY: all clean

all : CXXFLAGS += -O3
all : $(BINARIES)

$(BINARIES): $(OBJS)
	$(CXX) $(CXXFLAGS) -Wl,-rpath,$(TR_ROOT_PATH) $(OBJS) -o $@ $(LDFLAGS)

clean:
	rm -f $(OBJS) $(BINARIES) 
