COMPILER=g++

BISHOP=../resources/bishop.cpp
CHESSBOARD=../resources/chessboard.cpp
EVENTHANDLER=../resources/eventhandler.cpp
KING=../resources/king.cpp
KNIGHT=../resources/knight.cpp
MAIN=../resources/main.cpp
PAWN=../resources/pawn.cpp
PIECE=../resources/piece.cpp
QUEEN=../resources/queen.cpp
ROOK=../resources/rook.cpp

all: compile link

compile:
	$(COMPILER) -I ../src/include -c $(BISHOP) $(CHESSBOARD) $(EVENTHANDLER) $(KING) $(KNIGHT) $(MAIN) $(PAWN) $(PIECE) $(QUEEN) $(ROOK)

link:
	$(COMPILER) bishop.o chessboard.o eventhandler.o king.o knight.o main.o pawn.o piece.o queen.o rook.o -o main -L ../src/lib -lsfml-graphics -lsfml-window -lsfml-system -lsfml-network