/**
********************************************************************************
*
*	@file		meanFilter.cpp
*
*	@brief		A program to perform the mean filter using OpenCV
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
#include <cstdlib>   // Header for atoi and atof
#include <exception> // Header for catching exceptions
#include <iostream>  // Header to display text in the console
#include <opencv2/opencv.hpp> // Main OpenCV header


//******************************************************************************
//	Namespaces
//******************************************************************************
using namespace std;


//******************************************************************************
//	Global variables
//******************************************************************************


//******************************************************************************
//	Function declaration
//******************************************************************************


//******************************************************************************
//	Implementation
//******************************************************************************


//-----------------------------
int main(int argc, char** argv)
//-----------------------------
{
    try
    {
        // No file to display
        // No file to save
        if (argc != 3 && argc != 4)
        {
            // Create an error message
            std::string error_message;
            error_message  = "usage: ";
            error_message += argv[0];
            error_message += " <input_image>  <output_image> <kernel_radius>";

            // Throw an error
            throw error_message;
        }

        // Filter radius
        unsigned int radius(1);

        if (argc == 4)
        {
            radius = atoi(argv[3]);
        }
    
        // Write your own code here
        // Load Image
        cv::Mat image = cv::imread(argv[1], CV_LOAD_IMAGE_GRAYSCALE);

        // Create filter
        int ksize = atoi(argv[3])*2+1;
        cv::Size filter_size(ksize, ksize);

        // blur image
        cv::Mat blurred_image;
        cv::blur(image, blurred_image, filter_size);

        // Save Image
        if(!cv::imwrite(argv[2], blurred_image)) {
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

