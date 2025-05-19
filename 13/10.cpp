#include <iostream>
#include <filesystem>
#include <string>
#include <algorithm>

void renameFilesInDirectory(const std::filesystem::path& directory) {
    try {
        std::cout << "Processing directory: " << directory << std::endl;

        for (const auto& entry : std::filesystem::directory_iterator(directory)) {
            if (entry.is_regular_file()) {
                std::string filename = entry.path().filename().string();
                
                std::string newFilename = filename;
                std::transform(newFilename.begin(), newFilename.end(),
                              newFilename.begin(), ::tolower);
                
                if (newFilename != filename) {
                    std::filesystem::path newPath = entry.path();
                    newPath.replace_filename(newFilename);
                    
                    try {
                        std::filesystem::rename(entry.path(), newPath);
                        std::cout << "Renamed: " << filename 
                                  << " -> " << newFilename << std::endl;
                    } catch (const std::filesystem::filesystem_error& e) {
                        std::cerr << "Error renaming " << filename 
                                  << ": " << e.what() << std::endl;
                    }
                } else {
                    std::transform(newFilename.begin(), newFilename.end(),
                                newFilename.begin(), ::toupper);
                    
                    std::filesystem::path newPath = entry.path();
                    newPath.replace_filename(newFilename);
                    
                    try {
                        std::filesystem::rename(entry.path(), newPath);
                        std::cout << "Renamed: " << filename 
                                  << " -> " << newFilename << std::endl;
                    } catch (const std::filesystem::filesystem_error& e) {
                        std::cerr << "Error renaming " << filename 
                                  << ": " << e.what() << std::endl;
                    }
                }
            }
        }
    } catch (const std::filesystem::filesystem_error& e) {
        std::cerr << "Directory error: " << e.what() << std::endl;
    }
}

int main() {
    std::string path = "/test_dir";

    renameFilesInDirectory(path);
    std::cout << "Operation completed." << std::endl;

    return 0;
}