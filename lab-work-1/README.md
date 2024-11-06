● 			Image Processing in C++
●Stenyashin Danil Vladislavovich, 24.B81-mm
●st128493@student.spbu.ru
# 			sDescription

This project implements image processing for BMP files in C++. The program performs the following operations:

    Loading a BMP image.
    Rotating the image 90° clockwise.
    Rotating the image 90° counterclockwise.
    Applying a Gaussian filter to the image for smoothing.

The program uses the standard C++ library and doesn't rely on any external dependencies.
Project Structure

The project consists of several files:

    bmp.h — Header file for working with BMP images.
    bmp.cpp — Implementation of functions for loading and saving BMP images.
    image_processing.h — Header file for image processing (rotation, filtering).
    image_processing.cpp — Implementation of functions for rotating images and applying Gaussian filters.
    main.cpp — Main file with the entry point of the program, performing all operations.

How to Run the Project
Prerequisites:

    Ensure that you have a C++ compiler installed (e.g., g++).
    You are working in an environment with access to a terminal (Linux, macOS, or Windows).

Steps to Compile and Run:

    Clone or download the repository:

git clone https://github.com/Danil-Stenyashin/HomeAssignments.git


Compile the program:

	make


Run the program:

	./main

    After running the program, it will:
        Rotate the image 90° clockwise and save the result to output_clockwise.bmp.
        Rotate the image 90° counterclockwise and save the result to output_counterclockwise.bmp.
        Apply a Gaussian filter to the image and save the result to output_gaussian.bmp.

    Make sure you have a bmp image file in the same directory as the executable.

Notes:

    The program works with BMP images (24 bits per pixel).
    The image rotations maintain the original image dimensions.
    The Gaussian filter is applied with a kernel size of 5x5 and sigma value of 1.0.

File Structure:

image-processing/
├── bmp.h              // Header file for BMP
├── bmp.cpp            // BMP file handling functions
├── image_processing.h // Header file for image processing
├── image_processing.cpp // Functions for image rotation and Gaussian filtering
├── main.cpp           // Main entry point of the program
└── input.bmp          // Input BMP image

