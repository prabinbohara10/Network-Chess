#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>
using namespace sf;

class chessboard
{
public:
    int row = 8, col = 8;
    int n = 0;
    int size = 80;
    float scale = 1.3;
    
    
    void set_piece_to_board(RenderWindow&,int (&board)[8][8],RectangleShape(&square)[8][8],Texture& tex,Sprite& sp);
    void draw_baseboard(RenderWindow&, RectangleShape(&square)[8][8]);
    
   

};

