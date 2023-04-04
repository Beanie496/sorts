JFLAGS =
JC = javac
COMPDIR = ../compiled
SRC = Quicksort.java Partition.java Swap.java
.SUFFIXES: .java .class

all: 
	javac -d $(COMPDIR) $(SRC)

clean:
	rm -f *.class

default:
	all

Quicksort.class: Quicksort.java
	javac -d $(COMPDIR) Quicksort.java
Partition.class: Partition.java
	javac -d $(COMPDIR) Partition.java
Swap.class: Swap.java
	javac -d $(COMPDIR) Swap.java
