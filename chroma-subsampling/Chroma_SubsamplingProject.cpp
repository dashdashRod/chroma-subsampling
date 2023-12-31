﻿// Chroma_SubsamplingProject.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
//

#include <iostream>
#include "Subsampling.h"
#include <stdlib.h>
#include <opencv2/opencv.hpp>

using namespace cv;
int main()
{
	std::string File_Name = "Hollywood.bmp";
	Mat content = imread(File_Name);
	Mat resultado = To_422(content);
	Mat Final;
	Mat Resultado_traduzido;
	cvtColor(content, Final, COLOR_BGR2YCrCb);
	cvtColor(resultado, Resultado_traduzido, COLOR_YCrCb2BGR);
	imshow("Original", content);
	imshow("Resultado", Resultado_traduzido);
	waitKey(0);
	destroyAllWindows();
	std::cout << "Image compatibility is equal to: " << (100.0 - Difference_Function(resultado, Final)) << std::endl;
	return 0;
}
