#include <iostream>
#include <stdio.h>
#include <opencv2/opencv.hpp>

#ifndef SOMETHING
int funcao(std::string algo);
void Show_Function(cv::Mat content,std::string Name_Screen);
void Print_Content(cv::Mat image);
double Difference_Function(cv::Mat FirstImage, cv::Mat SecondImage);
cv::Mat To_422(cv::Mat image);
cv::Mat To_440(cv::Mat image);
cv::Mat To_420(cv::Mat image);
cv::Mat To_411(cv::Mat image);
#endif // !SOMETHING
