#include "movement.h"

bool w_check=false;
bool b_check=false;

int b_row=-1,b_col=-1,w_row=-1,w_col=-1;

void movement::king_position(int (&game_array1)[8][8],int (&king_pos)[2][2])
{
	
	for(int i=0;i<8;i++){
		for(int j=0;j<8;j++){
			if(game_array1[i][j]==5){
				king_pos[0][0]=i;
				king_pos[0][1]=j;
			}
			 if(game_array1[i][j]==-5){
				king_pos[1][0]=i;
				king_pos[1][1]=j;
			}
			//if(b_col!=-1 && b_row !=-1 && w_row!=-1 && w_col!=-1)
			//break;
		}//ending of 1st for loop
	}// ending of 2nd for loop
}

void movement::copy_2d_array(int (&destination_arr)[8][8],int (&src_arr)[8][8])
{
	for(int i=0;i<8;i++)
	{
		for(int j=0;j<8;j++)
		{
			destination_arr[i][j]=src_arr[i][j];
		}
	}
}

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
						king_position(game_array,king_pos);
						int temp_array[8][8];
						//to copy game_array to temp_arr:
						copy_2d_array(temp_array,game_array);
					
					
							//need_to_show_possible_moves=0;
							int parent_row=current_possible[0][0];
							int parent_col=current_possible[0][1];
							//game_array[parent_row][parent_col]=0;
							//game_array[current_row][current_col]=current_possible[0][2];
							
							//if move is promotion
							if ((temp_array[parent_row][parent_col]==6 && current_row==0) ||
									 (temp_array[parent_row][parent_col]==-6 && current_row==7 ))
							{

								int a = current_col;
								int b = current_row;
								if(temp_array[parent_row][parent_col]==6 && current_row==0)
								{

									
									//std::cout<<"yes"<<std::endl;

										if(mouse_pos_x>(Added_width+a*80) && mouse_pos_x<(Added_width+a*80+60*0.65) && mouse_pos_y>(b*80) && mouse_pos_y<(b*80+60*0.65))
										{
											temp_array[current_row][current_col]=1;

										}
										else if(mouse_pos_x>(Added_width+a*80+60*0.65) && mouse_pos_x<(Added_width+a*80+60*0.65*2) && mouse_pos_y>(b*80) && mouse_pos_y<(b*80+60*0.65))
										{
											temp_array[current_row][current_col]=2;
										}
										else if(mouse_pos_x>(Added_width+a*80) && mouse_pos_x<(Added_width+a*80+60*0.65) && mouse_pos_y>(b*80+60*0.65) && mouse_pos_y<(b*80+60*0.65*2))
										{
											temp_array[current_row][current_col]=3;
										}
										else if(mouse_pos_x>(Added_width+a*80+60*0.65) && mouse_pos_x<(Added_width+a*80+60*0.65*2) && mouse_pos_y>(b*80+60*0.65) && mouse_pos_y<(b*80+60*0.65*2))
										{
											temp_array[current_row][current_col]=4;
										}
										else{}
									temp_array[parent_row][parent_col]=0;	


								}

								if(temp_array[parent_row][parent_col]==-6 && current_row==7)
								{

								
									//std::cout<<"yes"<<std::endl;

										if(mouse_pos_x>(Added_width+a*80) && mouse_pos_x<(Added_width+a*80+60*0.65) && mouse_pos_y>(b*80) && mouse_pos_y<(b*80+60*0.65))
										{
											temp_array[current_row][current_col]=-1;

										}
										else if(mouse_pos_x>(Added_width+a*80+60*0.65) && mouse_pos_x<(Added_width+a*80+60*0.65*2) && mouse_pos_y>(b*80) && mouse_pos_y<(b*80+60*0.65))
										{
											temp_array[current_row][current_col]=-2;
										}
										else if(mouse_pos_x>(Added_width+a*80) && mouse_pos_x<(Added_width+a*80+60*0.65) && mouse_pos_y>(b*80+60*0.65) && mouse_pos_y<(b*80+60*0.65*2))
										{
											temp_array[current_row][current_col]=-3;
										}
										else if(mouse_pos_x>(Added_width+a*80+60*0.65) && mouse_pos_x<(Added_width+a*80+60*0.65*2) && mouse_pos_y>(b*80+60*0.65) && mouse_pos_y<(b*80+60*0.65*2))
										{
											temp_array[current_row][current_col]=-4;
										}
										else{}
									temp_array[parent_row][parent_col]=0;	


								}
 
							}
							else
							{
								
								temp_array[parent_row][parent_col]=0;
								
								temp_array[current_row][current_col]=current_possible[0][2];

							}

							
    
                            //if the move is castling:
						int castling_row=((current_side==0) ? 7 :0);
                            if(current_possible[i][3]==-1)
                            {
								//to move rook only since king has already moved above:
                                temp_array[castling_row][3]=temp_array[castling_row][0];
                                temp_array[castling_row][0]=0;
                                
                            }
                            else if(current_possible[i][3]==1)
                            {
                                temp_array[castling_row][5]=temp_array[castling_row][7];
                                temp_array[castling_row][7]=0;
                                
                            }
                            else {}

							//if the move is en passant:
							if(current_possible[i][3]==2)
							{
								int row=current_possible[0][0];
								int col=current_col;
								
								temp_array[row][col]=0;
							}
							en_passant_possible_arr[0]=0;//disable en passant:
							int current_piece_moved=current_possible[0][2];
							if(current_piece_moved==6 || current_piece_moved==-6)
							   { possible_en_passant(temp_array,current_possible,i);}


							
							//checks if there is check or not for current move:
							int abc=find_check(temp_array,window,square,current_side);
							if(!abc)
							{
								if( (current_possible[0][2]==1)
								    || (current_possible[0][2]==-1) )
								{
									if(current_possible[0][1]==0)
										castling_possible_arr[current_side][1]=0;
									if(current_possible[0][1]==7)
										castling_possible_arr[current_side][2]=0;
								}

								if (current_possible[i][1]==0)
								{
									if((current_possible[i][0]==0) ||(current_possible[i][0]==7))
									castling_possible_arr[!current_side][1]=0;
								}
								if (current_possible[i][1]==7)
								{
									if((current_possible[i][0]==0) ||(current_possible[i][0]==7))
									castling_possible_arr[!current_side][2]=0;
								}

								//if move is castling:
								
								if(current_possible[i][3]==-1)
								{
									castling_possible_arr[current_side][0]=0;
								}
								else if(current_possible[i][3]==1)
								{
									castling_possible_arr[current_side][0]=0;
								}
								else {}
									
								find_captured_pieces(window,current_possible,game_array,i);
								
								
								//copy temp_array to game_array:
								copy_2d_array(game_array,temp_array);
							
							
								current_possible.clear();
                            
								window.clear();
								c1.draw_baseboard(window,square);
								if(w_check==true){
		 						square[w_row][w_col].setFillColor(Color::Red);
							 	window.draw(square[w_row][w_col]);
								}
								if(b_check==true ){
								square[b_row][b_col].setFillColor(Color::Red);
								window.draw(square[b_row][b_col]);
								}

								c1.set_piece_to_board(window, game_array,square, tex, sp);
								current_side=!current_side; //to switch current side to play:
							
								return 1;
							}
							
					
				  }
					
				}
			}

			int abc=find_check(game_array,window,square,current_side);
			//to remove all elemets of vector 
			 //	:either it finds possible moves or not:
			current_possible.clear();
			w_row=king_pos[0][0];
			w_col=king_pos[0][1];
			b_row=king_pos[1][0];
			b_col=king_pos[1][1];

			    if(current_side==0 && w_check==true)
				{
					//w_check=false;
				// 	if((w_row+w_col)%2==0)
				// 		square[w_row][w_col].setFillColor(Color::White);
				// 	else 
				// 	square[w_row][w_col].setFillColor(Color::Black);
				
				// window.draw(square[w_row][w_col]);
				
					
				}
				if(current_side==1 && b_check==true )
				{
					//b_check=false;
				}
			

			if( (current_side==0 && game_array[current_row][current_col]<0)  //black click detected:
				|| (current_side==1 && game_array[current_row][current_col]>0) ) //white click detected:
             {
		
				window.clear();
				c1.draw_baseboard(window,square);

				if(w_check==true)
				{
		 		square[w_row][w_col].setFillColor(Color::Red);
		 		window.draw(square[w_row][w_col]);
				}
				if(b_check==true )
				{
				square[b_row][b_col].setFillColor(Color::Red);
				window.draw(square[b_row][b_col]);
				}
				
				c1.set_piece_to_board(window, game_array,square, tex, sp);
			
				 return 1; //move not successful:
			 }
			 else
			  return 0;
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





