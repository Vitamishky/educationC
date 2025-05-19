#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <algorithm>

bool isBlank(const std::string& line) {
    return line.empty() || 
           std::all_of(line.begin(), line.end(), [](char c) { 
               return std::isspace(static_cast<unsigned char>(c)); 
           });
}

void removeBlankLines(const std::string& inputFile, const std::string& outputFile) {
    std::ifstream inFile(inputFile);
    if (!inFile.is_open()) {
        std::cerr << "Error: Could not open input file: " << inputFile << std::endl;
        return;
    }

    std::ofstream outFile(outputFile);
    if (!outFile.is_open()) {
        std::cerr << "Error: Could not create output file: " << outputFile << std::endl;
        inFile.close();
        return;
    }

    std::string line;
    while (std::getline(inFile, line)) {
        if (!isBlank(line)) {
            outFile << line << '\n';
        }
    }

    inFile.close();
    outFile.close();
    std::cout << "Processing complete. Cleaned file saved as: " << outputFile << std::endl;
}

int main() {
    std::string inputPath, outputPath;
    inputPath = "/05/input.txt";
    outputPath = "/05/output.txt";

    removeBlankLines(inputPath, outputPath);

    return 0;
}