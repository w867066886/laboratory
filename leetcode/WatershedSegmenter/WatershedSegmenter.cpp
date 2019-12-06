
#include<stdio.h>
#include<opencv2/opencv.hpp>
#include <opencv2/highgui/highgui_c.h>
using namespace cv;
using namespace std;

int main(int argc, char* argv[]) {

	char input_win[] = "input image";
	char watershed_win[] = "watershed segementation demo";
	Mat src = imread("22303076,1753996735.jpg", -1);
//	resize(src, src, Size(), 0.25, 0.25, 1);
//
//	if (src.empty()) {
//		puts("could not load images");
//		return -1;
//	}
//
//	namedWindow(input_win, CV_WINDOW_AUTOSIZE);
//	imshow(input_win, src);
//
//
//	//1. 将白色背景编程黑色背景 - 目的是为了后面变的变换做准备
//	for (int row = 0; row < src.rows; row++) {
//		for (int col = 0; col < src.cols; col++) {
//			if (src.at<Vec3b>(row, col) == Vec3b(255, 255, 255)) {
//				//我这里和视频教程图片不一样，所以这一步不同
//// 				src.at<Vec3b>(row, col)[0] = 0;
//// 				src.at<Vec3b>(row, col)[1] = 0;
//// 				src.at<Vec3b>(row, col)[2] = 0;
//			}
//		}
//	}
//	namedWindow("black background", CV_WINDOW_AUTOSIZE);
//	imshow("black background", src);
//	imwrite("black background.jpg", src);
//
//
//	//2. 使用filter2D与拉普拉斯算子实现图像对比度的提高 - sharp
//	Mat kernel1 = (Mat_<float>(3, 3) << 1, 1, 1, 1, -8, 1, 1, 1, 1);
//	Mat imgLaplance;
//	Mat imgSharpen;
//	filter2D(src, imgLaplance, CV_32F, kernel1, Point(-1, -1), 0, BORDER_DEFAULT);
//
//	src.convertTo(imgSharpen, CV_32F);
//	Mat imgResult = imgSharpen - imgLaplance;
//	imgResult.convertTo(imgResult, CV_8UC3);
//	imgLaplance.convertTo(imgLaplance, CV_8UC3);
//	imshow("sharpen img", imgResult);
//	imwrite("sharpen img.jpg", imgResult);
//
//
//	//3. 转为二值图像通过threshold
//	Mat imgBinary;
//	cvtColor(imgResult, imgResult, CV_BGR2GRAY);
//	threshold(imgResult, imgBinary, 40, 255, THRESH_BINARY | THRESH_OTSU);
//
//	Mat temp;
//	imgBinary.copyTo(temp, Mat());
//	Mat kernel2 = getStructuringElement(MORPH_RECT, Size(2, 2), Point(-1, -1));
//	morphologyEx(temp, temp, CV_MOP_TOPHAT, kernel2, Point(-1, -1), 1);
//
//	for (int row = 0; row < src.rows; row++) {
//		for (int col = 0; col < src.cols; col++) {
//			imgBinary.at<uchar>(row, col) = saturate_cast<uchar>(imgBinary.at<uchar>(row, col) - temp.at<uchar>(row, col));
//		}
//	}
//
//	imshow("sharpen img", imgResult);
//	imshow("binary img", imgBinary);
//	imwrite("sharpen img2.jpg", imgResult);
//	imwrite("binary.jpg", imgBinary);
//
//
//	//4. 距离变换
//	Mat imgDist;
//	distanceTransform(imgBinary, imgDist, CV_DIST_L1, 3);
//
//
//	//5. 对距离变换结果进行归一化[0-1]之间
//	normalize(imgDist, imgDist, 0, 1, NORM_MINMAX);
//	imshow("distance result normalize", imgDist);
//	imwrite("distance result normalize.jpg", imgDist);
//
//
//	//6. 使用阈值，在此二值化，得到标记
//	threshold(imgDist, imgDist, 0.5, 1, CV_THRESH_BINARY);
//	imshow("distance result threshold", imgDist);
//	imwrite("distance result threshold.jpg", imgDist);
//
//
//	//7. 腐蚀每个peak erode
//	Mat kernel3 = Mat::zeros(15, 15, CV_8UC1);
//	erode(imgDist, imgDist, kernel3, Point(-1, -1), 2);
//	imshow("distance result erode", imgDist);
//	imwrite("distance result erode.jpg", imgDist);
//
//
//	//8. 发现轮廓 findContours
//	Mat imgDist8U;
//	imgDist.convertTo(imgDist8U, CV_8U);
//	vector<vector<Point>> contour;
//	findContours(imgDist8U, contour, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE, Point(0, 0));
//
//
//	//9. 绘制轮廓 drawContours
//	Mat maskers = Mat::zeros(imgDist8U.size(), CV_32SC1);
//	for (size_t i = 0; i < contour.size(); i++) {
//		drawContours(maskers, contour, static_cast<int>(i), Scalar::all(static_cast<int>(i) + 1));
//	}
//	imshow("maskers", maskers);
//	imwrite("maskers.jpg", maskers);
//
//
//	//10.分水岭变换 watershed
//	watershed(src, maskers);
//	Mat mark = Mat::zeros(maskers.size(), CV_8UC1);
//	maskers.convertTo(mark, CV_8UC1);
//	bitwise_not(mark, mark, Mat());
//	imshow("watershed", mark);
//	imwrite("watershed.jpg", mark);
//
//
//	//11.对每个分割区域着色输出结果
//	vector<Vec3b> colors;
//	for (size_t i = 0; i < contour.size(); i++) {
//		int r = theRNG().uniform(0, 255);
//		int g = theRNG().uniform(0, 255);
//		int b = theRNG().uniform(0, 255);
//		colors.push_back(Vec3b((uchar)r, (uchar)g, (uchar)b));
//	}
//
//	Mat dst = Mat::zeros(maskers.size(), CV_8UC3);
//	for (int row = 0; row < src.rows; row++) {
//		for (int col = 0; col < src.cols; col++) {
//			int index = maskers.at<int>(row, col);
//			if (index > 0 && index <= static_cast<int>(contour.size())) {
//				dst.at<Vec3b>(row, col) = colors[index - 1];
//			}
//			else {
//				dst.at<Vec3b>(row, col) = Vec3b(0, 0, 0);
//			}
//		}
//	}
//	imshow("dst", dst);
//	imwrite("dst.jpg", dst);
//
//
//	waitKey();

	return 0;

}

