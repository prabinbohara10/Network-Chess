#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include<vector>

#include"piece.h"

using namespace std;
using namespace sf;

extern int Added_width;

class pawn
{
	private:
	Texture prtex,pqtex,pktex,pbtex; //pqtex=promotion queen texture ...
    Sprite prsp,pqsp,pksp,pbsp; //pksp=promotion knight sprite
	
	piece piece1;
public:

	
	void showpath(RenderWindow& window, int(&board)[8][8],RectangleShape (&square)[8][8],int row,int col,
		int piece,vector<vector<int>> &current_possible,int &current_side);
	void promotion(RenderWindow& window, int(&board)[8][8], RectangleShape(&square)[8][8], int row,
        int col, int piece, vector<vector<int>> &current_possible,int &current_side);

	
};

