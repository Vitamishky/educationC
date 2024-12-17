#include <iostream>
#include <vector>
#include <string>

void tower(int n, char source, char target, char auxiliary, std::vector<std::string>& instructions) {
    if (n == 1) {
        instructions.push_back("Move disk 1 from " + std::string(1, source) + " on " + std::string(1, target));
    } else {
        tower(n - 1, source, auxiliary, target, instructions);
        
        instructions.push_back("Move disk " + std::to_string(n) + " from " + std::string(1, source) + " to " + std::string(1, target));
        
        tower(n - 1, auxiliary, target, source, instructions);
    }
}

int main() {
    int n;  
    std::cin >> n;
    std::vector<std::string> instructions;

    tower(n, 'A', 'C', 'B', instructions);

    for (const std::string& instruction : instructions) {
        std::cout << instruction << std::endl;
    }

    return 0;
}
