#include <iostream>

template<typename T>
class Pair {
    T first, second;
public:
    Pair(T a, T b) : first(a), second(b) {}
    T sum() const { return first + second; }
};

// The guide is intentionally redundant: the constructor already gives the same deduction.
template<typename T>
Pair(T, T) -> Pair<T>;

int main() {
    Pair numbers(2, 3);
    std::cout << "Deduced Pair<int> sum: " << numbers.sum() << '\n';

    // Pair mixed(2, 3.5);
    // Conflict: both arguments must give the same T. 2 gives int, 3.5 gives double.
    // Deduction fails, so this line is not compiled.

    // Valid alternative: state the type explicitly. 2 converts to double.
    Pair<double> mixed(2, 3.5);
    std::cout << "Explicit Pair<double> sum: " << mixed.sum() << '\n';
    return 0;
}
