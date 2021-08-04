
#include <SFML/Graphics.hpp>

#include<iostream>
#include<vector>
#include "chessboard.h"
#include "pawn.h"
#include "rook.h"
#include "bishop.h"
#include "queen.h"
#include "king.h"
#include "knight.h"
#include "EventHandler.h"
#include"startmenu.h"

using namespace std;

int Added_width = 160;

vector<int> bcaptured_pieces;
vector<int> wcaptured_pieces;

int mouse_pos_x;
int mouse_pos_y;

int main()
{
	startmenu startmenu1;
	startmenu1.mainmenu();

	
	


	return 0;
}
