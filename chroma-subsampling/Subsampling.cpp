#include <stdio.h>
#include <iostream>
#include <opencv2/opencv.hpp>
#include "Subsampling.h"

using namespace std;
using namespace cv;

int funcao(String File_Name) {
	Mat algo = imread(File_Name);
	if (algo.empty()) {
		cout << "File name nao encontrado" << endl;
	}
	else {
		imshow("FIGURA", algo);
		waitKey(0);
		destroyWindow("FIGURA");
	}
	return 0;
}

void Show_Function(cv::Mat content,std::string Name_Screen) {
	if (content.empty()) {
		cout << "Empty file" << endl;
		return;
	}
	else {
		imshow(Name_Screen, content);
		waitKey(0);
		destroyWindow(Name_Screen);
	}
}

void Print_Content(cv::Mat image) {
	Size s = image.size();
	for (int i = 0; i < s.width; i++)
	{
		for (int y = 0; y < s.height; y++)
		{
			cout << image.at<Vec3b>(y,i) << endl;
		}
	}
	cout << "Final Size: X: " << s.height << " Y: " << s.width << endl;
}

double Difference_Function(cv::Mat FirstImage,cv::Mat SecondImage) {
	Size s;
	double dif_counter = 0;
	if (FirstImage.empty() == true || SecondImage.empty() == true) {
		cout << "One of the images are empty" << endl;
		return -1;
	}
	else if (FirstImage.size().width != SecondImage.size().width || FirstImage.size().height != SecondImage.size().height) {
		cout << "Images of different Dimensions, Finishing code" << endl;
		return -2;
	}
	s = FirstImage.size();
	for (int x = 0; x < s.width; x++) {
		for (int y = 0; y < s.height; y++) {
			if (FirstImage.at<Vec3b>(y, x) != SecondImage.at<Vec3b>(y, x)) {
				dif_counter++;
			}
		}
	}
	//cout << "Dif_counter: " << dif_counter << endl;
	return (dif_counter / (s.width * s.height)) * 100;
}

cv::Mat To_422(cv::Mat image) {
	cv::Mat new_image;
	cv::cvtColor(image, new_image, COLOR_BGR2YCrCb);
	Size s = new_image.size();
	for (int x = 0; x < s.width; x++)
	{
		for (int y = 0; y < s.height; y=y+2)
		{
			if (y + 1 < s.height) {
				new_image.at<Vec3b>(y + 1, x)[1] = new_image.at<Vec3b>(y, x)[1];
				new_image.at<Vec3b>(y + 1, x)[2] = new_image.at<Vec3b>(y, x)[2];
			}
		}
	}
	return new_image;
}

cv::Mat To_440(cv::Mat image) {
	cv::Mat new_image;
	cv::cvtColor(image, new_image, COLOR_BGR2YCrCb);
	Size s = new_image.size();
	for (int x = 0; x < s.width; x=x+2)
	{
		for (int y = 0; y < s.height; y++)
		{
			if (x + 1 < s.width) {
				new_image.at<Vec3b>(y, x+1)[1] = new_image.at<Vec3b>(y, x)[1];
				new_image.at<Vec3b>(y, x+1)[2] = new_image.at<Vec3b>(y, x)[2];
			}
		}
	}
	return new_image;
}


cv::Mat To_420(cv::Mat image) {
	cv::Mat new_image;
	cv::cvtColor(image, new_image, COLOR_BGR2YCrCb);
	Size s = new_image.size();
	for (int x = 0; x < s.width; x = x + 2)
	{
		for (int y = 0; y < s.height; y = y + 2)
		{
			if (x + 1 < s.width) {
				new_image.at<Vec3b>(y, x + 1)[1] = new_image.at<Vec3b>(y, x)[1];
				new_image.at<Vec3b>(y, x + 1)[2] = new_image.at<Vec3b>(y, x)[2];
				new_image.at<Vec3b>(y+1, x)[1] = new_image.at<Vec3b>(y, x)[1];
				new_image.at<Vec3b>(y+1, x)[2] = new_image.at<Vec3b>(y, x)[2];
				new_image.at<Vec3b>(y + 1, x+1)[1] = new_image.at<Vec3b>(y, x)[1];
				new_image.at<Vec3b>(y + 1, x+1)[2] = new_image.at<Vec3b>(y, x)[2];
			}
		}
	}
	return new_image;
}

cv::Mat To_411(cv::Mat image) {
	cv::Mat new_image;
	cv::cvtColor(image, new_image, COLOR_BGR2YCrCb);
	Size s = new_image.size();
	for (int x = 0; x < s.width; x++)
	{
		for (int y = 0; y < s.height; y++)
		{
			if (y % 4 != 0) {
				new_image.at<Vec3b>(y, x)[1] = new_image.at<Vec3b>(y - 1, x)[1];
				new_image.at<Vec3b>(y, x)[2] = new_image.at<Vec3b>(y - 1, x)[2];
			}
		}
	}
	return new_image;
}





