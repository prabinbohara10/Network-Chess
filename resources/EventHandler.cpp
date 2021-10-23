#include"EventHandler.h"
//passing game window, game_array and base squares:
   void EventHandler:: event_function(RenderWindow &window,int (&game_array)[8][8],RectangleShape (&square)[8][8],int &current_side_to_play)
   {
	   
	   
	   //checking special cases i.e. special movements:
			// 1)castling  2)En passant 3)Check  4)Checkmate  5)
      

		//any event is triggered:
	    while (window.pollEvent(event1)|| (to_trigger_event==true)) {

		   //checking window close event both by mouse click and keyboard press:
		   	if (event1.type == Event::Closed)
				window.close();
			if (event1.type == Event::KeyPressed && event1.key.code == Keyboard::Escape)
				window.close();
			
			
			 

		   //mouse pressed event start:
		   if(event1.type==Event::MouseButtonPressed && event1.mouseButton.button==Mouse::Left || (to_trigger_event==true))
		   {
			int x,y;
            if(to_trigger_event==true)
			{
				x=0;
				y=0;
			}
			else
			{
			//getting x and y when mouse is clicked:
			x = Mouse::getPosition(window).x;
			y = Mouse::getPosition(window).y;
			}
			mouse_pos_x = x;
			mouse_pos_y = y;
			
			//condition is only triggered when clicked within the chess board:
			if (x >= 0 && x <= 800 && y >= 0 && y <= 640) //if inside the board??
			{
				int board_x_lower=160;
				int board_y_lower=0;
				if(x>=board_x_lower)
				{
				row_no = y / 80;
				col_no = (x-Added_width)/ 80;
				
				clicked_piece = game_array[row_no][col_no];
			
				}
				


			

			//if move is successful:
			int move_flag= movement1.is_move_success(window,square,game_array,current_possible,current_side_to_play,row_no, col_no);
			if(move_flag)
			{
				
				gameleftsidescreen(window, mouse_pos_x,mouse_pos_y);
				gamerightsidescreen(window);
				movement1.show_captured_pieces(window);
				window.display();
				
			 return;
			}

		//espically used when playing between two pc:
		//"my_turn" is always set to 1 when played in same pc:	
		if(my_turn==true)
		{
			//checking of white moves in white turn and black moves in black turn:	
			if((current_side_to_play==0 && clicked_piece>=0) || (current_side_to_play==1 && clicked_piece<=0))
			{

			
			
				window.clear();//reset everything by clering window to make different colour for possible moves:
				
				c1.draw_baseboard(window,square);//making baseboard so that other color can fit above this baseboard.
												 //This has initial color black and white.
				
				

				//checks if the clicked square doesn't contain any of the piece
				if(clicked_piece!=0)
				{
				//make the clecked square Blue in color:
				square[row_no][col_no].setFillColor(Color::Blue);
				window.draw(square[row_no][col_no]);
				
				//push clicked row, column and clicked piece to 0th index of current_possible:
					vector<int> temp_vector;
					 temp_vector.push_back(row_no);
					 temp_vector.push_back(col_no);
					 temp_vector.push_back(clicked_piece); //if kills then 1 otherwise 0:
					 current_possible.push_back(temp_vector);
				}

				//call the showpath(possible path) function for respective pieces:
				if (clicked_piece == -6 || clicked_piece == 6) //black or white pawn
				{
					p1.showpath(window, game_array, square, row_no, col_no, clicked_piece,current_possible,current_side_to_play);
				}
				else if (clicked_piece == 1 || clicked_piece == -1)
				{
					r1.showpath(window, game_array, square, row_no, col_no, clicked_piece,current_possible);
				}
				else if (clicked_piece == -2 || clicked_piece == 2)
				{
					n1.showpath(window, game_array, square, row_no, col_no, clicked_piece,current_possible);
				}
				else if (clicked_piece == 3 || clicked_piece == -3)
				{
					b1.showpath(window, game_array, square, row_no, col_no, clicked_piece,current_possible);
				}
				else if (clicked_piece == 4 || clicked_piece == -4)
				{
					q1.showpath(window, game_array, square, row_no, col_no, clicked_piece,current_possible);
				}
				else if (clicked_piece == 5 || clicked_piece == -5)
				{
					k1.showpath(window, game_array, square, row_no, col_no, clicked_piece,current_possible,current_side_to_play);
				}
				else
				{
					//std::cout<<"Invalid piece";
				}

				

			
				
				// placing pieces to the board. making baseboard is already done before.
				//Why making baseboard function is above?
				//just to draw different colours to the squares of possible moves:
					if(b_check==true)
					{
						cout<<"2 ";
					square[b_row][b_col].setFillColor(Color::Red);
					window.draw(square[b_row][b_col]);
					}
					else if(w_check==true)
					{
		 			square[w_row][w_col].setFillColor(Color::Red);
		 			window.draw(square[w_row][w_col]);
					}
					else{}

				c1.set_piece_to_board(window, game_array,square, tex, sp);
				p1.promotion(window, game_array, square, row_no, col_no, clicked_piece,current_possible,current_side_to_play);
				gameleftsidescreen(window, mouse_pos_x,mouse_pos_y);
				gamerightsidescreen(window);
				movement1.show_captured_pieces(window);

			    window.display();
			//else part of "if clicked is on same square:"
			}//end of if (checking if white moves in white turn and black in black turn)
		}//end of if(if my_turn==true)

				

			}//if inside the board??
			

			
			
			



		}//MouseButtonPressed() function
	   }//window polled event1
   }//void forMouseClicked() function:


