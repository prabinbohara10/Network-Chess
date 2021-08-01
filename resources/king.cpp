#include "king.h"
//prabin bohara changed
void king::showpath(RenderWindow& window, int(&board)[8][8],RectangleShape (&square)[8][8],int row,int col,
		int piece,vector<vector<int>> &current_possible,int current_side)
{
	if (piece == 5 || piece == -5) 
	{
		int a=piece1.is_king_castling_possible(square,board,current_possible,current_side);
		for(pair<int,int> step_dir:step_direction)
		{
			int new_row= row + step_dir.first;
			int new_col= col + step_dir.second;
			
			if( (new_row>=0) && (new_col>=0) && (new_row<=7) && (new_col<=7) )
			{
				if ((board[new_row] [new_col]) == 0 )
				{
					
					piece1.copy_to_2dvector(square,current_possible,new_row,new_col, 0 ,0);
				}
				else if((board[new_row] [new_col])>0) //finds white piece:
				{
					if (piece==-5) //if passed sqaure contins black king:
					 {
					
						 piece1.copy_to_2dvector(square,current_possible,new_row,new_col, 1,0);
					 }
				}
				else if((board[new_row] [new_col])<0)//finds black piece:
				{
					if (piece==5) //if passed sqaure contins white king:
					 {
						 
						 piece1.copy_to_2dvector(square,current_possible,new_row,new_col, 1,0);
					 }
				}
				else{}
				
				
			}
		}
		
		//drawing all current possible:
		bool first=true;//to skip first since first contains the parent square:
		for(vector<int> each_possible:current_possible)
		{
			int row=each_possible[0];
			int col=each_possible[1];
			int can_kill=each_possible[2];
			if(first)
			{
				first=false;
			}
			else
			{
			window.draw(square[row][col]);
			}
			
		}
		

	}
}
		

