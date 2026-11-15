#include <iomanip>
#include <iostream>

// 1 inch = 2.54 cm. The type T decides how precisely the value is stored.
template<typename T>
inline constexpr T inchesToCm = static_cast<T>(2.54L);

int main() {
    std::cout << std::fixed << std::setprecision(2);

    std::cout << "12 inches (double): " << inchesToCm<double> * 12.0 << " cm\n";
    std::cout << "12 inches (float):  " << inchesToCm<float> * 12.0F << " cm\n";

    // int stores only 2, so the fraction .54 is lost and the result is wrong.
    std::cout << "12 inches (int):    " << inchesToCm<int> * 12 << " cm (wrong: truncated)\n";

    // Sensible types: double for general use, float when memory matters.
    // Integer types are not suitable for values with fractions.
    return 0;
}
