#include "pawn.h"
//test for pull:

void pawn::showpath(RenderWindow& window, int(&board)[8][8], RectangleShape(&square)[8][8], int row,
  int col, int piece, vector<vector<int>> &current_possible,int &current_side)
{
	piece1.is_en_passant(square,board,current_possible,current_side,row,col);
	if (piece == 6) //if white pawn:
	{
		if (row == 6) //if white pawn is in second rank:
		{
			for (int i = 1;i < 3;i++)
			{
				if (board[row - i][col] == 0) {
					square[row - i][col].setFillColor(Color::Cyan);
					
					piece1.copy_to_2dvector(square,current_possible,row-i,col,0,0);
					window.draw(square[row - i][col]);
				}
				else
					break;
			}
		}
		else {
			for (int i = 1;i < 2;i++)
			{
				if (board[row - i][col] == 0) {

					square[row - i][col].setFillColor(Color::Cyan);
					piece1.copy_to_2dvector(square,current_possible,row-i,col,0,0);
					window.draw(square[row - i][col]);
				}


			}
		}


		if (board[row - 1][col - 1] < 0 || board[row - 1][col + 1] < 0) {
			//square[row - 1][col].setFillColor(Color::Cyan);
			//window.draw(square[row - 1][col]);
			if (board[row - 1][col - 1] < 0 && (row - 1) >= 0 && (col - 1) >= 0)
			{
				square[row - 1][col - 1].setFillColor(Color::Red);
				piece1.copy_to_2dvector(square,current_possible,row-1,col-1,1,0);
				window.draw(square[row - 1][col - 1]);
			}


			if (board[row - 1][col + 1] < 0 && (row - 1) >= 0 && (col + 1) <= 7)
			{
				square[row - 1][col + 1].setFillColor(Color::Red);
				piece1.copy_to_2dvector(square,current_possible,row-1,col+1,1,0);
				window.draw(square[row - 1][col + 1]);

			}


		}
		

	}

	if (piece == -6)
	{
		if (row == 1)
		{
			for (int i = 1;i < 3;i++)
			{
				if (board[row + i][col] == 0) {

					square[row + i][col].setFillColor(Color::Cyan);
					piece1.copy_to_2dvector(square,current_possible,row+i,col,0,0);
					window.draw(square[row + i][col]);
				}
				else
					break;



			}
		}
		else {
			for (int i = 1;i < 2;i++)
			{
				if (board[row + i][col] == 0) {

					square[row + i][col].setFillColor(Color::Cyan);
					piece1.copy_to_2dvector(square,current_possible,row+i,col,0,0);
					window.draw(square[row + i][col]);
				}


			}
		}
		//for displaying replacable piece
		if (board[row + 1][col - 1] > 0 || board[row + 1][col + 1] > 0) {

			if (board[row + 1][col - 1] > 0 && (row + 1) <= 7 && (col - 1) >= 0)
			{
				square[row + 1][col - 1].setFillColor(Color::Red);
				piece1.copy_to_2dvector(square,current_possible,row+1,col-1,1,0);
				window.draw(square[row + 1][col - 1]);
			}


			if (board[row + 1][col + 1] > 0 && (row + 1) <= 7 && (col + 1) <= 7)
			{
				square[row + 1][col + 1].setFillColor(Color::Red);
				piece1.copy_to_2dvector(square,current_possible,row+1,col+1,1,0);
				window.draw(square[row + 1][col + 1]);

			}
			

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
void pawn::promotion(RenderWindow& window, int(&board)[8][8], RectangleShape(&square)[8][8], int row,
  int col, int piece, vector<vector<int>> &current_possible,int &current_side)
{
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
				if(piece==6 && row==0 || piece==-6 && row==7)
				{
					if(piece==6 && row==0)
					{

                        prtex.loadFromFile("../resources/texture/white rook.png");
						prtex.setSmooth(true);
			            prsp.setTexture(prtex);
						prsp.setScale(0.65,0.65);
                        prsp.setPosition(Added_width+col*80,0);
						pktex.loadFromFile("../resources/texture/white knight.png");
						pktex.setSmooth(true);
			            pksp.setTexture(pktex);
					    pksp.setScale(0.65,0.65);
                        pksp.setPosition(Added_width+col*80+60*0.65,0);
						pbtex.loadFromFile("../resources/texture/white bishop.png");
						pbtex.setSmooth(true);
		                pbsp.setTexture(pbtex);
						pbsp.setScale(0.65,0.65);
                        pbsp.setPosition(Added_width+col*80,60*0.65);
						pqtex.loadFromFile("../resources/texture/white queen.png");
					    pqtex.setSmooth(true);
			            pqsp.setTexture(pqtex);
						pqsp.setScale(0.65,0.65);
                        pqsp.setPosition(Added_width+col*80+60*0.65,60*0.65);	
						//window.draw(square[row][col]);	

					    window.draw(prsp);
						window.draw(pksp);
						window.draw(pbsp);
						window.draw(pqsp);

						//else{
						//	window.draw(square[row][col]);

						//}

					}
					if(piece==-6 && row==7)
					{

                        prtex.loadFromFile("../resources/texture/black rook.png");
						prtex.setSmooth(true);
			            prsp.setTexture(prtex);
						prsp.setScale(0.65,0.65);
                        prsp.setPosition(Added_width+col*80,row*80);
						pktex.loadFromFile("../resources/texture/black knight.png");
						pktex.setSmooth(true);
			            pksp.setTexture(pktex);
					    pksp.setScale(0.65,0.65);
                        pksp.setPosition(Added_width+col*80+60*0.65,row*80);
						pbtex.loadFromFile("../resources/texture/black bishop.png");
						pbtex.setSmooth(true);
		                pbsp.setTexture(pbtex);
						pbsp.setScale(0.65,0.65);
                        pbsp.setPosition(Added_width+col*80,row*80+60*0.65);
						pqtex.loadFromFile("../resources/texture/black queen.png");
					    pqtex.setSmooth(true);
			            pqsp.setTexture(pqtex);
						pqsp.setScale(0.65,0.65);
                        pqsp.setPosition(Added_width+col*80+60*0.65,row*80+60*0.65);	
						//window.draw(square[row][col]);	

					    window.draw(prsp);
						window.draw(pksp);
						window.draw(pbsp);
						window.draw(pqsp);
					}
				}
			
			}
		}


}


