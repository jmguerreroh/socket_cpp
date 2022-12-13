/**
 * @file SereverSocket.hpp
 * @author José Miguel Guerrero Hernández (josemiguel.guerrero@urjc.es)
 * @brief class used to use sockets as a server
 * @version 0.1
 * @date 2022-12-14
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef ServerSocket_class
#define ServerSocket_class

#include "Socket.hpp"

class ServerSocket : private Socket
{
	public:
		/**
		 * @brief Construct a new Server Socket object
		 * 
		 * @param port int port number
		 */
		ServerSocket ( int port );

		/** @brief Construct a new Server Socket object */
		ServerSocket (){};

		/** @brief Destroy the Server Socket object */
		virtual ~ServerSocket();

		/**
		 * @brief overloading the << operator to write to socket
		 * 
		 * @param s string to write
		 * @return const ServerSocket& 
		 */
		const ServerSocket& operator << ( const std::string& s ) const;

		/**
		 * @brief overloading the << operator to read from socket
		 * 
		 * @param s string to read
		 * @return const ServerSocket& 
		 */
		const ServerSocket& operator >> ( std::string& s ) const;

		/**
		 * @brief accept socket
		 * 
		 * @param sock ServerSocket to accept
		 */
		void accept ( ServerSocket& sock);
};

#endif