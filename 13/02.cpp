#include <iostream>
#include <vector>
#include <iomanip>

void printPascalTriangle(int n) {
    std::vector<std::vector<int>> triangle(n);
    
    for (int line = 0; line < n; line++) {
        triangle[line].resize(line + 1);
        
        triangle[line][0] = triangle[line][line] = 1;
        
        for (int j = 1; j < line; j++)
            triangle[line][j] = triangle[line-1][j-1] + triangle[line-1][j];
    }
    
    for (int line = 0; line < n; line++) {
        std::cout << std::setw((n - line) * 2);
        
        for (int num : triangle[line])
            std::cout << std::setw(4) << num;
            
        std::cout << std::endl;
    }
}

int main() {
    const int rows = 10;
    printPascalTriangle(rows);
    return 0;
}