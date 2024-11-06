# Image Processing in C++

### Stenyashin Danil Vladislavovich, 24.B81-mm

### st128493@student.spbu.ru

## Description

This project implements image processing for BMP files in C++. The program performs the following operations:

- Loading a BMP image.
- Rotating the image 90° clockwise.
- Rotating the image 90° counterclockwise.
- Applying a Gaussian filter to the image for smoothing.

The program uses the standard C++ library.

---

## Project Structure

The project consists of several files:

- **`bmp.h`** — Header file for working with BMP images.
- **`bmp.cpp`** — Implementation of functions for loading and saving BMP images.
- **`image_processing.h`** — Header file for image processing (rotation, filtering).
- **`image_processing.cpp`** — Implementation of functions for rotating images and applying Gaussian filters.
- **`main.cpp`** — Main file with the entry point of the program, performing all operations.

---

## How to Run the Project

### Prerequisites:

1. Ensure that you have a C++ compiler installed (`g++`).
2. You are working in an environment with access to a terminal.

### Steps to Compile and Run:

1. Clone or download the repository:

   ```bash
   
   git clone https://github.com/your-username/image-processing.git

   ```

2. Compile the program:
   - For Linux/macOS:

     ```bash
     
     make
     
     ```


3. Run the program:
   - For Linux:

     ./main
     
4. After running the program, it will:
   - Rotate the image 90° clockwise and save the result to `output_clockwise.bmp`.
   - Rotate the image 90° counterclockwise and save the result to `output_counterclockwise.bmp`.
   - Apply a Gaussian filter to the image and save the result to `output_gaussian.bmp`.

   Make sure you have a bmp image file in the same directory as the executable.

---

## Notes:

- The program works with BMP images (24 bits per pixel).
- The image rotations maintain the original image dimensions.
- The Gaussian filter is applied with a kernel size of 5x5 and sigma value of 1.0.

---

## File Structure:

```
image-processing/
├── bmp.h              // Header file for BMP
├── bmp.cpp            // BMP file handling functions
├── image_processing.h // Header file for image processing
├── image_processing.cpp // Functions for image rotation and Gaussian filtering
├── main.cpp           // Main entry point of the program
└── input.bmp          // Input BMP image
```

---



## Conclusion

This project demonstrates basic image processing operations on BMP files in C++, including rotations and Gaussian filtering. It can serve as a foundation for developing more complex image processing applications.

---

Let me know if you need any further modifications!


