#include<opencv2\opencv.hpp>
#include<iostream>

using namespace cv;
using namespace std;

int main() {


	VideoCapture cap;
	cap.open(0);
	while (1) {
		Mat src;
		bool sucess = cap.read(src);
		if (sucess) {
			Mat matResult;

			int bilateralFilterVal = 30;  // 双边模糊系数
			imshow("scr", src);
			GaussianBlur(src, src, Size(9, 9), 0, 0); // 高斯模糊，消除椒盐噪声
			bilateralFilter(src, matResult, bilateralFilterVal, // 整体磨皮
				bilateralFilterVal * 2, bilateralFilterVal / 2);

			Mat matFinal;

			// 图像增强，使用非锐化掩蔽（Unsharpening Mask）方案。
			cv::GaussianBlur(matResult, matFinal, cv::Size(0, 0), 9);
			cv::addWeighted(matResult, 1.5, matFinal, -0.5, 0, matFinal);
			imshow("result", matFinal);

		}
		waitKey(30);
	}

}