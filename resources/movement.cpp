#include "movement.h"

int movement::is_move_success(RenderWindow (&window),RectangleShape (&square)[8][8],int(&game_array)[8][8],
        vector<vector<int>> &current_possible, int &current_side,int current_row,int current_col)
{
    //to check if the clicked_square is present in the current_possible vector:
			if(current_possible.size()>1)
			{
				for(int i=1;i<current_possible.size();i++)
				{
				  if(current_possible[i][0]==current_row && current_possible[i][1]==current_col)
					{
							//need_to_show_possible_moves=0;
							int parent_row=current_possible[0][0];
							int parent_col=current_possible[0][1];
							game_array[parent_row][parent_col]=0;
							game_array[current_row][current_col]=current_possible[0][2];

							
    
                            //if the move is castling:
							int castling_row=((current_side==0) ? 7 :0);
                            if(current_possible[i][3]==-1)
                            {
                                game_array[castling_row][3]=game_array[castling_row][0];
                                game_array[castling_row][0]=0;
                                castling_possible_arr[current_side][0]=0;
                            }
                            else if(current_possible[i][3]==1)
                            {
                                game_array[castling_row][5]=game_array[castling_row][7];
                                game_array[castling_row][7]=0;
                                castling_possible_arr[current_side][0]=0;
                            }
                            else {}

							//if the move is en passant:
							if(current_possible[i][3]==2)
							{
								int row=current_possible[0][0];
								int col=current_col;
								game_array[row][col]=0;
							}

							en_passant_possible_arr[0]=0;//disable en passant:

							int current_piece_moved=current_possible[0][2];
							if(current_piece_moved==6 || current_piece_moved==-6)
							   { possible_en_passant(game_array,current_possible,i);}

							current_side=!current_side; //to switch current side to play:
							
							current_possible.clear();
                            
							window.clear();
							c1.draw_baseboard(window,square);
							c1.set_piece_to_board(window, game_array,square, tex, sp);
							
							return 1;
					}
					
				}
			}
			//to remove all elemets of vector 
			 //	:either it finds possible moves or not:
			 current_possible.clear();
             return 0; //move not successful:
}

//possible en passant:

void movement::possible_en_passant(int(&game_array)[8][8],vector<vector<int>> &current_possible,int moved_index)
{
	int row_moved=current_possible[moved_index][0];
		int col_moved=current_possible[moved_index][1];
	if( (current_possible[0][0]==6 || current_possible[0][0]==1 ) &&
		(row_moved==4 || row_moved==3) )
	{
		
		int current_piece_moved=current_possible[0][2];
		if(current_piece_moved==6)
		{
			if(game_array[row_moved][col_moved-1]==-6 || game_array[row_moved][col_moved+1]==-6)
			{
				en_passant_possible_arr[0]=1;
				en_passant_possible_arr[1]=row_moved;
				en_passant_possible_arr[2]=col_moved;
			}

			
		}
		else
		{
			if(game_array[row_moved][col_moved-1]==6 || game_array[row_moved][col_moved+1]==6)
			{
				en_passant_possible_arr[0]=1;
				en_passant_possible_arr[1]=row_moved;
				en_passant_possible_arr[2]=col_moved;
			}
		}
		en_passant_possible_arr[3]=current_piece_moved;
	}
}