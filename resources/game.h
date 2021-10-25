#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Network.hpp>

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
#include"check.h"



using namespace std;
using namespace sf;

extern vector<int> bcaptured_pieces;
extern vector<int> wcaptured_pieces;

//parent global variable:
extern int white_up_or_down;
extern int black_up_or_down;


//for chess network:
//parent global variable:
extern bool my_turn; //used in chess network:
					//when my_turn== ture then only I can play:

extern bool time_to_send_sever; 
extern bool to_trigger_event;

extern int who_won;//white won=1;blackwon=2;


class game
{
private:
	int current_side_to_play=0;//0 for white and 1 for black:

public:

	
	void main_game(int a);
    void network_game(int a);
};
