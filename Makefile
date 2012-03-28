CC=g++
CFLAGS=-Wall
CFLAGS_TEST=-Wall -I C:\prog\cppunit-1.12.1\include
LDFLAGS_TEST= -LC:\prog\cppunit-1.12.1\lib -lcppunit
EXEC=Geom

#dirs
DIR_SRC=src
DIR_OBJ=obj
DIR_TESTS=tests
DIR_BIN=bin

all: $(DIR_BIN)/$(EXEC)

$(DIR_BIN)/$(EXEC): $(DIR_OBJ)/main.o $(DIR_OBJ)/variable.o $(DIR_OBJ)/fonction.o
	$(CC) $(DIR_OBJ)/main.o -o $(DIR_BIN)/$(EXEC)

$(DIR_OBJ)/main.o: $(DIR_SRC)/main.cpp $(DIR_SRC)/fonction.hpp $(DIR_SRC)/variable.hpp
	$(CC) -c $(DIR_SRC)/main.cpp -o $(DIR_OBJ)/main.o $(CFLAGS)

$(DIR_OBJ)/variable.o: $(DIR_SRC)/variable.cpp $(DIR_SRC)/variable.hpp
	$(CC) -c $(DIR_SRC)/variable.cpp -o $(DIR_OBJ)/variable.o $(CFLAGS)

$(DIR_OBJ)/fonction.o: $(DIR_SRC)/fonction.cpp $(DIR_SRC)/fonction.hpp $(DIR_SRC)/variable.hpp
	$(CC) -c $(DIR_SRC)/fonction.cpp -o $(DIR_OBJ)/fonction.o $(CFLAGS)

clean:
	rm $(DIR_OBJ)/*.o
	rm $(DIR_OBJ)/$(DIR_TESTS)/*.o

#cppunits

test: $(DIR_OBJ)/$(DIR_TESTS)/main.o
	$(CC) $(DIR_OBJ)/$(DIR_TESTS)/main.o -o $(DIR_BIN)/cppunits $(LDFLAGS_TEST)

$(DIR_OBJ)/$(DIR_TESTS)/main.o : $(DIR_TESTS)/main.cpp
	$(CC) -c $(DIR_TESTS)/main.cpp -o $(DIR_OBJ)/$(DIR_TESTS)/main.o $(CFLAGS_TEST)

#$(DIR_OBJ)/$(DIR_TESTS)/testvecteur.o: $(DIR_TESTS)/testvecteur.cpp $(DIR_TESTS)/testvecteur.hpp $(DIR_SRC)/vecteur.hpp
#	$(CC) -c $(DIR_TESTS)/testvecteur.cpp -o $(DIR_OBJ)/$(DIR_TESTS)/testvecteur.o $(CFLAGS)

#$(DIR_OBJ)/$(DIR_TESTS)/testscalaire.o: $(DIR_TESTS)/testscalaire.cpp $(DIR_TESTS)/testscalaire.hpp $(DIR_SRC)/scalaire.hpp $(DIR_SRC)/angle.hpp $(DIR_SRC)/monome.hpp
#	$(CC) -c $(DIR_TESTS)/testscalaire.cpp -o $(DIR_OBJ)/$(DIR_TESTS)/testscalaire.o $(CFLAGS)


