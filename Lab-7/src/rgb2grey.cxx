/**
********************************************************************************
*
*	@file		rgb2grey.cxx
*
*	@brief		A program to convert a RGB image in a greyscale image using OpenCV.
*
*	@version	1.0
*
*	@date		20/01/2020
*
*	@author		Franck Vidal
*
*
********************************************************************************
*/


//******************************************************************************
//	Includes
//******************************************************************************
#include <exception> // Header for catching exceptions
#include <iostream>  // Header to display text in the console
#include <opencv2/opencv.hpp> // Main OpenCV header


//******************************************************************************
//	Namespaces
//******************************************************************************
using namespace std;


//-----------------------------
int main(int argc, char** argv)
//-----------------------------
{
    try
    {
        // No file to display
        // No file to save
        if (argc != 3)
        {
            // Create an error message
            std::string error_message;
            error_message  = "usage: ";
            error_message += argv[0];
            error_message += " <input_image> <output_image>";

            // Throw an error
            throw error_message;
        }

        // Write your own code here
        // Load Image
        cv::Mat image = cv::imread(argv[1], CV_LOAD_IMAGE_GRAYSCALE);

        // Convert to greyscale
        cv::Mat grey_image;
        cv::cvtColor(image, grey_image, CV_RGB2GRAY);

        // Save Image
        if(!cv::imwrite(argv[2], grey_image)) {
            std::string error_message = "Could not write image to path: ";
            error_message += argv[2];
            throw error_message;
        }

    }
    // An error occured
    catch (const std::exception& error)
    {
        // Display an error message in the console
        cerr << error.what() << endl;
    }
    catch (const std::string& error)
    {
        // Display an error message in the console
        cerr << error << endl;
    }
    catch (const char* error)
    {
        // Display an error message in the console
        cerr << error << endl;
    }

	// Do not close the prompt window
#if defined(WIN32) && defined(_DEBUG)
	system("pause");
#endif

    // Exit the program
    return 0;
}

