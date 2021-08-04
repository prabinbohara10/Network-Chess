#include <SFML/Network.hpp>
#include<string>
#include<iostream>
using namespace std;
using namespace sf;
int main()
{
    sf::IpAddress ip = sf::IpAddress::getPublicAddress();
    sf::IpAddress ip2 = sf::IpAddress::getLocalAddress();

    cout<<ip<<endl;
    string text = "connet to : ";
	char buffer[2000];
	size_t received;
    sf::Time t1 = sf::seconds(5.0f);

sf::TcpSocket socket;
sf::Socket::Status status = socket.connect("192.168.1.67",7000,t1);
if (status != sf::Socket::Done)
{
    // error...
    std::cout<<"Connection failed, status: "<<status<<endl;
    //std::cout<<"COnnection failed, status: "<<WSAGetLastError()<<std::endl;
    std::cout << "Connection failed" << endl;
            socket.disconnect();
            return 1;
}

socket.send(text.c_str(), text.length()+1);
	socket.receive(buffer, sizeof(buffer), received);
	cout << buffer << endl;
	system("pause");
return 0;
}