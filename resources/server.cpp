#include<iostream>
#include <SFML/Network.hpp>
#include<string>

using namespace std;


int main()
{

string text = "connet to : ";
	char buffer[2000];
	size_t received;
sf::TcpListener listener;

// bind the listener to a port
if (listener.listen(53000) != sf::Socket::Done)
{
    // error...
	cout << "Error listening port 53000" << endl;
            return 1;
}

// accept a new connection
sf::TcpSocket client;
if (listener.accept(client) != sf::Socket::Done)
{
    // error...
	 cout << "Client not accepted" << endl;
            return 1;
}

client.send(text.c_str(), text.length()+1);
	client.receive(buffer, sizeof(buffer), received);
	cout << buffer << endl;
	system("pause");

return 0;
}