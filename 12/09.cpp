#include <iostream>
#include <string>

std::string refactoringString(const std::string& str) {
    if (str.empty()) 
        return "";

    std::string compressed;
    char currentLetter = str[0];
    int count = 1;

    for (size_t i = 1; i < str.size(); ++i)
        if (str[i] == currentLetter)
            ++count;
        else {
            compressed += currentLetter + std::to_string(count);
            currentLetter = str[i];
            count = 1;
        }

    compressed += currentLetter + std::to_string(count);
    return compressed;
}

int main() {
    std::string str = "aaabbbccc";

    std::string newStr = refactoringString(str);
    
    std::cout << newStr << std::endl; 
    
    return 0;
}
