TARGET = CheckEvent 

OBJ = 

ROOTCFLAGS = $(shell root-config --cflags)
ROOTLIBS   = $(shell root-config --libs)
ROOTGLIBS = $(shell root-config --glibs)

CXXFLAGS   = $(ROOTCFLAGS) -Wall -fPIC
CXXLIBS    = $(ROOTLIBS)
CC = g++ -std=c++11

INCS = -I$(WCSIMDIR)/include
LIBS = -L$(WCSIMDIR)/build/src -lWCSimRoot
#LIBS = -L$(WCSIMDIR) -lWCSimRoot

all: $(TARGET)

#CheckEvent: CheckEvent.o # $(OBJ)
#	$(CC) $(CXXFLAGS) -o $@ $^ $(CXXLIBS) $(LIBS)

.cc:
	$(CC) $(CXXFLAGS) -o $@ $^ $(CXXLIBS) $(LIBS) $(INCS)

#.cc.o:
#	$(CC) $(CXXFLAGS) $(INCS) -c $<

# clean
clean:
	rm -f $(TARGET) *.o *~ figures/* log.log
