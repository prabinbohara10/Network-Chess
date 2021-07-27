#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include"piece.h"

using namespace sf;
class bishop
{
	vector <pair<int,int>> slide_direction={
		{-1,-1},{-1,1},
		{1,-1},{1,1}
		};
	piece piece1;
public:

	int upleft,upright,downleft,downright,temp;
	void showpath(RenderWindow& window, int(&board)[8][8],RectangleShape (&square)[8][8],int row,int col,
		int piece,vector<vector<int>> &current_possible);
};

