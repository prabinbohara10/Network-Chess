#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

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

extern SoundBuffer click,hoover;
extern Music menu_music;
extern Sound click1,hoover1;

extern bool is_sound,is_music ;
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
    int i=0,j=0,k=0,a=0,b=0,c=0,v=0,w=0,x=0,y=0,z=0;

public:

	Font font;
	Text text;
	//Music music;
	Texture background,play,exit,option,menu1,bplay,boption,bexit,back,bback,online,bonline,offline,boffline;
	Sprite sbackground, splay, soption, sexit,smenu1,sbplay,sboption,sbexit,sback,sbback,sonline,sbonline,soffline,sboffline;
	Texture back1,bback1,bmusicon,bmusicoff,soundon,soundoff,bbmusicon,bbmusicoff,bsoundon,bsoundoff;
	Sprite sback1,sbback1,sbmusicon,sbmusicoff,ssoundon,ssoundoff,sbbmusicon,sbbmusicoff,sbsoundon,sbsoundoff;
	
	void mainmenu();
	void draw(RenderWindow& menu);
	void connection(int x, int y, RenderWindow& menu);
	void mode_of_game();
	void setting();
	void drawmode(RenderWindow& menu);//helps to draw icon in mode window
	void drawsetting(RenderWindow& menu);//helps to draw icon in setting window

	void clickplay();
	void hoverplay();
	
};
