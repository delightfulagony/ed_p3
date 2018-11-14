# Makefile de la práctica 3 para la asignatura de Estructura de Datos del DGIIM
# Autores:
# 	- Manuel Gachs Ballegeer
# 	- Gonzalo Moreno Soto
# Esta práctica esta bajo la licencia GPLv3

# Nombre del proyecto
PROJECT = pila_max

# Compilador usado y flags
CC = g++
FLAGS = -Wall -g

# Directorios del proyecto
INC = ./include
SRC = ./src
OBJ = ./obj
DOC = ./doc
BIN = ./bin
DATA = ./data
ZIP = ./zip

# Valgrind flags
VFLAGS = --leak-check=full

## Tests
# Test a ejecutar con 'make test'
TEST = $(DATA)/test.txt
#Test de valgrind
VTEST = $(DATA)/vtest.txt

#Reglas

all: $(PROJECT) help author

$(PROJECT): $(OBJ)/PilaMax.o $(OBJ)/VDG.o $(OBJ)/$(PROJECT).o
	-mkdir -p $(BIN) 
	$(CC) $(FLAGS) -o $(BIN)/$(PROJECT) $?

$(OBJ)/VDG.o: $(SRC)/VDG.cpp $(INC)/VDG.h
	$(CC) -I$(INC) -c -o $@ $<

$(OBJ)/PilaMax.o: $(SRC)/PilaMax.cpp $(INC)/PilaMax.h
	$(CC) -I$(INC) -c -o $@ $<

$(OBJ)/$(PROJECT).o: $(SRC)/$(PROJECT).cpp
	$(CC) -I$(INC) -c -o $@ $<

refresh: clean $(PROJECT)

clean:
	rm $(BIN)/* $(OBJ)/*
	rm -rf $(DOC)/html $(DOC)/latex

doxy:
	rm -rf $(DOC)/html $(DOC)/latex
	doxygen $(DOC)/$(PROJECT).doxy
	firefox & $(DOC)/html/index.html

tar: clean
	cd .. && prompt% tar zcv $(PROJECT).tgz ed_p3
	
valgrind: $(PROJECT)
	valgrind $(VFLAGS) $(BIN)/$(PROJECT) $(VTEST)
	
help:
	@echo "________________________________________________________________________________"
	@echo "Lista de parámetros posibles:"
	@echo "		refresh		Compila el proyecto desde cero"
	@echo "		clean		Elimina los archivos objeto y ejecutables"
	@echo "		doxy		Genera la documentación"
	@echo "		tar		Genera el tgz del proyecto"
	@echo "		valgrind	Realiza un test por medio de valgrind"
	@echo "		test		Realiza un los test"
	@echo "		help		Muestra esta ayuda"
	@echo "		author		Información sobre el autor de este programa"
	@echo "________________________________________________________________________________"

author:
	@echo "Este es un proyecto realizado por Gonzalo Moreno Soto (https://github.com/delightfulagony)"
	@echo "y Manuel Gachs Ballegeer (https://github.com/Manuelbelgicano)" 
	@echo "para la asignatura de Estructura de Datos de la Universidad de Granada"

