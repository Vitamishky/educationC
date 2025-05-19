#include <iostream>
#include <vector>
#include <sstream>
#include <iomanip>

std::string bytesToString(const std::vector<uint8_t>& bytes) {
    std::ostringstream oss;
    
    oss << std::hex << std::uppercase << std::setfill('0');
    
    for (uint8_t byte : bytes)
        oss << std::setw(2) << static_cast<int>(byte);
    
    return oss.str();
}

int main() {
    std::vector<uint8_t> data = {0xBA, 0xAD};
    std::string hexStr = bytesToString(data);
    
    std::cout << hexStr << std::endl;
    
    return 0;
}
