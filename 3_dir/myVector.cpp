#include <iostream>
#include <stdexcept>

class Vector {
private:
    int* data;       // указатель на динамический массив
    size_t size;     // количество элементов в векторе
    size_t capacity; // емкость вектора

    void resize(size_t new_capacity) {
        int* new_data = new int[new_capacity];
        for (size_t i = 0; i < size; ++i) {
            new_data[i] = data[i];
        }
        delete[] data;
        data = new_data;
        capacity = new_capacity;
    }

public:
    Vector() : data(nullptr), size(0), capacity(0) {}

    ~Vector() {
        delete[] data;
    }

    size_t get_size() const {
        return size;
    }

    size_t get_capacity() const {
        return capacity;
    }

    bool empty() const {
        return size == 0;
    }

    int& front() {
        if (empty()) throw std::out_of_range("Vector is empty");
        return data[0];
    }

    int& back() {
        if (empty()) throw std::out_of_range("Vector is empty");
        return data[size - 1];
    }

    void push_back(int value) {
        if (size == capacity) {
            resize(capacity == 0 ? 1 : 2 * capacity);
        }
        data[size++] = value;
    }

    void clear() {
        delete[] data;
        data = new int[capacity];
        size = 0;
    }
};

int main() {
    Vector vec;

    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);

    std::cout << "Size: " << vec.get_size() << std::endl; 
    std::cout << "Capacity: " << vec.get_capacity() << std::endl;
    std::cout << "Front: " << vec.front() << std::endl;
    std::cout << "Back: " << vec.back() << std::endl;

    vec.clear();
    std::cout << "After clear: " << vec.get_size() << std::endl;

    return 0;
}
