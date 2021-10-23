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
sf::Socket::Status status = socket.connect("192.168.1.65",53000,t1);
if (status != sf::Socket::Done)
{
    // error...
    std::cout<<"Connection failed, status: "<<status<<endl;
    //std::cout<<"COnnection failed, status: "<<WSAGetLastError()<<std::endl;
    std::cout << "Connection failed" << endl;
            //socket.disconnect();
            return 1;
}

sf::Packet p1;
sf::Uint16 x;

socket.receive(p1);
p1>>x;
	
    cout<<x;
    cin>>x;
//socket.receive(p1);

//p1>>x;
//cout<<endl<<x;
// socket.send(text.c_str(), text.length()+1);
// 	socket.receive(buffer, sizeof(buffer), received);
// 	cout << buffer << endl;
	//system("pause");
return 0;
}