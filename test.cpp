#include <src/include/SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }



    //       Texture t1;
    // if(!t1.loadFromFile("img.png"))
    // {
    //     std::cout<<"error to load"<<std::endl;
    // }

    // Sprite sp;
    // sp.setTexture(t1);
    

        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}