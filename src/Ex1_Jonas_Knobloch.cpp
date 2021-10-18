#include<opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main() {
    Mat img = imread("../stereo.jpg");

    cout << "input: " << img.size() << endl;

    Range rows = Range(0, img.size().height);
    Range colsL = Range(0, img.size().width / 2);
    Range colsR = Range(img.size().width / 2, img.size().width);

    Mat left = img(rows, colsL);
    Mat right = img(rows, colsR);

    cout << "left: " << left.size() << endl;
    cout << "right: " << right.size() << endl;

    vector<Mat> channelsL(3);
    vector<Mat> channelsR(3);

    split(left, channelsL);
    split(right, channelsR);

    vector<Mat> channelsA(3);

    channelsA[0] = channelsR[0];
    channelsA[1] = channelsR[1];
    channelsA[2] = channelsL[2];

    Mat anaglyph;
    merge(channelsA, anaglyph);

    namedWindow("left", 1);
    namedWindow("right", 1);
    namedWindow("anaglyph", 1);

    imshow("left", left);
    imshow("right", right);
    imshow("anaglyph", anaglyph);

    waitKey(0);
}