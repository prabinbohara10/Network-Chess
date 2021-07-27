#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include<vector>
using namespace std;

using namespace sf;

class piece
{
  public:
  void copy_to_2dvector(vector<vector<int>> &current_possible,int row,int col,int can_kill);
};