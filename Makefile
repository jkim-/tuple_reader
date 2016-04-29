CXX ?= g++
CXXFLAGS = -Wall -std=c++11
CXXFLAGS += -fPIC

# Postgre 
INCFLAGS = -I/usr/pgsql-9.4/include
LDFLAGS += -L/usr/pgsql-9.4/lib -lpq

# CERN ROOT
INCFLAGS += -I$(shell root-config --incdir)
LDFLAGS += $(shell root-config --libs)

LDFLAGS += -shared
CXXFLAGS += $(INCFLAGS)

# Target rules
SOURCES = TupleReader.cc
OBJS = $(patsubst %.cc, %.o, $(SOURCES))
LIBS = libTupleReader.so

.PHONY: all clean

all : CXXFLAGS += -O3
all : $(LIBS)

$(LIBS): $(OBJS)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $(OBJS) -o $@

clean:
	rm -f $(OBJS) $(LIBS) 
