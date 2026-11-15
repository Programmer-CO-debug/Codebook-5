#include <iostream>
#include <string>

template<typename T>
T maximum(T a, T b) {
    return a < b ? b : a;
}

template<typename T>
T minimum(T a, T b) {
    return b < a ? b : a;
}

int main() {
    std::cout << "maximum(4, 9): " << maximum(4, 9) << '\n';
    std::cout << "maximum<double>(4, 9.5): " << maximum<double>(4, 9.5) << '\n';
    std::cout << "minimum(4, 9): " << minimum(4, 9) << '\n';
    std::cout << "minimum<double>(4, 9.5): " << minimum<double>(4, 9.5) << '\n';
    std::cout << "minimum(strings): "
              << minimum(std::string("Apple"), std::string("Pear")) << '\n';

    // Why this line is commented out:
    // maximum(4, 9.5);
    // Both arguments must produce the same T. Argument 4 deduces T = int,
    // while 9.5 deduces T = double. The deductions conflict, so compilation fails.
    // Explicit maximum<double>(...) works because the arguments convert to double.
    return 0;
}
