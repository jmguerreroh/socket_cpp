#include "../include/ServerSocket.hpp"
#include "../include/SocketException.hpp"
#include "../include/Draw.hpp"
#include "../include/Utils.hpp"
#include <string>
#include <iostream>

int main ( int argc, char *argv[] )
{
	srand(time(NULL)); 
	std::cout << "Server running....\n";

	try
  	{
		// Create the socket
		ServerSocket server ( 30000 );

		while ( true )
		{
			Utils utils;
			ServerSocket new_sock;
			server.accept ( new_sock );
			std::cout << "Conection accepted" << std::endl;
			try
			{
				while ( true )
				{
					// Read message from client
					std::string data;
					new_sock >> data;
					std::cout << "We received this response from the client:\n\"" << data << "\"\n";

					// Tokenize the message
					const char delim = ',';
					std::vector<std::string> vdata;
					utils.tokenize(data, delim, vdata);
					std::cout << "TOKENIZE --> Data: " ;
					// *** NEW: for auto 
					for (auto &d: vdata) {
						std::cout << d << " - " ;
					}
					std::cout << std::endl;

					// Send message to client
					std::string msg = "server_param1,server_param2,server_param3";
					new_sock << msg;
				}
			}
			catch ( SocketException& ) {}
			std::cout << "Conection closed" << std::endl;

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
		}
	}
	catch ( SocketException& e )
	{
		std::cout << "Exception was caught:" << e.description() << "\nExiting.\n";
	}

	return 0;
}