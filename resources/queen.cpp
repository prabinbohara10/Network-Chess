#include "queen.h"

void queen::showpath(RenderWindow& window, int(&board)[8][8],RectangleShape (&square)[8][8],int row,int col,
		int piece,vector<vector<int>> &current_possible)
{
	if (piece == 4 || piece == -4) {
		for(pair<int,int> slide_dir: slide_direction)
		{
			int new_row= row+ slide_dir.first;
			int new_col= col+ slide_dir.second;
			while( (new_row>=0)&& (new_col>=0) && (new_row<=7) && (new_col<=7) )
			{
				if(board[new_row][new_col]==0) //finds empty square
				{
				square[new_row][new_col].setFillColor(Color::Cyan);
				window.draw(square[new_row][new_col]);
				piece1.copy_to_2dvector(current_possible,new_row,new_col,0);
				}
				else if(board[new_row][new_col]>0) //finds white piece
				{
					if(piece==-4)  //if the clicked piece is queen of black:
					{
						square[new_row][new_col].setFillColor(Color::Red);
				 		window.draw(square[new_row][new_col]);
						piece1.copy_to_2dvector(current_possible,new_row,new_col, 1);
					}
					break;
			
				}
				else if(board[new_row][new_col]<0) //finds black piece
				{
					if(piece==4) //if the clicked piece is queen of white:
					{
						square[new_row][new_col].setFillColor(Color::Red);
						window.draw(square[new_row][new_col]);
						piece1.copy_to_2dvector(current_possible,new_row,new_col, 1);
					}
					break;
				}
				new_row+=slide_dir.first;
				new_col+=slide_dir.second;
			}//end of while loop:
		}
	}
}


	
