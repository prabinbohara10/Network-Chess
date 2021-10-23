#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

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
#include "game.h"
#include"test.h"


using namespace std;
using namespace sf;

//parent global variable:
extern int white_up_or_down;
extern int black_up_or_down;


//for chess network:
//parent global variable:
extern bool my_turn; //used in chess network:
					//when my_turn== ture then only I can play:

class startmenu
{
private:
	

public:

	Font font;
	Text text;
	//Music music;
	Texture background,play,exit,option,menu1,bplay,boption,bexit;
	Sprite sbackground, splay, soption, sexit,smenu1,sbplay,sboption,sbexit;
	
	void mainmenu();
	void draw(RenderWindow& menu);
	void connection(int x, int y, RenderWindow& menu);
	
};
