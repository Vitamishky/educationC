#include <iostream>

// Method 1
void printHello() __attribute__ ((constructor)); 
void printHello(void) {
    std::cout << "Hello";
}


// Method 2
struct PrintSpace {
    PrintSpace() {
        std::cout << ", ";
    }
};
PrintSpace printer;


// Method 3
const int printWorld = []() {
    std::cout << "world";
    return 0;
}();


// Method 4
void printExclamation() {
    std::cout << "!" << std::endl;
}
int dummy = (std::atexit(printExclamation), 0);


int main() {
    return 0;
}