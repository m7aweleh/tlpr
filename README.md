# tlpr library

## usage:
Staticaly link the library to your software and use the namespace `tlpr` and call the function `anpr` as it is shown in the example.

### example
```
#include <fstream>
#include <sstream>
#include <iostream>
#include <opencv2/dnn.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
`
#include "tlpr.h"

int main()
{
	cv::Mat img = cv::imread("C:/dev/tlpr/bin/x64/Debug/testtst.JPG", cv::IMREAD_COLOR);
	results values;
	std::string assetsDir = "C:/dev/tlpr/bin/x64/Debug/assetsDir";
	values = tlpr::anpr(img, assetsDir);

	cv::imshow("Display window", values.croppedPlates[0]);
	std::cout << values.platesOCR[0] << std::endl;

	int k = cv::waitKey(0);
	std::cin.get();
}
```

### results
the results are returned as a struccture defined in the `tlpr.h` file
```
struct results {
	std::vector<cv::Mat> croppedPlates;
	std::vector<std::string> platesOCR;
};
```

the `croppedPLates` vector contains a vector of opencv mat objects each one is for a plate found in the input frame.
the `platesOCR` vector contains the OCR results for each of the plates in the `croppedPLates` vector.

## Information
compiled using `arm-hisiv500-linux-g++` compiler with C++11 standard.

## Dependencies
tesseract 4.1.1 [GitHub](https://github.com/tesseract-ocr/tesseract)
OpenCV 4.4.0 [GitHub](https://github.com/opencv/opencv)
