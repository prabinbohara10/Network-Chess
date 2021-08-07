#include<iostream>
#include <SFML/Network.hpp>
#include<string>
using namespace std;

sf::TcpListener listener1;
sf::TcpSocket client1;
sf::TcpSocket client2;
string con_text = "Hi client1 11";

int initial_connection()
{
	// bind the listener to a port
if (listener1.listen(53000) != sf::Socket::Done)       		  //listener:
{ // error...
	cout << "Error listening port 53000" << endl;
            return 1;
}
else 
{cout<<"sucess listening"<<endl;
}

cout<<"\n1111\n";

// accept a new connection

while(1)
{
	cout<<"1";
if (client1.getRemoteAddress() == sf::IpAddress::None)
{
	if (listener1.accept(client1) != sf::Socket::Done)         //accepts client1:
	{// error...
	 cout << "Client1 not accepted" << endl;
            return 1;
	}
	else
	{cout<<"client1 accepted";
 	//client1.send(con_text.c_str(), con_text.length()+1);
	 break;
	}
//client1.disconnect();
}


//client2 started:
else if(client2.getRemoteAddress() == sf::IpAddress::None)
{
	if (listener1.accept(client2) != sf::Socket::Done)			//accepts client2:
	{// error...
	 cout << "Client2 not accepted" << endl;
            return 1;
	}
	else
	{cout<<"client2 accepted";
  	break;
	}

}

else{}

}//end of while:
}//function end: initial_connection()


int check_connection()
{

}

int main()
{

int a=initial_connection();
string text = "connect to : ";
	char buffer[2000];
	size_t received;






while(0)
{
	string disconnect_msg="Other player disconneted from server.";
  if(client1.getRemoteAddress() == sf::IpAddress::None)  //if client1 disconnects:
  {
	  client2.send(disconnect_msg.c_str(), disconnect_msg.length()+1);
	  client2.disconnect();
  }
  if(client2.getRemoteAddress() == sf::IpAddress::None)  //if client1 disconnects:
  {
	  client1.send(disconnect_msg.c_str(), disconnect_msg.length()+1);
	  client1.disconnect();
  }
  
  //cout << buffer << endl;
}
cout<<"\n2222\n";

sf::Packet packet1;

sf::Uint16 x;
cout<<"Enter the value od x: ";
cin>>x;
while(1)
{
packet1 <<x;

client1.send(packet1);
packet1.clear();
x++;
if(x==10)
break;
}

//client1.send(text.c_str(), text.length()+1);
// 	client1.receive(buffer, sizeof(buffer), received);
//   cout << buffer << endl;
system("pause");




// listener2.setBlocking(true);
// // bind the listener to a port
// if (listener2.listen(7000) != sf::Socket::Done)
// {
//     // error...
// 	cout << "Error listening port 53000" << endl;
//             return 1;
// }
// else 
// {
// 	cout<<"sucess listening"<<endl;
// }
// //}//end of while:
// cout<<"\n1111\n";

// // accept a new connection
// sf::TcpSocket client2;
// if (listener2.accept(client2) != sf::Socket::Done)
// {
//     // error...
// 	 cout << "Client2 not accepted" << endl;
//             return 1;
// }
// else
// {

//  cout<<"client2 accepted";
// }
// cout<<"\n2222\n";

// client2.send(text.c_str(), text.length()+1);
// 	client2.receive(buffer, sizeof(buffer), received);
// 	cout << buffer << endl;
// 	system("pause");


return 0;
}