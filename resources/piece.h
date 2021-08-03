#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <vector>
using namespace std;

using namespace sf;

 extern int castling_possible_arr[2][3];
 extern int en_passant_possible_arr[4];

class piece
{
 

	int down_side=0,up_side=1; //board ko tala white cha ani mathi black cha:
								//This assumption could be changed when we play in different computers:


	
public:
   void copy_to_2dvector(RectangleShape (&square)[8][8],vector<vector<int>> &current_possible,int row,int col,
  		int can_kill,int special_move);
	
	//retuns 1 if king castling is possible otherwise returns 0:
	int is_king_castling_possible(RectangleShape (&square)[8][8],int(&board)[8][8],
		vector<vector<int>> &current_possible,int current_side);

	//for en passant:
	void is_en_passant(RectangleShape (&square)[8][8],int(&board)[8][8],
		vector<vector<int>> &current_possible,int current_side,int clicked_row,int clicked_col);
};