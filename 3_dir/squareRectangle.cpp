#include<iostream>
#include<vector>

struct Rectangle {
    float x1, y1;
    float width, height;

    Rectangle(float _x1, float _y1, float _width, float _height) :
        x1(_x1), y1(_y1), width(_width), height(_height) {}

    Rectangle() :
        x1(0), y1(0), width(2), height(2) {}

    float x2 = x1 + width;
    float y2 = y1 + height; 

    float square = width * height;
};

bool intersection(const Rectangle& A, Rectangle& B) {
    if (A.x2 < B.x1 || A.x1 > B.x2 || A.y2 < B.y1 || A.y1 > B.y2) {
        return false;  // Нет пересечения
    }

    // Вычисляем координаты пересечения
    float x_intersect1 = std::max(A.x1, B.x1);
    float y_intersect1 = std::max(A.y1, B.y1);
    float x_intersect2 = std::min(A.x2, B.x2);
    float y_intersect2 = std::min(A.y2, B.y2);

    // Если пересечение имеет положительные размеры, обновляем прямоугольник B
    if (x_intersect1 < x_intersect2 && y_intersect1 < y_intersect2) {
        B = Rectangle(x_intersect1, y_intersect1, x_intersect2 - x_intersect1, y_intersect2 - y_intersect1);
        return true;
    }

    return false; 
}

void computeSquare(std::vector<Rectangle>& rects) {
    for(int i = 0; i < rects.size() - 1; ++i) {

        if(!intersection(rects[i], rects[i + 1])) {
            std::cout << "Empty square" << std::endl;
            return;
        }
    }

    std::cout << "Total square: " << rects[rects.size() - 1].width << std::endl;
}

int main() {
    Rectangle A(1, 2, 3, 4),
              B(3, 5, 2, 1),
              C(3, 5, 7, 8);

    std::vector<Rectangle> rects{A, B, C};

    computeSquare(rects);

    return 0;
}