int movement :: find_check(int(&game_array1)[8][8],RenderWindow (&window),RectangleShape (&square)[8][8],
	 int &current_side)
{
	int king_no,a,b,row,col;
	b_row=b_col=w_row=w_col=-1;    //for checking where is king 
	w_check=false;
	b_check=false;

	for(int i=0;i<8;i++){
		for(int j=0;j<8;j++){
			if(game_array1[i][j]==-5){
				b_row=i;
				b_col=j;
			}
			 if(game_array1[i][j]==5){
				w_row=i;
				w_col=j;
			}
			//if(b_col!=-1 && b_row !=-1 && w_row!=-1 && w_col!=-1)
			//break;
		}//ending of 1st for loop
	}// ending of 2nd for loop

	king_no=-5; //at 1st lets take black king;

		//loop for checking if the black king is checked
		for(pair<int,int> king_dir: king_direction)
		{
			int new_row= b_row+ king_dir.first;
			int new_col= b_col+ king_dir.second;
			a= king_dir.first; b=king_dir.second;
			while( (new_row>=0)&& (new_col>=0) && (new_row<=7) && (new_col<=7) )
			{

				 if(game_array1[new_row][new_col]>0) //finds white piece
				{

					//for rook
						if(game_array1[new_row][new_col]==1){
							if((a==-1 && b==0) || (a==0 && b==-1) || (a==0 && b==1) || (a==1 && b==0)){
								b_check=true;
							}
						}//ending of rook

						//for bishop
						if(game_array1[new_row][new_col]==3){
							if((a==-1 && b==-1) || (a==-1 && b==1) || (a==1 && b==-1) || (a==1 && b==1)){
								b_check=true;
							}
						}    //ending of bishop

						//for queen
						if(game_array1[new_row][new_col]==4){
							if((a==-1 && b==0) || (a==0 && b==-1) || (a==0 && b==1) || (a==1 && b==0) ||
							    (a==-1 && b==-1) || (a==-1 && b==1) || (a==1 && b==-1) || (a==1 && b==1)){
								b_check=true;
							}
						}//ending of queen

						//for knight
						if(game_array1[new_row][new_col]==2){
							if((a==-2 && b==-1) || (a==-2 && b==1) || (a==-1 && b==2) || (a==1 && b==2) ||
							    (a==2 && b==1) || (a==2 && b==-1) || (a==1 && b==-2) || (a==-1 && b==2)){
								b_check=true;
								
							}
						}//ending of knight

						//for pawn
						if(game_array1[new_row][new_col]==6){
							if((new_row==b_row+1 && new_col==b_col-1) ||(new_row==b_row+1 && new_col==b_col+1)){
								b_check=true;
							}
						}//ending of pawn 


					
					break;

				}
				//aafnai goti raicha vney break vara new pair liney
				if(game_array1[new_row][new_col]<0)
				{break;}

				if((a==-2 && b==-1) || (a==-2 && b==1) || (a==-1 && b==2) || (a==1 && b==2) ||
							    (a==2 && b==1) || (a==2 && b==-1) || (a==1 && b==-2) || (a==-1 && b==2)){
								
								break;
							}


				new_row+=king_dir.first;
				new_col+=king_dir.second;
			}//end of while loop:
		}   //end for black king check checking

		king_no=5;    //at 2nd lets take white king
		//loop for checking if the white king is checked
		for(pair<int,int> king_dir: king_direction)
		{
			int new_row= w_row+ king_dir.first;
			int new_col= w_col+ king_dir.second;
			a= king_dir.first; b=king_dir.second;
			while( (new_row>=0)&& (new_col>=0) && (new_row<=7) && (new_col<=7) )
			{


				 if(game_array1[new_row][new_col]<0) //finds black piece 
				{
					
						//rook
						if(game_array1[new_row][new_col]==-1){
							if((a==-1 && b==0) || (a==0 && b==-1) || (a==0 && b==1) || (a==1 && b==0)){
								w_check=true;
							}
						}   //ending of rook

						//bishop
						if(game_array1[new_row][new_col]==-3){
							if((a==-1 && b==-1) || (a==-1 && b==1) || (a==1 && b==-1) || (a==1 && b==1)){
								w_check=true;
							}
						}    //ending of bishop

						//for queen
						if(game_array1[new_row][new_col]==-4){
							if((a==-1 && b==0) || (a==0 && b==-1) || (a==0 && b==1) || (a==1 && b==0) ||
							    (a==-1 && b==-1) || (a==-1 && b==1) || (a==1 && b==-1) || (a==1 && b==1)){
								w_check=true;
							}
						}//ending of queen

						//for knight
						if(game_array1[new_row][new_col]==-2){
							if((a==-2 && b==-1) || (a==-2 && b==1) || (a==-1 && b==2) || (a==1 && b==2) ||
							    (a==2 && b==1) || (a==2 && b==-1) || (a==1 && b==-2) || (a==-1 && b==2)){
								w_check=true;
								
							}
						}//ending of knight

						
						//for pawn
						if(game_array1[new_row][new_col]==-6){
							if( (new_row==w_row-1 && new_col==w_col-1) ||(new_row==w_row-1 && new_col==w_col+1)){
								w_check=true;
							}
						}//ending of pawn
					
					break;
				}

				//aafnai goti raicha vney break vara new pair liney
				if(game_array1[new_row][new_col]>0){
					break;}
				if((a==-2 && b==-1) || (a==-2 && b==1) || (a==-1 && b==2) || (a==1 && b==2) ||
							    (a==2 && b==1) || (a==2 && b==-1) || (a==1 && b==-2) || (a==-1 && b==2)){
									break;
								
							}


				new_row+=king_dir.first;
				new_col+=king_dir.second;
			}//end of while loop:


		}//end for white king check checking


		
	window.clear();
	c1.draw_baseboard(window,square);
	




	if(current_side==0 && w_check==true ){
		b_check=false;
		
		return 1;
	}
	else if(current_side==1 && b_check==true){
		// square[w_row][w_col].setFillColor(Color::Red);
		// window.draw(square[w_row][w_col]);
		w_check=false;
		
		return 1;
	}
	else
	{return 0;}
cout<<"never here:";

	c1.set_piece_to_board(window, game_array1,square, tex, sp);
	

}  //ending of this function 



