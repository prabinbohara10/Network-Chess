#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include<vector>

#include"piece.h"

using namespace std;
using namespace sf;
class queen
{
	//vector containing the pair of all posibile squares of movements:
	vector <pair<int,int>> slide_direction={ 
		{-1,-1},{-1,0},{-1,1},
		{0,-1},    {0,1},
		{1,-1},{1,0},{1,1}
	};
	piece piece1;
public:
	int up, down, left, right, temp;
	int upleft, upright, downleft, downright;
	void showpath(RenderWindow& window, int(&board)[8][8],RectangleShape (&square)[8][8],int row,int col,
		int piece,vector<vector<int>> &current_possible);
};

