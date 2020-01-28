CC		:= g++
CFLAGS	:= -std=c++17 -Wall -Wextra

SRC 	:= src
INC		:= inc
SFML	:= -DSFML_STATIC -Isfml/include -Lsfml/lib  
LIB		:= -lsfml-window-s -lsfml-graphics-s -lsfml-system-s -lopengl32 -lwinmm -lgdi32 -lfreetype 

BIN 	:= bin
EXE		:= game.exe

all: $(BIN)/$(EXE)

$(BIN)/$(EXE): $(SRC)/*
	$(CC) $(CFLAGS) -I$(INC) $(SFML) $^ -o $@ $(LIB)

clean:
	rm *.o $(EXECUTABLE)

run: all
	./$(BIN)/$(EXECUTABLE)