void EventHandler:: gameleftsidescreen(RenderWindow &window,int x, int y)
{
    
    Texture background1,menu2,bmenu2;
	Sprite sbackground1,smenu2,sbmenu2;
	//background1.loadFromFile("../resources/menu/background2.jpg");
	//background1.setSmooth("true");
	
	//sbackground1.setTexture(background1);
	
	//sp3.setScale(0.5, 0.5);
	//sbackground1.setPosition(0,0);
	menu2.loadFromFile("../resources/menu/menu.png");
	menu2.setSmooth("true");
	smenu2.setTexture(menu2);
	smenu2.setScale(0.75, 0.75);
	smenu2.setPosition(4, 640-smenu2.getGlobalBounds().height-4);
    //bmenu2.loadFromFile("../resources/menu/menubig.png");
	//bmenu2.setSmooth("true");
	//sbmenu2.setTexture(bmenu2);
	//sbmenu2.setScale(0.75,0.75);
	//sbmenu2.setPosition(window.getSize().x - sbmenu2.getGlobalBounds().width, window.getSize().y - sbmenu2.getGlobalBounds().height);
    
    if(smenu2.getGlobalBounds().contains(x,y))
			{
				
				//startmenu startmenu2;
				//startmenu2.mainmenu();
			}
    int mousepos_x = Mouse::getPosition(window).x;
	int mousepos_y = Mouse::getPosition(window).y;
    window.draw(sbackground1);
    if (smenu2.getGlobalBounds().contains(mousepos_x,mousepos_y))
    {
        smenu2.setScale(0.9, 0.9);
        window.draw(smenu2);
		window.display();
		window.close();
		startmenu startmenu1;
		startmenu1.mainmenu();

    }
    if (!smenu2.getGlobalBounds().contains(mousepos_x,mousepos_y))
    {
        
        window.draw(smenu2);
    }
}


void EventHandler:: gamerightsidescreen(RenderWindow &window)
{
	RectangleShape rec1,rec2;
	Texture tex;
	Sprite sp;
	tex.loadFromFile("../resources/menu/captured white pieces.png");
	tex.setSmooth(true);
	sp.setTexture(tex);
	sp.setPosition(Added_width+640,0);
	
	//rec1.setSize(Vector2f(160,160));
	//rec1.setFillColor(Color::Yellow);
	//rec1.setPosition(0,0);
	rec2.setSize(Vector2f(160,160));
	rec2.setFillColor(Color::Yellow);
	rec2.setPosition(Added_width+640,480);
	window.draw(sp);
	window.draw(rec2);

}

