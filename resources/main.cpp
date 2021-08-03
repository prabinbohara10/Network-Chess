
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



int main()
{
	startmenu startmenu1;
	startmenu1.mainmenu();

	
	// int game_array[8][8] = {
	//   { -1,-2,-3,-4,-5,-3,-2,-1 },
	//   { -6,0,-6,0 ,-6,-6,0,5 },
	//   {  0, -1, 0, 5, 0, 0, 1, 0 },
	//   {  -5, 4, 0, 0, 0, -6, 0, 5 },
	//   {  5, 0, -2, 5, 0, 0, 3, 0 },
	//   {  0, 6, 0, 0, 0, 0, -4, 0 },
	//   {  -1, 6, 6, 0, 6, 6, 6, 6 },
	//   {  1, 0, 0, 4, 5, 0, 0, 1 }
	// };
	// RectangleShape square[8][8];   //for board
	// Texture tex;       //for pieces img
	// Sprite sp;         //for displaying those images


	// RenderWindow window(VideoMode(800, 640), "THE BOARD", Style::Close | Style::Titlebar);
	// window.setFramerateLimit(60); 

	

	// chessboard chessboard1;
	

	// //initial clear:
	// window.clear();
	
	// //initial drawing the board in starting position:
	// chessboard1.draw_baseboard(window, square);
	// chessboard1.set_piece_to_board(window, game_array,square, tex, sp);

	// //for handling events: EventHandler class
	// EventHandler eventhandler1;
	// eventhandler1.gamesidescreen(window,0,0);
	// //display the initial postion board:
	// window.display();


	
	
	
	// while (window.isOpen()) {
		
	// 	//Event handler section:
		
	// 	eventhandler1.event_function(window,game_array,square);

		

	// }


	return 0;
}
