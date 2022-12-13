/**
 * @file Draw.hpp
 * @author José Miguel Guerrero Hernández (josemiguel.guerrero@urjc.es)
 * @brief draw a radar and airplanes using OpenCV
 * @version 0.1
 * @date 2022-12-14
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef Draw_class
#define Draw_class

#include "Point.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include <string.h>
#include <iostream>

class Draw 
{
	public:
		/** @brief Construct a new Draw object */
		Draw();

		/**
		 * @brief Construct a new Draw object
		 * 
		 * @param tam size
		 */
		Draw(int tam);

		/** @brief Destroy the Draw object */
		~Draw();

		/**
		 * @brief draw a line using XY coordinates of initial and final points, and write a text close to final point
		 * 
		 * @param p1x x coordinate of the initial point
		 * @param p1y y coordinate of the initial point
		 * @param p2x x coordinate of the final point
		 * @param p2y x coordinate of the final point
		 * @param text string to write close to the final point
		 */
		void drawLine(int p1x, int p1y, int p2x, int p2y, std::string text);

		/**
		 * @brief show radar during a time
		 * 
		 * @param title string name of the window
		 * @param time int time in milliseconds
		 */
		void show(std::string title, int time);

	private:
		/** @brief OpenCV image used to draw */
		cv::Mat area_;

		/** @brief radar image size */
		int tam_;

		/** @brief draw radar lines over a black image */
		void drawRadar();
};

#endif