/**
 * @file SocketException.hpp
 * @author José Miguel Guerrero Hernández (josemiguel.guerrero@urjc.es)
 * @brief socket exception class
 * @version 0.1
 * @date 2022-12-14
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef SocketException_class
#define SocketException_class

#include <string>

class SocketException
{
	public:
		/**
		 * @brief Construct a new Socket Exception object
		 * 
		 * @param s string exception error
		 */
		SocketException ( std::string s ) : m_s ( s ) {};

		/** @brief Destroy the Socket Exception object */
		~SocketException (){};

		/**
		 * @brief get exception error
		 * 
		 * @return std::string exception error
		 */
		std::string description() { return m_s; }

	private:
		/** @brief string exception error */
		std::string m_s;
};

#endif