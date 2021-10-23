#include "startmenu.h"
//initializing the global variable:
int white_up_or_down=1; //if down side of board then 1:
int black_up_or_down=0; //if upper side of board then 0 :
bool my_turn=true;


void startmenu::mainmenu()
{
	RenderWindow menu(VideoMode(640, 400), "CHESS", Style::Close | Style::Titlebar);
    //if (!font.loadFromFile("Fonts/Metropolian-Display.ttf"))
	//{
		//jguyhuu
	//}
	//text.setFont(font);
	//text.setFillColor(Color::Blue);
	//text.setString("HELLO");
	//text.setPosition(width/2,height/2);
	background.loadFromFile("../resources/menu/background2.jpg");
	background.setSmooth("true");
	
	sbackground.setTexture(background);
	
	sbackground.setScale(0.5, 0.5);
    menu1.loadFromFile("../resources/menu/menu.png");
	menu1.setSmooth("true");
	smenu1.setTexture(menu1);
	smenu1.setPosition(640 / 2 - smenu1.getGlobalBounds().width/2, 20);
    smenu1.setScale(0.75, 0.75);
	play.loadFromFile("../resources/menu/play.png");
	play.setSmooth("true");
	splay.setTexture(play);
	splay.setPosition(640 / 2 - splay.getGlobalBounds().width/2, 100);
    splay.setScale(0.75, 0.75);
    option.loadFromFile("../resources/menu/option.png");
	option.setSmooth("true");
    soption.setTexture(option);
	soption.setPosition(640 / 2 - soption.getGlobalBounds().width/2 + 10 , 180);
    soption.setScale(0.75, 0.75);
    exit.loadFromFile("../resources/menu/exit.png");
	exit.setSmooth("true");
    sexit.setTexture(exit);
	sexit.setPosition(640 / 2 - sexit.getGlobalBounds().width/2, 260);
    sexit.setScale(0.75, 0.75);
    bplay.loadFromFile("../resources/menu/playbig.png");
	bplay.setSmooth("true");
	sbplay.setTexture(bplay);
	sbplay.setPosition(640 / 2 - sbplay.getGlobalBounds().width/2, 100);
    sbplay.setScale(0.75, 0.75);
    boption.loadFromFile("../resources/menu/optionbig.png");
	boption.setSmooth("true");
    sboption.setTexture(boption);
	sboption.setPosition(640 / 2 - sboption.getGlobalBounds().width/2 + 10 , 180);
    sboption.setScale(0.75, 0.75);
    bexit.loadFromFile("../resources/menu/exitbig.png");
	bexit.setSmooth("true");
    sbexit.setTexture(bexit);
	sbexit.setPosition(640 / 2 - sbexit.getGlobalBounds().width/2, 260);
    sbexit.setScale(0.75, 0.75);


    bcaptured_pieces.clear();
	wcaptured_pieces.clear();
	

	while (menu.isOpen())
	{
		Event ev;
		while (menu.pollEvent(ev))
		{
			if (ev.type == Event::Closed)
				menu.close();
			if (ev.type == Event::KeyPressed && ev.key.code == Keyboard::Escape)
				menu.close();
			if (ev.type == Event::MouseButtonPressed && ev.mouseButton.button == Mouse::Left)
			{
				int x = Mouse::getPosition(menu).x;
				int y = Mouse::getPosition(menu).y;
				if (x >= 0 && x <= 640 && y >= 0 && y <= 400)
				{
					connection(x, y,menu);
				}
			}

		}
		menu.clear();
		draw(menu);
		menu.display();

		
	}


	/*
	if (!font.loadFromFile("Fonts/Metropolian-Display.ttf"))
	{
		//jguyhuu
	}
	text.setFont(font);
	text.setFillColor(Color::Red);
	text.setOutlineThickness(1);
	text.setString("Play");
	text.setPosition(300,100);
	*/

	

}


void startmenu::draw(RenderWindow& menu)
{
	menu.draw(sbackground);
    menu.draw(smenu1);
    int mousepos_x = Mouse::getPosition(menu).x;
	int mousepos_y= Mouse::getPosition(menu).y;
    if(splay.getGlobalBounds().contains(mousepos_x,mousepos_y))
    {
        menu.draw(sbplay);

    }
    if(!splay.getGlobalBounds().contains(mousepos_x,mousepos_y))
    {
        menu.draw(splay);

    }
    if(soption.getGlobalBounds().contains(mousepos_x,mousepos_y))
    {
        menu.draw(sboption);

    }
    if(!soption.getGlobalBounds().contains(mousepos_x,mousepos_y))
    {
        menu.draw(soption);

    }
    if(sexit.getGlobalBounds().contains(mousepos_x,mousepos_y))
    {
        menu.draw(sbexit);

    }
    if(!sexit.getGlobalBounds().contains(mousepos_x,mousepos_y))
    {
        menu.draw(sexit);

    }
}

void startmenu::connection(int x, int y, RenderWindow& menu)
{
	if (splay.getGlobalBounds().contains(x, y))
	{
		//cout << "play" << endl;

		game game1;
		menu.close();
        
	    game1.main_game(5);
       // game2.gamescreen();
		
         //window.close();
	}
    if (sexit.getGlobalBounds().contains(x, y))
	{
		//cout << "play" << endl;
		menu.close();
		game game2;
		game2.network_game(5);

    
		
        
	}
		
}

