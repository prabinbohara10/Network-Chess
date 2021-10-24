#include"check.h"

bool check::isCheckmate2(int game_arr[8][8],int current_side_to_play)
{
	int temp_arr[8][8];
	for(int i=0;i<8;i++)
	{
		std::cout<<"value of i : "<<i<<endl;
		for(int j=0;j<8;j++)
		temp_arr[i][j]=game_arr[i][j];
	}

    int (&game_array)[8][8] = temp_arr;
    
	
	RectangleShape square[8][8];   //for board
	RenderWindow window(VideoMode(0, 0), "THE BOARD", Style::Close | Style::Titlebar);
	


    for(int i=0;i<8;i++)
    {
        for(int j=0;j<8;j++)
        {
			int row_no=i;
			int col_no=j;
            int selected_piece=game_array[i][j];
			std::cout<<"selected piece : "<<selected_piece<<endl;

		 if((current_side_to_play==0 && selected_piece>=0) || (current_side_to_play==1 && selected_piece<=0))
		  {
			
			//push clicked row, column and clicked piece to 0th index of current_possible:
			vector<int> temp_vector;
	     	temp_vector.push_back(row_no);
			temp_vector.push_back(col_no);
			temp_vector.push_back(selected_piece); //if kills then 1 otherwise 0:
			current_possible.push_back(temp_vector);

            //call the showpath(possible path) function for respective pieces:
				if (selected_piece == -6 || selected_piece == 6) //black or white pawn
				{
					p1.showpath(window, game_array, square, row_no, col_no, selected_piece,current_possible,current_side_to_play);
				}
				else if (selected_piece == 1 || selected_piece == -1)
				{
					r1.showpath(window, game_array, square, row_no, col_no, selected_piece,current_possible);
				}
				else if (selected_piece == -2 || selected_piece == 2)
				{
					n1.showpath(window, game_array, square, row_no, col_no, selected_piece,current_possible);
				}
				else if (selected_piece == 3 || selected_piece == -3)
				{
					b1.showpath(window, game_array, square, row_no, col_no, selected_piece,current_possible);
				}
				else if (selected_piece == 4 || selected_piece == -4)
				{
					q1.showpath(window, game_array, square, row_no, col_no, selected_piece,current_possible);
				}
				else if (selected_piece == 5 || selected_piece == -5)
				{
					k1.showpath(window, game_array, square, row_no, col_no, selected_piece,current_possible,current_side_to_play);
				}
				else
				{
					//std::cout<<"Invalid piece";
				}


			if(current_possible.size()>1)
			{
				for(int i=1;i<current_possible.size();i++)
				{
					int current_row=current_possible[i][0];
					int current_col=current_possible[i][1];
					check check1;
					int move_flag= check1.is_move_success2(window,square,game_array,current_possible,current_side_to_play,
							current_row, current_row);
					
					if(move_flag==101) //successful move
					{
						std::cout<<"no checkmate"<<endl;
						return false;
					}
				}
				current_possible.clear();
			}

		 }

        }//end of loop: j
    }//end of loop: i
	std::cout<<"yes checkmate"<<endl;
	return true;

}//end of function isCheckmate():


void check::king_position2(int (&game_array1)[8][8],int (&king_pos)[2][2])
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

void check::copy_2d_array2(int (&destination_arr)[8][8],int (&src_arr)[8][8])
{
	for(int i=0;i<8;i++)
	{
		for(int j=0;j<8;j++)
		{
			destination_arr[i][j]=src_arr[i][j];
		}
	}
}

int check::is_move_success2(RenderWindow (&window),RectangleShape (&square)[8][8],int(&game_array)[8][8],
        vector<vector<int>> &current_possible, int &current_side,int current_row,int current_col)
{
    //to check if the clicked_square is present in the current_possible vector:
			if(current_possible.size()>1)
			{
				for(int i=1;i<current_possible.size();i++)
				{
				  if(current_possible[i][0]==current_row && current_possible[i][1]==current_col)
					{
						king_position2(game_array,king_pos);
						int temp_array[8][8];
						//to copy game_array to temp_arr:
						copy_2d_array2(temp_array,game_array);
					
					
							//need_to_show_possible_moves=0;
							int parent_row=current_possible[0][0];
							int parent_col=current_possible[0][1];
							//game_array[parent_row][parent_col]=0;
							//game_array[current_row][current_col]=current_possible[0][2];
							
							//if move is promotion
							if(  ( (white_up_or_down==1)&&  ((temp_array[parent_row][parent_col]==6 && current_row==0) ||
									 (temp_array[parent_row][parent_col]==-6 && current_row==7 )) )
								|| ( (white_up_or_down==0)&&  ((temp_array[parent_row][parent_col]==6 && current_row==7) ||
									 (temp_array[parent_row][parent_col]==-6 && current_row==0 )) )   )
							{

								//promotion_move(temp_array,current_possible,i);
 
							}
							else
							{
								
								temp_array[parent_row][parent_col]=0;
								
								temp_array[current_row][current_col]=current_possible[0][2];

							}

							
    
                            //if the move is castling:
					    	int castling_row=((current_side!=white_up_or_down) ? 7 :0);
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
							//if(current_piece_moved==6 || current_piece_moved==-6)
							  // { possible_en_passant(temp_array,current_possible,i);}


							
							//checks if there is check or not for current move:
							//move successful:
							int abc=find_check2(temp_array,window,square,current_side);
							if(!abc)
							{
								
								return 101;//success:
							}
							
					
				  }
					
				}
			}

			
}//end of function: is_move_success()


