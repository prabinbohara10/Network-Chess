#include "piece.h"

 //defination of global variable:
 int castling_possible_arr[2][3]={
		{1,1,1},  	// For white:- initialize 1 if both rook and king hasn't move yet:
					// white_king=1; white_rook_1=1;  white_rook_2=1;
		{1,1,1}	  // For black:- initialize 1 if both rook and king hasn't move yet:
	};

 int en_passant_possible_arr[4]={
        0,      //1 if currently en passant is possible:
        -1,-1,  //if possible, opponent has move pawn to this square:
        6       //6 if white pawn is in that square and -6 if black is in that square:
 };

void piece::copy_to_2dvector(RectangleShape (&square)[8][8],vector<vector<int>> &current_possible,
    int row,int col,int can_kill,int special_move)
{
    
    if(can_kill==0)
        square[row][col].setFillColor(Color::Cyan);
    else
        square[row][col].setFillColor(Color::Red);

    

    vector<int> temp;
    temp.push_back(row);
    temp.push_back(col);
    temp.push_back(can_kill);
    temp.push_back(special_move);
    current_possible.push_back(temp);
    
}

//to check is_castling_possible
int piece::is_king_castling_possible(RectangleShape (&square)[8][8],int(&board)[8][8],
    vector<vector<int>> &current_possible,int current_side)
{
    int king_row, king_col=4;
    int move_flag=0;
    if(current_side==down_side)
        king_row=7;
    else 
        king_row=0;
    
    if(castling_possible_arr[current_side][0]==1) //king isn't moved once:
    {
        if(castling_possible_arr[current_side][1]==1) //queen side ko rook isn't moved once.
        {
            for(int i=1;i<=3;i++)
            {
               // cout<<board[king_row][king_col-i]<<"\t";
                if(board[king_row][king_col-i]==0)
                    move_flag++;
                    
            }
            
            if(move_flag==3)
            
             {
                 
                 
                 copy_to_2dvector(square,current_possible,king_row,king_col-2,0,-1);
             }
        }
        
        move_flag=0;
        if(castling_possible_arr[current_side][2]==1) //king side ko rook isn't moved once.
        {
            for(int i=1;i<=2;i++)
            {
                if(board[king_row][king_col+i]!=0)
                    break;   
                else
                    move_flag++;
            }
            
            if(move_flag==2)
            {copy_to_2dvector(square,current_possible,king_row,king_col+2,0,1);}
        }
    }
        

        return 1;
}


//to check en passant:
void piece::is_en_passant(RectangleShape (&square)[8][8],int(&board)[8][8],
		vector<vector<int>> &current_possible,int current_side,int clicked_row,int clicked_col)
{
    
    int pawn_row_factor=((current_side==0) ? -1 : 1);
    if(en_passant_possible_arr[0]==1)
    {
        if(clicked_row==en_passant_possible_arr[1]) //checks if row is same:
        {
           if(clicked_col==(en_passant_possible_arr[2]-1) || clicked_col==(en_passant_possible_arr[2]+1) )
            {
                copy_to_2dvector(square,current_possible,clicked_row+ pawn_row_factor,en_passant_possible_arr[2],
                1,2*pawn_row_factor);
            }
        }
    }
}