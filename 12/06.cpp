#include <iostream>
#include <vector>
#include <cctype>

std::string capitalizeWords(const std::string& text) {
    std::string result;
    bool newWord = true;

    for (char c : text) {
        if (newWord && isalpha(c)) {
            result += toupper(c);
            newWord = false;
        } else {
            result += tolower(c);
        }

        if (isspace(c) || ispunct(c)) {
            newWord = true;
        }
    }

    return result;
}

int main() {
    std::string input = "heLLo, woRLD";
    std::string output = capitalizeWords(input);
    std::cout << output << std::endl;
    return 0;
}