//promotion move:
void check::promotion_move2(int (&temp_array)[8][8],vector<vector<int>> &current_possible,int i)
{
	int parent_row=current_possible[0][0];
    int parent_col=current_possible[0][1];
	int current_row=current_possible[i][0];
    int current_col=current_possible[i][1];
	
int a = current_col;
int b = current_row;

//start of if white is down and black is up:
if(white_up_or_down==1 && black_up_or_down==0)
{
	if (temp_array[parent_row][parent_col] == 6 && current_row == 0) {

  //std::cout<<"yes"<<std::endl;

  if (mouse_pos_x > (Added_width + a * 80) && mouse_pos_x < (Added_width + a * 80 + 60 * 0.65) && mouse_pos_y > (b * 80) && mouse_pos_y < (b * 80 + 60 * 0.65)) {
    temp_array[current_row][current_col] = 1;

  } else if (mouse_pos_x > (Added_width + a * 80 + 60 * 0.65) && mouse_pos_x < (Added_width + a * 80 + 60 * 0.65 * 2) && mouse_pos_y > (b * 80) && mouse_pos_y < (b * 80 + 60 * 0.65)) {
    temp_array[current_row][current_col] = 2;
  } else if (mouse_pos_x > (Added_width + a * 80) && mouse_pos_x < (Added_width + a * 80 + 60 * 0.65) && mouse_pos_y > (b * 80 + 60 * 0.65) && mouse_pos_y < (b * 80 + 60 * 0.65 * 2)) {
    temp_array[current_row][current_col] = 3;
  } else if (mouse_pos_x > (Added_width + a * 80 + 60 * 0.65) && mouse_pos_x < (Added_width + a * 80 + 60 * 0.65 * 2) && mouse_pos_y > (b * 80 + 60 * 0.65) && mouse_pos_y < (b * 80 + 60 * 0.65 * 2)) {
    temp_array[current_row][current_col] = 4;
  } else {}
  temp_array[parent_row][parent_col] = 0;

}

if (temp_array[parent_row][parent_col] == -6 && current_row == 7) {

  //std::cout<<"yes"<<std::endl;

  if (mouse_pos_x > (Added_width + a * 80) && mouse_pos_x < (Added_width + a * 80 + 60 * 0.65) && mouse_pos_y > (b * 80) && mouse_pos_y < (b * 80 + 60 * 0.65)) {
    temp_array[current_row][current_col] = -1;

  } else if (mouse_pos_x > (Added_width + a * 80 + 60 * 0.65) && mouse_pos_x < (Added_width + a * 80 + 60 * 0.65 * 2) && mouse_pos_y > (b * 80) && mouse_pos_y < (b * 80 + 60 * 0.65)) {
    temp_array[current_row][current_col] = -2;
  } else if (mouse_pos_x > (Added_width + a * 80) && mouse_pos_x < (Added_width + a * 80 + 60 * 0.65) && mouse_pos_y > (b * 80 + 60 * 0.65) && mouse_pos_y < (b * 80 + 60 * 0.65 * 2)) {
    temp_array[current_row][current_col] = -3;
  } else if (mouse_pos_x > (Added_width + a * 80 + 60 * 0.65) && mouse_pos_x < (Added_width + a * 80 + 60 * 0.65 * 2) && mouse_pos_y > (b * 80 + 60 * 0.65) && mouse_pos_y < (b * 80 + 60 * 0.65 * 2)) {
    temp_array[current_row][current_col] = -4;
  } else {}
  temp_array[parent_row][parent_col] = 0;

}
}//end of if white is down and black is up:



//start of if white is up and black is down:
if(white_up_or_down==0 && black_up_or_down==1)
{
	if (temp_array[parent_row][parent_col] == -6 && current_row == 0) {

  //std::cout<<"yes"<<std::endl;

  if (mouse_pos_x > (Added_width + a * 80) && mouse_pos_x < (Added_width + a * 80 + 60 * 0.65) && mouse_pos_y > (b * 80) && mouse_pos_y < (b * 80 + 60 * 0.65)) {
    temp_array[current_row][current_col] = -1;

  } else if (mouse_pos_x > (Added_width + a * 80 + 60 * 0.65) && mouse_pos_x < (Added_width + a * 80 + 60 * 0.65 * 2) && mouse_pos_y > (b * 80) && mouse_pos_y < (b * 80 + 60 * 0.65)) {
    temp_array[current_row][current_col] = -2;
  } else if (mouse_pos_x > (Added_width + a * 80) && mouse_pos_x < (Added_width + a * 80 + 60 * 0.65) && mouse_pos_y > (b * 80 + 60 * 0.65) && mouse_pos_y < (b * 80 + 60 * 0.65 * 2)) {
    temp_array[current_row][current_col] = -3;
  } else if (mouse_pos_x > (Added_width + a * 80 + 60 * 0.65) && mouse_pos_x < (Added_width + a * 80 + 60 * 0.65 * 2) && mouse_pos_y > (b * 80 + 60 * 0.65) && mouse_pos_y < (b * 80 + 60 * 0.65 * 2)) {
    temp_array[current_row][current_col] = -4;
  } else {}
  temp_array[parent_row][parent_col] = 0;

}

if (temp_array[parent_row][parent_col] == 6 && current_row == 7) {

  //std::cout<<"yes"<<std::endl;

  if (mouse_pos_x > (Added_width + a * 80) && mouse_pos_x < (Added_width + a * 80 + 60 * 0.65) && mouse_pos_y > (b * 80) && mouse_pos_y < (b * 80 + 60 * 0.65)) {
    temp_array[current_row][current_col] = 1;

  } else if (mouse_pos_x > (Added_width + a * 80 + 60 * 0.65) && mouse_pos_x < (Added_width + a * 80 + 60 * 0.65 * 2) && mouse_pos_y > (b * 80) && mouse_pos_y < (b * 80 + 60 * 0.65)) {
    temp_array[current_row][current_col] = 2;
  } else if (mouse_pos_x > (Added_width + a * 80) && mouse_pos_x < (Added_width + a * 80 + 60 * 0.65) && mouse_pos_y > (b * 80 + 60 * 0.65) && mouse_pos_y < (b * 80 + 60 * 0.65 * 2)) {
    temp_array[current_row][current_col] = 3;
  } else if (mouse_pos_x > (Added_width + a * 80 + 60 * 0.65) && mouse_pos_x < (Added_width + a * 80 + 60 * 0.65 * 2) && mouse_pos_y > (b * 80 + 60 * 0.65) && mouse_pos_y < (b * 80 + 60 * 0.65 * 2)) {
    temp_array[current_row][current_col] = 4;
  } else {}
  temp_array[parent_row][parent_col] = 0;

}
}//end of if white is up and black is down:



}//end of promotion move function:







