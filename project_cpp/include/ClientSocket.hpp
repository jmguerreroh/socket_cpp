/**
 * @file ClientSocket.hpp
 * @author José Miguel Guerrero Hernández (josemiguel.guerrero@urjc.es)
 * @brief class used to use sockets as a client
 * @version 0.1
 * @date 2022-12-14
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef ClientSocket_class
#define ClientSocket_class

#include "Socket.hpp"

class ClientSocket : private Socket
{
	public:
		/**
		 * @brief Construct a new Client Socket object
		 * 
		 * @param host string ip address
		 * @param port int port number
		 */
		ClientSocket ( std::string host, int port );

		/** @brief Destroy the Client Socket object */
		virtual ~ClientSocket(){};

		/**
		 * @brief overloading the << operator to write to socket
		 * 
		 * @param s string to write
		 * @return const ClientSocket& 
		 */
		const ClientSocket& operator << ( const std::string& s ) const;
		
		/**
		 * @brief overloading the << operator to read from socket
		 * 
		 * @param s string to read
		 * @return const ClientSocket& 
		 */
		const ClientSocket& operator >> ( std::string& s ) const;
};

#endif