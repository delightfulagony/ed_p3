# Compilador y flags
CXX := g++
CXXFLAGS := -g
VFLAGS := --leak-check=full

# Nombre del proyecto
PROJECT := pila_max

# Directorios del proyecto
OBJ := obj/
DOC := doc/
BIN := bin/

# Archivos del proyecto
EXEC = $(BIN)$(PROJECT)
MAIN = main.cpp
MAINOBJ = $(MAIN:.cpp=.o)
SOURCES := VDG.cpp PilaMax.cpp
HEADERS = $(SOURCES:.cpp=.h)

# Otras variables
DOCUMENTATION = doxygen
BROWSER = firefox
COMPRESS = tar
BOLD = `tput bold`
GREEN = `tput setaf 2`
RESET = `tput sgr0`

# Variables definidas
define makebin =
@echo "Creando el ejecutable $@ ..."
@$(CXX) $(CXXFLAGS) -o $@ $^
@-mv $^ $(OBJ)
@echo "${GREEN}HECHO${RESET}"
endef
define makeobj =
@echo "Creando el objeto $@ ..."
@$(CXX) $(CXXFLAGS) -o $@ $<
@echo "${GREEN}HECHO${RESET}"
endef
define makedir =
@echo "Creando carpeta $@ ..."
@mkdir -p $@
@echo "${GREEN}HECHO${RESET}"
endef
define erase =
@echo "Borrando ejecutable..."
@-rm -rf $(BIN)
@echo "Borrando objetos..."
@-rm -rf $(OBJ)
@echo "Borrando documentación..."
@rm -rf $(DOC)html $(DOC)latex
@echo "${GREEN}HECHO${RESET}"
endef

# Directivas
vpath %.h include/
vpath %.cpp src/
vpath %.o obj/

# Variables específicas a un patrón
%.o: CXXFLAGS += -Wall -I./include -I./src -c

# Reglas sin recetas
all: $(EXEC) help author
.PHONY: clean
$(MAINOBJ): | $(OBJ)
$(EXEC): | $(BIN)

# Reglas

$(EXEC): $(MAINOBJ)
	$(makebin)

$(MAINOBJ): $(MAIN) $(HEADERS) $(SOURCES)
	$(makeobj)
	
$(OBJ):
	$(makedir)

$(BIN):
	$(makedir)


clean:
	$(erase)

$(DOCUMENTATION):
	@rm -rf $(DOC)html $(DOC)latex
	@$(DOCUMENTATION) $(DOC)$(PROJECT).doxy
	@echo "${BOLD}Abriendo documentación...${RESET}"
	@$(BROWSER) & $(DOC)html/index.html

$(COMPRESS): clean
	$(COMPRESS) -cvzf ../$(PROJECT).tgz ../ed_p3
	
valgrind: $(PROJECT)
	valgrind $(VFLAGS) ./$(EXEC)
	
help:
	@echo "________________________________________________________________________________"
	@echo "Lista de parámetros posibles:"
	@echo "		${BOLD}clean${RESET}		\
	Elimina los archivos objeto y ejecutables"
	@echo "		${BOLD}doxygen${RESET}		\
	Genera la documentación"
	@echo "		${BOLD}tar${RESET}		\
	Genera el tgz del proyecto"
	@echo "		${BOLD}valgrind${RESET}	\
	Realiza una ejecución por medio de valgrind"
	@echo "		${BOLD}help${RESET}		\
	Muestra esta ayuda"
	@echo "		${BOLD}author${RESET}		\
	Información sobre el autor de este programa"
	@echo "________________________________________________________________________________"

author:
	@echo "Este es un proyecto realizado por:"
	@echo "		- Gonzalo Moreno Soto (https://github.com/delightfulagony)"
	@echo "		- Manuel Gachs Ballegeer (https://github.com/Manuelbelgicano)" 
	@echo "para la asignatura de Estructura de Datos de la Universidad de Granada"
