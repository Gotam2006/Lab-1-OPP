#include <iostream>
#include <cmath>

class Vector2D {
private:
    double x, y;

public:
    // 1. Конструктори
    Vector2D() : x(0), y(0) {} // Конструктор за замовчуванням

    Vector2D(double xVal, double yVal) : x(xVal), y(yVal) {} // Конструктор ініціалізації

    Vector2D(const Vector2D& other) : x(other.x), y(other.y) {} // Конструктор копіювання

    // 2. Операції додавання та віднімання векторів
    Vector2D operator+(const Vector2D& other) const {
        return Vector2D(x + other.x, y + other.y);
    }

    Vector2D operator-(const Vector2D& other) const {
        return Vector2D(x - other.x, y - other.y);
    }

    // Скалярний добуток
    double dot(const Vector2D& other) const {
        return x * other.x + y * other.y;
    }

    // 3. Масштабування вектору
    Vector2D operator*(double scalar) const {
        return Vector2D(x * scalar, y * scalar);
    }

    Vector2D operator/(double scalar) const {
        if (scalar == 0) throw std::runtime_error("Ділення на нуль!");
        return Vector2D(x / scalar, y / scalar);
    }

    // 4. Віддзеркалення (протилежний вектор)
    Vector2D operator-() const {
        return Vector2D(-x, -y);
    }

    // 5. Довжина (норма) вектору
    double length() const {
        return std::sqrt(x * x + y * y);
    }

    // Метод для виведення координат вектора
    void print() const {
        std::cout << "(" << x << ", " << y << ")\n";
    }
};

// Демонстрація
int main() {
    Vector2D v1(3, 4);
    Vector2D v2(1, 2);

    std::cout << "v1 = "; v1.print();
    std::cout << "v2 = "; v2.print();

    Vector2D sum = v1 + v2;
    std::cout << "v1 + v2 = "; sum.print();

    Vector2D diff = v1 - v2;
    std::cout << "v1 - v2 = "; diff.print();

    double scalarProduct = v1.dot(v2);
    std::cout << "Скалярний добуток v1 і v2 = " << scalarProduct << std::endl;

    Vector2D scaled = v1 * 2.5;
    std::cout << "v1 * 2.5 = "; scaled.print();

    Vector2D divided = v1 / 2;
    std::cout << "v1 / 2 = "; divided.print();

    Vector2D opposite = -v1;
    std::cout << "Протилежний до v1 = "; opposite.print();

    std::cout << "Довжина v1 = " << v1.length() << std::endl;

    return 0;
}
