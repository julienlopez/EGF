CC=g++
CFLAGS= -std=gnu++0x -Wall -I include
CFLAGS_TEST=-Wall -I include
LDFLAGS_TEST= -lcppunit
EXEC=EGL

#dirs
DIR_SRC=src
DIR_OBJ=obj
DIR_TESTS=tests
DIR_BIN=bin

all: $(DIR_BIN)/$(EXEC)

$(DIR_BIN)/$(EXEC): $(DIR_OBJ)/main.o $(DIR_OBJ)/variable.o $(DIR_OBJ)/fonction.o $(DIR_OBJ)/monome.o $(DIR_OBJ)/variablehandler.o $(DIR_OBJ)/fonctionhandler.o
	$(CC) $(DIR_OBJ)/main.o $(DIR_OBJ)/variable.o $(DIR_OBJ)/fonction.o $(DIR_OBJ)/monome.o $(DIR_OBJ)/variablehandler.o $(DIR_OBJ)/fonctionhandler.o -o $(DIR_BIN)/$(EXEC)

$(DIR_OBJ)/main.o: $(DIR_SRC)/main.cpp $(DIR_SRC)/fonction.hpp $(DIR_SRC)/variable.hpp
	$(CC) -c $(DIR_SRC)/main.cpp -o $(DIR_OBJ)/main.o $(CFLAGS)

$(DIR_OBJ)/variable.o: $(DIR_SRC)/variable.cpp $(DIR_SRC)/variable.hpp $(DIR_SRC)/variablehandler.hpp
	$(CC) -c $(DIR_SRC)/variable.cpp -o $(DIR_OBJ)/variable.o $(CFLAGS)

$(DIR_OBJ)/variablehandler.o: $(DIR_SRC)/variablehandler.cpp $(DIR_SRC)/variablehandler.hpp $(DIR_SRC)/variable.hpp $(DIR_SRC)/singleton.hpp
	$(CC) -c $(DIR_SRC)/variablehandler.cpp -o $(DIR_OBJ)/variablehandler.o $(CFLAGS)

$(DIR_OBJ)/fonction.o: $(DIR_SRC)/fonction.cpp $(DIR_SRC)/fonction.hpp $(DIR_SRC)/variable.hpp
	$(CC) -c $(DIR_SRC)/fonction.cpp -o $(DIR_OBJ)/fonction.o $(CFLAGS)

$(DIR_OBJ)/monome.o: $(DIR_SRC)/monome.cpp $(DIR_SRC)/monome.hpp $(DIR_SRC)/fonction.hpp $(DIR_SRC)/variable.hpp
	$(CC) -c $(DIR_SRC)/monome.cpp -o $(DIR_OBJ)/monome.o $(CFLAGS)

$(DIR_OBJ)/fonctionhandler.o: $(DIR_SRC)/fonctionhandler.cpp $(DIR_SRC)/fonctionhandler.hpp $(DIR_SRC)/fonction.hpp $(DIR_SRC)/singleton.hpp
	$(CC) -c $(DIR_SRC)/fonctionhandler.cpp -o $(DIR_OBJ)/fonctionhandler.o $(CFLAGS)

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


