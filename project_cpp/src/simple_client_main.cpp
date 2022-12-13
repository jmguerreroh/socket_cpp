#include "../include/ClientSocket.hpp"
#include "../include/SocketException.hpp"
#include "../include/Draw.hpp"
#include "../include/Utils.hpp"
#include <iostream>
#include <string.h>
#include <vector>
#include <list>

int main ( int argc, char *argv[] )
{
	srand(time(NULL)); 
	Utils utils;

	try
	{
		ClientSocket client_socket ( "localhost", 30000 );

		std::string reply;
		try
		{
			// Send message to server
			client_socket << "client_param1,client_param2,client_param3";

			// Read message from server
			client_socket >> reply;
			std::cout << "We received this response from the server:\n\"" << reply << "\"\n";

			// Tokenize the message
			const char delim = ',';
			std::vector<std::string> vdata;
			utils.tokenize(reply, delim, vdata);
			std::cout << "TOKENIZE --> Data: " ;
			// *** NEW: for auto 
			for (auto &d: vdata) {
				std::cout << d << " - " ;
			}
			std::cout << std::endl;
		}
		catch ( SocketException& ) {}    
	}
	catch ( SocketException& e )
	{
		std::cout << "Exception was caught:" << e.description() << "\n";
	}

	// Draw arrows, these represent the aiplanes and their direction
	Draw dr(500);
	int posx = 0;
	for (int i=0; i<5; i++) {
		dr.drawLine(posx, 0, posx, 100, "A" + std::to_string(i));
		posx += 50;
	}
	// Draw an arrow 
	dr.drawLine(-25, 50, 25, 50, "A" + std::to_string(6));
	dr.show("Map - Server", 1000);
	// Check if A1 and A2, and A1 and A6 intersec
	Point ini_a0(0,0), end_a0(0,100), ini_a1(50,0), end_a1(50,1000), ini_a6(-25,50), end_a6(25,50);
	utils.doIntersect(ini_a0,end_a0,ini_a1,end_a1) ? std::cout << "A0A1 - Yes\n": std::cout << "A0A1 - No\n";
	utils.doIntersect(ini_a0,end_a0,ini_a6,end_a6) ? std::cout << "A0A6 - Yes\n": std::cout << "A0A6 - No\n";

	return 0;
}