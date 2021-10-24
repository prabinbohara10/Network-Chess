#include<iostream>
#include <SFML/Network.hpp>
#include<string>
using namespace std;

sf::TcpListener listener1;
sf::TcpSocket client1;
sf::TcpSocket client2;
string con_text = "Hi client1 11";

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

//reverse game_array and copy to temp_array:
void reverse_array(int (&temp_array)[8][8], int (&game_array)[8][8])
{
	for(int i=0;i<8;i++)
	{
		for(int j=0;j<8;j++)
		  {  temp_array[i][j]=game_array[7-i][7-j];  }
	}
	
	
}


int initial_connection()
{


	// bind the listener to a port
if (listener1.listen(53000) != sf::Socket::Done)       		  //listener:
{ // error...
	cout << "Error listening port 53000" << endl;
            return 1;
}
else 
{
	cout<<"sucess listening"<<endl;
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


//for client1 to initialize:
int game_array1[8][8] = {
	  { -1,-2,-3,-4,-5,-3,-2,-1 },
	  { -6,-6,-6,-6,-6,-6,-6,-6 },
	  {  0, 0, 0, 0, 0, 0, 0, 0 },
	  {  0, 0, 0, 0, 0, 0, 0, 0 },
	  {  0, 0, 0, 0, 0, 0, 0, 0 },
	  {  0, 0, 0, 0, 0, 0, 0, 0 },
	  {  6, 6, 6, 6, 6, 6, 6, 6 },
	  {  1, 2, 3, 4, 5, 3, 2, 1 }
	};
int white=1; 
int black=0; //black up and white down:
bool turn=false;
sf::Packet packet1;
packet1.clear();
packet1<<game_array1<<white<<turn;//no need to send "black" since it's complement of "white"
client1.send(packet1);
packet1.clear();


//for client2 to initilize:
int game_array2[8][8] = {
	  { 1,2,3,4,5,3,2,1 },
	  { 6,6,6,6,6,6,6,6 },
	  {  0, 0, 0, 0, 0, 0, 0, 0 },
	  {  0, 0, 0, 0, 0, 0, 0, 0 },
	  {  0, 0, 0, 0, 0, 0, 0, 0 },
	  {  0, 0, 0, 0, 0, 0, 0, 0 },
	  {  -6, -6, -6, -6, -6, -6, -6, -6 },
	  {  -1, -2, -3, -4, -5, -3, -2, -1 }
	};
white=0; 
black=1;//white up and black down:
turn=false;
sf::Packet packet2;
packet2.clear();
packet2<<game_array2<<white<<turn;//no need to send "black" since it's complement of "white"
client2.send(packet2);
packet2.clear();


bool request_connection1=true;
bool request_connection2=false;
bool response_connection1;
bool response_connection2;

while(1)
{
	packet1.clear();
	packet1<<request_connection1;
	client1.send(packet1);
	packet1.clear();

	packet2.clear();
	packet2<<request_connection2;
	client2.send(packet2);
	packet2.clear();


	if(request_connection1==true)
	{
		cout<<"request_connection to 1:  "<<endl;
	packet1.clear();
	packet1<<game_array1<<true<<0;
	client1.send(packet1);
	packet1.clear();
	request_connection1=false;
	}

	if(request_connection2==true)
	{
		cout<<"request_connection to 2:  "<<endl;
	packet2.clear();
	packet2<<game_array2<<true<<1;
	client2.send(packet2);
	packet2.clear();
	request_connection2=false;
	}

	//receiving mode:
	packet1.clear();
    client1.receive(packet1);
    packet1>>response_connection1;
    packet1.clear();  

	packet2.clear();
    client2.receive(packet2);
    packet2>>response_connection2;
    packet2.clear(); 

	if(response_connection1==true)
    {
		cout<<"response_connection from 1:  "<<endl;
	    packet1.clear();
        client1.receive(packet1);
        packet1>>game_array1;
        packet1.clear();  
        response_connection1=false;
		reverse_array(game_array2,game_array1);
		request_connection2=true;
	}

	
	
 
	
	

	
	if(response_connection2==true)
    {
		cout<<"response_connection from 2:  "<<endl;
	    packet2.clear();
        client2.receive(packet2);
        packet2>>game_array2;
        packet2.clear();  
        response_connection2=false;
		reverse_array(game_array1,game_array2);
		request_connection1=true;
	}
}//end of while loop:



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