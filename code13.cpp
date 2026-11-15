#include <array>
#include <cstddef>
#include <iostream>
#include <stdexcept>

template<typename T, std::size_t N = 3>
class Fixed {
    std::array<T, N> data{};
public:
    T& at(std::size_t i) { return data.at(i); }
};

int main() {
    Fixed<double, 5> values;   // N = 5 is a compile-time choice. Valid indices: 0 to 4.

    try {
        values.at(0) = 1.5;    // first position
        values.at(4) = 9.5;    // last position
        std::cout << "First: " << values.at(0) << '\n';
        std::cout << "Last: " << values.at(4) << '\n';
        values.at(5) = 0.0;    // one past the last valid index
    } catch (const std::out_of_range&) {
        std::cout << "Invalid index 5 (valid indices are 0 to 4)\n";
    }
    return 0;
}
