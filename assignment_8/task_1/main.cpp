#include <iostream>

template <typename T>
bool compare(T a, T b) {
    std::cout << "Generic function: ";
    std::cout << "Comparing " << a << " with " << b << std::endl;
    return a == b;
}

bool compare(double a, double b) {
    std::cout << "Compare double " << a << " with double " << b << std::endl;
    return a == b;
}


int main() {

    compare(1, 2);
    compare("wasd", "wasd");
    compare(1.1, 1.0);

    return 0;
}
