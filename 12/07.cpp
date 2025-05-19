#include <iostream>
#include <vector>
#include <string>

std::string separateWords(const std::vector<std::string>& words, const std::string& delim) {
    if (words.empty())
        return "";
    
    std::string result = words[0];
    for (size_t i = 1; i < words.size(); ++i)
        result += delim + words[i];
    return result;
}

int main() {
    std::vector<std::string> words = {"Hello", "world", "!"};
    std::string delim = "&";
    
    std::string res = separateWords(words, delim);
    std::cout << res << std::endl;
    
    return 0;
}