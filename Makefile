
CC = g++
CFLAGS = -Wall
LIBS =  -lglut -lGL -lGLU -lGLEW -lm

EXEC_NAME = main

ODIR = obj
SDIR = src
BDIR = bin

all: main

main: dirs main.o environment.o
	$(CC) $(LIBS) $(ODIR)/main.o $(ODIR)/environment.o -o $(BDIR)/$(EXEC_NAME)

dirs:
	mkdir -p $(ODIR) $(BDIR)

main.o: $(SDIR)/main.cpp $(SDIR)/environment.cpp
	$(CC) -c $(LIBS) $(CFLAGS) $(SDIR)/main.cpp -o $(ODIR)/main.o

environment.o: $(SDIR)/environment.cpp
	$(CC) -c $(LIBS) $(CFLAGS) $(SDIR)/environment.cpp -o $(ODIR)/environment.o

clean:
	rm -rf $(ODIR)/*.o $(BDIR)/$(EXEC_NAME)

run: all
	./$(BDIR)/$(EXEC_NAME)
