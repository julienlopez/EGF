CC=g++
CFLAGS= -std=gnu++0x -Wall

#dirs
DIR_SRC=src
DIR_OBJ=obj
DIR_TESTS=tests
DIR_BIN=bin

CLASSMAKER=classmaker

$(CLASSMAKER):$(DIR_OBJ)/$(CLASSMAKER)/main.o
	$(CC) $(CFLAGS) $(DIR_OBJ)/$(CLASSMAKER)/main.o -o $(DIR_BIN)/$(CLASSMAKER).exe

$(DIR_OBJ)/$(CLASSMAKER)/main.o: $(CLASSMAKER)/main.cpp
	$(CC) $(CFLAGS) -c $(CLASSMAKER)/main.cpp -o $(DIR_OBJ)/$(CLASSMAKER)/main.o

all: classmaker

clean:
	rm $(DIR_OBJ)/$(CLASSMAKER)/*.o
