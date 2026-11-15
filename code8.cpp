#include <iostream>
#include <string>

template<typename T, typename U>
auto addValues(T a, U b) -> decltype(a + b) {
    return a + b;
}

int main() {
    std::cout << addValues(4, 2.5) << '\n';
    std::cout << addValues(std::string("Hello, "), std::string("World")) << '\n';
    return 0;
}

