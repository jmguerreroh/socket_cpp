/**
 * @file Point.hpp
 * @author José Miguel Guerrero Hernández (josemiguel.guerrero@urjc.es)
 * @brief a point with XY coordinates
 * @version 0.1
 * @date 2022-12-14
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef Point_class
#define Point_class

#include <iostream>

class Point
{
	public:
		/** @brief Construct a new Point object */
		Point();

		/**
		 * @brief Construct a new Point object
		 * 
		 * @param x 
		 * @param y 
		 */
		Point(int x, int y);

		/**
		 * @brief get x coordinate
		 * 
		 * @return int 
		 */
		int getX();

		/**
		 * @brief get y coordinate
		 * 
		 * @return int 
		 */
		int getY();

		/**
		 * @brief set x coordinate
		 * 
		 * @return int 
		 */
		void setX(int x);

		/**
		 * @brief set y coordinate
		 * 
		 * @return int 
		 */
		void setY(int y);

		/**
		 * @brief set x and y coordinates
		 * 
		 * @param x int x coordinate
		 * @param y int y coordinate
		 */
		void setXY(int x, int y);

		/**
		 * @brief overloading the << operator to get cout to accept a Point object 
		 * 
		 * @param os std::ostream
		 * @param pt Point object
		 * @return std::ostream& with the Point object included
		 */
		friend std::ostream& operator<<(std::ostream& os, const Point& pt);

	private:
		/** @brief x coordinate */
		int x_;

		/** @brief y coordinate */
		int y_;
};

#endif