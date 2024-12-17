#include<iostream>
#include<vector>

void shellSort(std::vector<int>& vector) {
    int n = vector.size();

    for (int iter = n / 2; iter > 0; iter /= 2) {
        for (int i = iter; i < n; i++) {
            int temp = vector[i];
            int j = i;

            while (j >= iter && vector[j - iter] > temp) {
                vector[j] = vector[j - iter];
                j -= iter;
            }

            vector[j] = temp;
        }
    }
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& vec) {
    os << "[";
    for (size_t i = 0; i < vec.size(); ++i) {
        os << vec[i];
        if (i != vec.size() - 1) {
            os << ", ";
        }
    }
    os << "]";
    return os;
}

int main() {
    std::vector<int> input{3, 6, 2, 8, 8, 1, 6, 8, 9, 24, 0, 343, 85};
    
    shellSort(input);

    std::cout << input << std::endl;
    return 0;
}