#include <algorithm>
#include <cstddef>
#include <functional>
#include <iostream>

// Reference to array keeps the extent N, so T and N are both deduced.
template<typename T, std::size_t N>
void sortDescending(T (&a)[N]) {
    std::sort(a, a + N, std::greater<T>());
}

int main() {
    int values[]{3, 1, 2};
    double readings[]{2.5, 1.5};

    sortDescending(values);
    sortDescending(readings);

    for (int n : values) std::cout << n << ' ';
    std::cout << '\n';
    for (double n : readings) std::cout << n << ' ';
    std::cout << '\n';
    return 0;
}
