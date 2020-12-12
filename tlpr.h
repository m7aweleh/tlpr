#pragma once

struct results {
	std::vector<cv::Mat> croppedPlates;
	std::vector<std::string> platesOCR;
};

namespace tlpr
{
	results anpr(cv::Mat Image, std::string assetsDir);
}