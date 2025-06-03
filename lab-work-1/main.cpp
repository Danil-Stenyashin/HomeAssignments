#include <iostream>
#include <chrono>
#include <vector>
#include "bmp.h"
#include "image_processing.h"

template<typename Func>
void measure_time(const std::string& operation_name, Func&& operation) {
    auto start = std::chrono::high_resolution_clock::now();
    operation();
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    std::cout << "[TIME] " << operation_name << ": " << duration.count() << " ms\n";
}

void run_test(const std::string& inputFile, bool parallel) {
    std::cout << "\n=== Running test (" << (parallel ? "PARALLEL" : "SEQUENTIAL") << " version) ===\n";

    std::string suffix = parallel ? "_parallel" : "_sequential";
    std::string outputRotateR = "output_clockwise" + suffix + ".bmp";
    std::string outputRotateL = "output_counterclockwise" + suffix + ".bmp";
    std::string outputFileGaussian = "output_gaussian" + suffix + ".bmp";

    BMPImage bmpImage(inputFile, parallel);
    measure_time("Image loading", [&]() {
        if (bmpImage.getPixels().empty()) {
            std::cerr << "Failed to load image!" << std::endl;
            exit(1);
        }
    });

    const DIBHeader& dibHeader = bmpImage.getDIBHeader();
    std::vector<Pixel> pixels = bmpImage.getPixels();
    std::vector<Pixel> result;

    unsigned num_threads = parallel ? std::thread::hardware_concurrency() : 1;
    
    measure_time("Clockwise rotation", [&]() {
        rotate90Clockwise(dibHeader.width, dibHeader.height, pixels, result, num_threads);
    });
    bmpImage.setPixels(result);
    bmpImage.saveBMP(outputRotateR);

    measure_time("Counter-clockwise rotation", [&]() {
        rotate90CounterClockwise(dibHeader.width, dibHeader.height, pixels, result, num_threads);
    });
    bmpImage.setPixels(result);
    bmpImage.saveBMP(outputRotateL);

    measure_time("Gaussian blur", [&]() {
        std::vector<float> kernel = gaussianKernel(5, 1.0f);
        applyGaussianFilterToImage(pixels, dibHeader.width, dibHeader.height, 
                                result, kernel, 5, num_threads);
    });
    bmpImage.setPixels(result);
    bmpImage.saveBMP(outputFileGaussian);
}

int main() {
    std::cout << "Enter input file name: ";
    std::string inputFile;
    std::cin >> inputFile;

    run_test(inputFile, false);  
    run_test(inputFile, true);  

    std::cout << "\n=== Testing completed ===" << std::endl;
    return 0;
}
