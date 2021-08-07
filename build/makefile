COMPILER=g++ 

BISHOP=../resources/bishop.cpp
CHESSBOARD=../resources/chessboard.cpp
EVENTHANDLER=../resources/eventhandler.cpp
KING=../resources/king.cpp
KNIGHT=../resources/knight.cpp
MAIN=../resources/main.cpp
MOVEMENT=../resources/movement.cpp
PAWN=../resources/pawn.cpp
PIECE=../resources/piece.cpp
QUEEN=../resources/queen.cpp
ROOK=../resources/rook.cpp
STARTMENU=../resources/startmenu.cpp



client=../resources/client.cpp
server=../resources/server.cpp


# all: compile link

all: compile1 link1 compile2 link2



compile:
	$(COMPILER) -I ../src/include -c $(BISHOP) $(CHESSBOARD) $(EVENTHANDLER) $(KING) $(KNIGHT) $(MAIN) $(MOVEMENT) $(PAWN) $(PIECE) $(QUEEN) $(ROOK) $(STARTMENU)

link:
	$(COMPILER) bishop.o chessboard.o eventhandler.o king.o knight.o main.o movement.o pawn.o piece.o queen.o rook.o startmenu.o -o main -L ../src/lib -lsfml-graphics -lsfml-window -lsfml-system -lsfml-network




compile1:
	$(COMPILER) -I ../src/include -c $(client)

link1:
	$(COMPILER) client.o -o client -L ../src/lib -lsfml-graphics -lsfml-window -lsfml-system -lsfml-network

compile2:
	$(COMPILER) -I ../src/include -c $(server)

link2:
	$(COMPILER) server.o -o server -L ../src/lib -lsfml-graphics -lsfml-window -lsfml-system -lsfml-network

