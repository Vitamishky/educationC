#include <iostream>
#include <filesystem>
#include <chrono>
#include <ctime>

void removeOldFiles(const std::filesystem::path& dir, const std::chrono::system_clock::time_point& cutoffTime) {
    try {
        for (const auto& entry : std::filesystem::directory_iterator(dir)) {
            try {
                auto lastWrite = std::filesystem::last_write_time(entry);
                auto lastWriteTime = std::chrono::system_clock::to_time_t(
                    std::chrono::file_clock::to_sys(lastWrite));
                    
                if (lastWriteTime < std::chrono::system_clock::to_time_t(cutoffTime)) {
                    std::cout << "Deleting: " << entry.path() << " (modififed: " 
                              << std::ctime(&lastWriteTime) << ")";
                    
                    if (std::filesystem::is_directory(entry)) {
                        std::filesystem::remove_all(entry); 
                    } else {
                        std::filesystem::remove(entry);
                    }
                }
            } catch (const std::filesystem::filesystem_error& e) {
                std::cerr << "Error processing " << entry.path() << ": " << e.what() << std::endl;
            }
        }
    } catch (const std::filesystem::filesystem_error& e) {
        std::cerr << "Error access denied: " << e.what() << std::endl;
    }
}

int main() {
    std::string path = "/test_dir";
    int days = 10;

    auto now = std::chrono::system_clock::now();
    auto resultTime = now - std::chrono::hours(24 * days);

    removeOldFiles(path, resultTime);
    
    return 0;
}