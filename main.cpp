#include <iostream>
#include <string>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace std;
using namespace cv;

void addRandomNoise(Mat& image, int nPixels, int noiseMagnitude) {
    for (int k = 0; k < nPixels; k++) {
        int j = rand() % image.rows;
        int i = rand() % image.cols;

        if (image.type() == CV_8UC1) {
            uchar pixel_value = image.at<uchar>(j, i);
            int noise = (rand() % (2 * noiseMagnitude + 1)) - noiseMagnitude; // Generate random noise value within [-noiseMagnitude, noiseMagnitude]
            int new_value = pixel_value + noise;

            // Ensure that the new pixel value is within the valid range [0, 255]
            new_value = max(0, min(new_value, 255));

            image.at<uchar>(j, i) = static_cast<uchar>(new_value);
        } else if (image.type() == CV_8UC3) {
            Vec3b pixel_value = image.at<Vec3b>(j, i);
            for (int channel = 0; channel < 3; channel++) {
                int noise = (rand() % (2 * noiseMagnitude + 1)) - noiseMagnitude; // Generate random noise value within [-noiseMagnitude, noiseMagnitude]
                int new_value = pixel_value[channel] + noise;

                // Ensure that the new pixel value is within the valid range [0, 255]
                new_value = max(0, min(new_value, 255));

                image.at<Vec3b>(j, i)[channel] = static_cast<uchar>(new_value);
            }
        }
    }
}

int main() {
    string image_path = "C:\\Users\\Josh\\Downloads\\castle.jpg"; // Adjust to your image path
    int nPixels = 60000; // Number of pixels to add noise to
    int noiseMagnitude = 200; // Adjust the noise magnitude to increase/decrease noise

    Mat image = imread(image_path);

    if (image.empty()) {
        cout << "Error: Could not open or load the image." << endl;
        return 1;
    }

    addRandomNoise(image, nPixels, noiseMagnitude);

    namedWindow("Image with Increased Noise", WINDOW_FREERATIO);
    imshow("Image with Increased Noise", image);
    waitKey(0);

    return 0;
}