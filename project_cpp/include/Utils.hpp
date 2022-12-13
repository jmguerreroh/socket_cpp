/**
 * @file Utils.hpp
 * @author José Miguel Guerrero Hernández (josemiguel.guerrero@urjc.es)
 * @brief generic and useful functions
 * @version 0.1
 * @date 2022-12-14
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef Utils_class
#define Utils_class

#include "Point.hpp"
#include <string.h>
#include <iostream>
#include <vector>

class Utils 
{
	public:
		/**
		 * @brief divide a string in tokens using a character
		 * 
		 * @param str string to divide
		 * @param delim char used as delimitator
		 * @param out vector containing the strings
		 */
		void tokenize(std::string const &str, const char delim, std::vector<std::string> &out);

		/**
		 * @brief checks if point q lies on line segment 'pr'
		 * 
		 * @param p point
		 * @param q point
		 * @param r point
		 * @return true: point q lies on line segment 'pr'
		 * @return false point q do not lie on line segment 'pr'
		 */
		bool onSegment(Point p, Point q, Point r);

		/**
		 * @brief to find orientation of ordered triplet (p, q, r)
		 * 
		 * @param p point
		 * @param q point
		 * @param r point
		 * @return int: 0 --> p, q and r are collinear | 1 --> Clockwise | 2 --> Counterclockwise
		 */
		int orientation(Point p, Point q, Point r);

		/**
		 * @brief the main function that returns true if line segment 'p1q1' and 'p2q2' intersect.
		 * 
		 * @param p1 initial point of line 1
		 * @param q1 final point of line 1
		 * @param p2 initial point of line 2
		 * @param q2 final point of line 2
		 * @return true if line segment 'p1q1' and 'p2q2' intersect
		 * @return false if line segment 'p1q1' and 'p2q2' do not intersect
		 */
		bool doIntersect(Point p1, Point q1, Point p2, Point q2);
};

#endif