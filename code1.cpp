#include <iostream>
#include <stdexcept>

double divide(double a, double b) {
    if (b == 0) {
        throw std::invalid_argument("Zero denominator");
    }
    return a / b;
}

int main() {
    for (double divisor : {2.0, 0.0, -4.0}) {
        try {
            std::cout << divide(10, divisor) << '\n';
        } catch (const std::invalid_argument& e) {
            std::cout << e.what() << '\n';
        }
    }

    // Explanation: -4.0 is not zero, so it is a valid divisor.
    // The check rejects only zero. 10 / -4.0 = -2.5, and the sign is kept.
    return 0;
}
