#include"game.h"

bool time_to_send_sever=false; 
bool to_trigger_event=false;
//operator overloading for passing packet in array:
sf::Packet& operator <<(sf::Packet& packet, const int(&arr)[8][8])
{
	
    for(int i=0;i<8;i++)
	{
		for(int j=0;j<8;j++)
		 packet<<arr[i][j];
	}
	return packet;
}
sf::Packet& operator >>(sf::Packet& packet, int(&arr)[8][8])
{
	
    for(int i=0;i<8;i++)
	{
		for(int j=0;j<8;j++)
		 packet>>arr[i][j];
	}
	return packet;
}



void game::main_game(int a)
{
	// int game_array[8][8] = {
	//   { -1,-2,-3,-4,-5,-3,-2,-1 },
	//   { -6,-6,-6,-6,-6,-6,-6,-6 },
	//   {  0, 0, 0, 0, 0, 0, 0, 0 },
	//   {  0, 0, 0, 0, 0, 0, 0, 0 },
	//   {  0, 0, 0, 0, 0, 0, 0, 0 },
	//   {  0, 0, 0, 0, 0, 0, 0, 0 },
	//   {  6, 6, 6, 6, 6, 6, 6, 6 },
	//   {  1, 2, 3, 4, 5, 3, 2, 1 }
	// };

	int game_array[8][8] = {
	  { 1,2,3,4,5,3,2,1 },
	  { 6,6,6,6,6,6,6,6 },
	  {  0, 0, 0, 0, 0, 0, 0, 0 },
	  {  0, 0, 0, 0, 0, 0, 0, 0 },
	  {  0, 0, 0, 0, 0, 0, 0, 0 },
	  {  0, 0, 0, 0, 0, 0, 0, 0 },
	  {  -6, -6, -6, -6, -6, -6, -6, -6 },
	  {  -1, -2, -3, -4, -5, -3, -2, -1 }
	};

	// int game_array[8][8]={
	//   { -1,-2,-3,-4,-5,-3,0,-1 },
	//   { -6,6,-6,-6,-6,-6,6,-6 },
	//   {  0, 0, 0, 0, 0, 0, 0, 0 },
	//   {  0, 0, 0, 0, 0, 0, 0, 0 },
	//   {  0, 0, -6, 4, 0, 0, 0, 0},
	//   {  0, 0, 0, 0, 0, 0, 0, 0 },
	//   {  -1, -6, 0, 0, 6, 0,-6, 6 },
	//   {  1, 0, 3, 4, 5, 0, 0, 1 }
	// };

	RectangleShape square[8][8];   //for board
	Texture tex;       //for pieces img
	Sprite sp;         //for displaying those images


	RenderWindow window(VideoMode(Added_width+800, 640), "THE BOARD", Style::Close | Style::Titlebar);
	window.setFramerateLimit(60); 

	chessboard chessboard1;
	
    //initial clear:
	window.clear();
	
	//initial drawing the board in starting position:
	chessboard1.draw_baseboard(window, square);
	chessboard1.set_piece_to_board(window, game_array,square, tex, sp);

	//for handling events: EventHandler class
	EventHandler eventhandler1;
	eventhandler1.gameleftsidescreen(window,0,0);
	eventhandler1.gamerightsidescreen(window);
	//display the initial postion board:
	window.display();


	//initilizing other variables:
	
	

	//main game loop:
	while (window.isOpen()) {
		
		//Event handler section:
		
		
		eventhandler1.event_function(window,game_array,square,current_side_to_play);

		

	}

}//end of main_game function:


void game::network_game(int a)
{

    sf::Time t1 = sf::seconds(5.0f); //to set time limit for connecting to the sever:
    sf::TcpSocket socket;
    sf::Socket::Status status = socket.connect("192.168.1.65",53000);
    if (status != sf::Socket::Done) //if connection fails:
    {
        // error...
        std::cout<<"Connection failed, status: "<<status<<endl;
        //std::cout<<"COnnection failed, status: "<<WSAGetLastError()<<std::endl;
        std::cout << "Connection failed" << endl;
            //socket.disconnect();
    }
    else //if connection succeed:
    {
        sf::Packet packet1;
        socket.receive(packet1);
        int game_array[8][8];
        packet1>>game_array>>white_up_or_down>>my_turn;//no need to send "black_up_or_down" since it's complement of "white_up_or_down" 
        black_up_or_down=!white_up_or_down;
        packet1.clear();     
        time_to_send_sever=false;  

        RectangleShape square[8][8];   //for board
	    Texture tex;       //for pieces img
	    Sprite sp;         //for displaying those images
        RenderWindow window(VideoMode(Added_width+800, 640), "THE BOARD", Style::Close | Style::Titlebar);
	    window.setFramerateLimit(60); 
        chessboard chessboard1;
        //initial clear:
	    window.clear();
	    //initial drawing the board in starting position:
	    chessboard1.draw_baseboard(window, square);
	    chessboard1.set_piece_to_board(window, game_array,square, tex, sp);
        //for handling events: EventHandler class
	    EventHandler eventhandler1;
	    eventhandler1.gameleftsidescreen(window,0,0);
	    eventhandler1.gamerightsidescreen(window);
	    //display the initial postion board:
	    window.display();
        
		
        bool request_connection;
		bool response_connection=false;
    
	//main game loop:
	while (window.isOpen()) 
	{
		to_trigger_event=false;

	    packet1.clear();
        socket.receive(packet1);
        packet1>>request_connection;
        packet1.clear();  

		

		if(request_connection==true)
	   {
		std:: cout<<"connection";
	    packet1.clear();
        socket.receive(packet1);
        packet1>>game_array>>my_turn>>current_side_to_play;
		to_trigger_event=true;
        packet1.clear();  
        request_connection=false;
		std:: cout<<"end";
	   }

		if(time_to_send_sever==true)
		{
		response_connection=true;
		time_to_send_sever=false;
		my_turn=false;
		}

		packet1.clear();
		packet1<<response_connection;
		socket.send(packet1);
		packet1.clear();
	  

		if(response_connection==true)
		{
		packet1.clear();
		packet1<<game_array;
		socket.send(packet1);
		packet1.clear();
		response_connection=false;
		}
		
		
		 
            
		
        
//cout<<"2 :";
     
		//cout<<"3 :";
		
		eventhandler1.event_function(window,game_array,square,current_side_to_play);

		}//end of while loop: "window.isOpen()":

    }

    

}//end of network_game function: