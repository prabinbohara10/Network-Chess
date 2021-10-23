#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include<vector>

#include "chessboard.h"
#include "pawn.h"
#include "rook.h"
#include "bishop.h"
#include "queen.h"
#include "king.h"
#include "knight.h"
#include"movement.h"
#include"startmenu.h"


using namespace std;
using namespace sf;

//from movement.h


extern int Added_width;

extern int white_up_or_down;
extern int black_up_or_down;
//for chess network:
extern bool my_turn;
extern bool time_to_send_sever; 


extern int b_row,b_col,w_row,w_col;

class check
{
private:
	//vector containing the pair of all posibile squares of movements:
	vector <pair<int,int>> slide_direction={ 
		{-1,-1},{-1,0},{-1,1},
		{0,-1},    {0,1},
		{1,-1},{1,0},{1,1}
	};
	pawn p1;
	rook r1;
	knight n1;
	bishop b1;
	queen q1;
	king k1;
	vector<vector<int>> current_possible;//to store the information of all possible moves of particular piece:

	//from movement.h
	vector <pair<int,int>> king_direction={ 
		{-1,-1},{-1,0},{-1,1},
		{0,-1},    {0,1},
		{1,-1},{1,0},{1,1},

        {-2,-1},{-2,1},
		{-1,2},{1,2},
		{2,1},{2,-1},
		{1,-2},{-1,-2}
	    };
        Texture tex;
        Sprite sp;
        chessboard c1;
        int king_pos[2][2];
		bool w_check;
		bool b_check;
		int up, down, left, right, temp;
	int upleft, upright, downleft, downright;
public:
	
	bool isCheckmate2(int game_arr[8][8],int current_side_to_play);

	//from movement.h
	 void king_position2(int (&game_array1)[8][8],int (&king_pos)[2][2]);
        void copy_2d_array2(int (&temp_arr)[8][8],int (&game_array)[8][8]);

        int is_move_success2(RenderWindow (&window),RectangleShape (&square)[8][8],int(&game_array)[8][8],
        vector<vector<int>> &current_possible,int &current_side, int current_row,int current_col);
        
        void promotion_move2(int (&temp_array)[8][8],vector<vector<int>> &current_possible,int i);
        void possible_en_passant2(int(&game_array)[8][8],vector<vector<int>> &current_possible,int moved_index);
        int find_check2(int(&game_array)[8][8],RenderWindow (&window),RectangleShape (&square)[8][8],
          int &current_side);
        void find_captured_pieces2(RenderWindow (&window),vector<vector<int>> &current_possible,
        int(&temp_array)[8][8],int i);
        void show_captured_pieces2(RenderWindow (&window));
};

