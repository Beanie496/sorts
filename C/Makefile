SRC = binaryRadixSort.c binarySearchInsertionSort.c bogoSort.c bubbleSort.c \
	countingSort.c decimalRadixSort.c heapsort.c hexidecimalRadixSort.c main.c \
	mergeSort.c quicksort.c quicksortWithStages.c slowsort.c stoogeSort.c \
	threadedMergeSort.c util.c
OBJ = $(SRC:.c=.o)
BINDIR = /usr/local/bin
CC = cc
STRIP = strip
EXE = sorts
CFLAGS = -pedantic -Wall -O2 -march=native -flto


.PHONY: all help strip install clean

default: all

all: $(EXE)

help:
	@echo "To compile, type:"
	@echo ""
	@echo "make [target]"
	@echo ""
	@echo "Where target is one of the following:"
	@echo ""
	@echo "all:              > Compile and link all source files"
	@echo "help:             > Print this message"
	@echo "strip:            > Strip the executable"
	@echo "[An object file]  > Recompiles and re-links the object file if needed"
	@echo "install:          > Strip and install the executable"
	@echo "uninstall:        > Uninstall the executable"
	@echo "clean:            > Clean up"
	@echo ""
	@echo "If no target is given, it will use \"all\""

strip:
	$(STRIP) $(EXE)

install: strip
	-mkdir -p -m 755 $(BINDIR)
	-cp $(EXE) $(BINDIR)

uninstall:
	rm -f $(BINDIR)/$(EXE)

clean:
	rm -f $(EXE) $(OBJ)

$(EXE): $(OBJ)
	+$(CC) $(CFLAGS) -o $@ $(OBJ)