int check :: find_check2(int(&game_array1)[8][8],RenderWindow (&window),RectangleShape (&square)[8][8],
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
	//c1.draw_baseboard(window,square);
	
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
//cout<<"never here:";

	//c1.set_piece_to_board(window, game_array1,square, tex, sp);
	

} //ending of this function 



void check::game_over_window()
{
	cout<<"hhhhh";
	RenderWindow window(VideoMode(Added_width+800, 640), "THE BOARD", Style::Close | Style::Titlebar);
	window.setFramerateLimit(60);

	CircleShape shape(5.f);

	Texture background,play,exit,option,menu1,bplay,boption,bexit;
	Sprite sbackground, splay, soption, sexit,smenu1,sbplay,sboption,sbexit;
	window.clear();
	 menu1.loadFromFile("../resources/menu/game_over.png");
	menu1.setSmooth("true");
	smenu1.setTexture(menu1);
	smenu1.setPosition(640 / 2 - smenu1.getGlobalBounds().width/2, 20);
    smenu1.setScale(0.75, 0.75);
	
	window.draw(shape);
	window.draw(smenu1);
	window.display();

	

	while (window.isOpen())
	{
		Event ev;
		while (window.pollEvent(ev))
		{
			if (ev.type == Event::Closed)
				window.close();
			if (ev.type == Event::KeyPressed && ev.key.code == Keyboard::Escape)
				window.close();
			if (ev.type == Event::MouseButtonPressed && ev.mouseButton.button == Mouse::Left)
			{
			}

		}
	}
}//end of function: