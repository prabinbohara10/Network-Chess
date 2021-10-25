#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include<vector>

#include "chessboard.h"
#include "check.h"




using namespace std;

using namespace sf;
extern int castling_possible_arr[2][3];
extern int en_passant_possible_arr[4];

extern int mouse_pos_x;
extern int mouse_pos_y;

extern	bool w_check;
extern  bool b_check;

extern int Added_width;

extern vector<int> bcaptured_pieces;
extern vector<int> wcaptured_pieces;

extern int white_up_or_down;
extern int black_up_or_down;
//for chess network:
extern bool my_turn;
extern bool time_to_send_sever; 
extern int who_won;//white won=1;blackwon=2;


extern int b_row,b_col,w_row,w_col;
class movement
{
    private:

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
    public:
        void king_position(int (&game_array1)[8][8],int (&king_pos)[2][2]);
        void copy_2d_array(int (&temp_arr)[8][8],int (&game_array)[8][8]);

        int is_move_success(RenderWindow (&window),RectangleShape (&square)[8][8],int(&game_array)[8][8],
        vector<vector<int>> &current_possible,int &current_side, int current_row,int current_col);
        
        void promotion_move(int (&temp_array)[8][8],vector<vector<int>> &current_possible,int i);
        void possible_en_passant(int(&game_array)[8][8],vector<vector<int>> &current_possible,int moved_index);
        int find_check(int(&game_array)[8][8],RenderWindow (&window),RectangleShape (&square)[8][8],
          int &current_side);
        void find_captured_pieces(RenderWindow (&window),vector<vector<int>> &current_possible,
        int(&temp_array)[8][8],int i);
        void show_captured_pieces(RenderWindow (&window));

    
};