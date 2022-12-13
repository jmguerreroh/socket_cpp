#include "../include/Draw.hpp"

void Draw::drawRadar()
{
	// Draw center, circles and lines
	cv::Scalar color( 0, 100, 0);
	cv::line( area_, cv::Point(0, tam_/2), cv::Point(tam_, tam_/2), color, 1, cv::LINE_AA ); // Horizontal
	cv::line( area_, cv::Point(tam_/2, 0), cv::Point(tam_/2, tam_), color, 1, cv::LINE_AA ); // Vertical
	int max_radius = tam_/2;
	for (int i = 20; i < max_radius; i+= 20)
		cv::circle(area_, cv::Point(tam_/2,tam_/2), i, color, 1); // Circles
}

Draw::Draw() 
{
	tam_ = 200;
	area_ = cv::Mat(tam_, tam_, CV_8UC3, cv::Scalar(0, 0, 0)); 
	drawRadar();
}

Draw::Draw(int tam)
{
	tam_ = tam;
	area_ = cv::Mat(tam_, tam_, CV_8UC3, cv::Scalar(0, 0, 0)); 
	drawRadar();
}

Draw::~Draw() 
{}

void Draw::drawLine(int p1x, int p1y, int p2x, int p2y, std::string text)
{
	cv::Point pt1(p1x+(tam_/2), -p1y+(tam_/2)), pt2(p2x+(tam_/2), -p2y+(tam_/2));
	cv::Scalar color( rand()&255, rand()&255, rand()&255 );
	cv::arrowedLine( area_, pt1, pt2, color, 3, cv::LINE_AA );
	cv::putText(area_, text, cv::Point(pt2.x+5,pt2.y+5), cv::FONT_HERSHEY_DUPLEX, 0.5, color, 1, false);
}

void Draw::show(std::string title, int time)
{
	cv::imshow(title, area_);
	cv::waitKey(time);
}