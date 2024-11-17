EXEC1 = progdinamica
EXEC2 = progfuerzabruta

SRC1 = progdinamica.cpp
SRC2 = progfuerzabruta.cpp
FUNCSRC = funcostos.cpp

OBJ1 = $(SRC1:.cpp=.o)
OBJ2 = $(SRC2:.cpp=.o)
FUNCOBJ = $(FUNCSRC:.cpp=.o)

CXX = g++
CXXFLAGS = -Wall -std=c++17

all: $(EXEC1) $(EXEC2)

$(EXEC1): $(OBJ1) $(FUNCOBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(EXEC2): $(OBJ2) $(FUNCOBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

run: all
	@echo "Ejecutando $(EXEC1):"
	@./$(EXEC1)
	@echo ""
	@echo "Ejecutando $(EXEC2):"
	@./$(EXEC2)

clear:
	rm -f $(EXEC1) $(EXEC2) *.o