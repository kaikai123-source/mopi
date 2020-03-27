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

			int bilateralFilterVal = 30;  // ˫��ģ��ϵ��
			imshow("scr", src);
			GaussianBlur(src, src, Size(9, 9), 0, 0); // ��˹ģ����������������
			bilateralFilter(src, matResult, bilateralFilterVal, // ����ĥƤ
				bilateralFilterVal * 2, bilateralFilterVal / 2);

			Mat matFinal;

			// ͼ����ǿ��ʹ�÷����ڱΣ�Unsharpening Mask��������
			cv::GaussianBlur(matResult, matFinal, cv::Size(0, 0), 9);
			cv::addWeighted(matResult, 1.5, matFinal, -0.5, 0, matFinal);
			imshow("result", matFinal);

		}
		waitKey(30);
	}

}