/**
 * @file Socket.hpp
 * @author José Miguel Guerrero Hernández (josemiguel.guerrero@urjc.es)
 * @brief generic socket class 
 * @version 0.1
 * @date 2022-12-14
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef Socket_class
#define Socket_class

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>
#include <string>
#include <arpa/inet.h>

const int MAXHOSTNAME = 200;
const int MAXCONNECTIONS = 5;
const int MAXRECV = 500;

class Socket
{
	public:
		/** @brief Construct a new Socket object */
		Socket();

		/** @brief Destroy the Socket object */
		virtual ~Socket();

		// Server initialization
		/**
		 * @brief create a socket
		 * 
		 * @return true success
		 * @return false error
		 */
		bool create();

		/**
		 * @brief associates the socket with its local address
		 * 
		 * @param port int port number
		 * @return true success
		 * @return false error
		 */
		bool bind ( const int port );

		/**
		 * @brief prepare to accept connections on socket 
		 * 
		 * @return true success
		 * @return false error
		 */
		bool listen() const;
		
		/**
		 * @brief await a connection on socket
		 * 
		 * @param new_socket 
		 * @return true success
		 * @return false error
		 */
		bool accept ( Socket& new_socket ) const;

		// Client initialization
		/**
		 * @brief open a connection on socket
		 * 
		 * @param host string ip address
		 * @param port int port number
		 * @return true success
		 * @return false error
		 */
		bool connect ( const std::string host, const int port );

		// Data Transimission
		/**
		 * @brief write to socket
		 * 
		 * @param s string to write to socket
		 * @return true success
		 * @return false error
		 */
		bool send ( const std::string s ) const;

		/**
		 * @brief read from socket
		 * 
		 * @param s string to read from socket
		 * @return int the number read or -1 for errors
		 */
		int recv ( std::string& s ) const;

		/**
		 * @brief set the non blocking object
		 * 
		 * @param b bool if you set the non blocking object
		 */
		void set_non_blocking ( const bool b );

		/**
		 * @brief if socket is valid
		 * 
		 * @return true socket is valid
		 * @return false socket is not valid
		 */
		bool is_valid() const { return m_sock != -1; }

	private:
		/** @brief int socket */
		int m_sock;

		/** @brief sockaddr_in address */
		sockaddr_in m_addr;
};

#endif