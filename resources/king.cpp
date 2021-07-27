#include "king.h"

void king::showpath(RenderWindow& window, int(&board)[8][8],RectangleShape (&square)[8][8],int row,int col,
		int piece,vector<vector<int>> &current_possible)
{
	if (piece == 5 || piece == -5) {
		for(pair<int,int> step_dir:step_direction)
		{
			int new_row= row + step_dir.first;
			int new_col= col + step_dir.second;
			
			if( (new_row>=0) && (new_col>=0) && (new_row<=7) && (new_col<=7) )
			{
				if ((board[new_row] [new_col]) == 0 )
				{
					square[new_row][new_col].setFillColor(Color::Cyan);
					piece1.copy_to_2dvector(current_possible,new_row,new_col, 0);
				}
				else if((board[new_row] [new_col])>0) //finds white piece:
				{
					if (piece==-5) //if passed sqaure contins black king:
					 {
						 square[new_row][new_col].setFillColor(Color::Red);
						 piece1.copy_to_2dvector(current_possible,new_row,new_col, 1);
					 }
				}
				else if((board[new_row] [new_col])<0)//finds black piece:
				{
					if (piece==5) //if passed sqaure contins white king:
					 {
						 square[new_row][new_col].setFillColor(Color::Red);
						 piece1.copy_to_2dvector(current_possible,new_row,new_col, 1);
					 }
				}
				else{}
				window.draw(square[new_row][new_col]);
				
			}
		}
	}
}
		