void movement::find_captured_pieces(RenderWindow (&window),vector<vector<int>> &current_possible,
	int(&temp_array)[8][8],int i)
{
	int current_row=current_possible[i][0];
	int current_col=current_possible[i][1];
	if(current_possible[i][3]==-2)//if en passant://white turn;
	{
		current_row++;
	}
	if(current_possible[i][3]==2)//if en passant://black turn:
	{
		current_row--;
	}
	

	if(temp_array[current_row][current_col]<0)
	{
		bcaptured_pieces.push_back(temp_array[current_row][current_col]);
		//std::cout<<bcaptured_pieces[0];
	}
	if(temp_array[current_row][current_col]>0 )
	{
		wcaptured_pieces.push_back(temp_array[current_row][current_col]);

	}
	
}

void movement::show_captured_pieces(RenderWindow (&window))
{
	Texture btex,wtex;
	Sprite bsp,wsp;
	float small_scale =0.666;
	
	
	if(bcaptured_pieces.size()>0)
	{
		//std::cout<<bcaptured_pieces[0];
	for(int x=0;x<bcaptured_pieces.size();x++)
	{
		switch(bcaptured_pieces[x])
	      {
		case -1:       //for black rook
			btex.loadFromFile("../resources/texture/black rook.png");
					
					

			break;
		case -2:      //for black knight
			btex.loadFromFile("../resources/texture/black knight.png");
					
					

			break;
	    case -3:
			btex.loadFromFile("../resources/texture/black bishop.png");
					
			break;

		case -4:
			btex.loadFromFile("../resources/texture/black queen.png");
			break;

		case -6:
			btex.loadFromFile("../resources/texture/black pawn.png");
			break;

	    }

		btex.setSmooth(true);
		bsp.setTexture(btex);
		if(x<4)
		{
			bsp.setPosition(Added_width+640+x*60*small_scale,15*60*small_scale);

		}
		if (x>=4 && x<8)
		{
			int p = x-4;
			bsp.setPosition(Added_width+640+ p*60*small_scale,14*60*small_scale);
		}
		if (x>=8 && x<12)
		{
			int q = x-8;
			bsp.setPosition(Added_width+640+q*60*small_scale,13*60*small_scale);
		}
		if (x>=12 && x<16)
		{
			int r = x-12;
			bsp.setPosition(Added_width+640+r*60*small_scale,12*60*small_scale);
		}

		
		bsp.setScale(small_scale,small_scale);
		window.draw(bsp);

	}
	}

	if(wcaptured_pieces.size()>0)
	{


	for(int y=0;y<wcaptured_pieces.size();y++)
	{
		switch(wcaptured_pieces[y])
	      {
		case 1:       //for black rook
			wtex.loadFromFile("../resources/texture/white rook.png");
					
					

			break;
		case 2:      //for black knight
			wtex.loadFromFile("../resources/texture/white knight.png");
					
					

			break;
	    case 3:
			wtex.loadFromFile("../resources/texture/white bishop.png");
					
			break;

		case 4:
			wtex.loadFromFile("../resources/texture/white queen.png");
			break;

		case 6:
			wtex.loadFromFile("../resources/texture/white pawn.png");
			break;

	    }

		wtex.setSmooth(true);
		wsp.setTexture(wtex);
		if(y<4)
		{
			wsp.setPosition(Added_width+640+y*60*small_scale,0);

		}
		if (y>=4 && y<8)
		{
			int p = y-4;
			wsp.setPosition(Added_width+640+p*60*0.66,60*small_scale);
		}
		if (y>=8 && y<12)
		{
			int q = y-8;
			wsp.setPosition(Added_width+640+q*60*0.66,2*60*small_scale);
		}
		if (y>=12 && y<16)
		{
			int r = y-12;
			wsp.setPosition(Added_width+640+r*60*0.66,3*60*small_scale);
		}

		
		wsp.setScale(small_scale,small_scale);
		window.draw(wsp);

	}

	}
			

				
}