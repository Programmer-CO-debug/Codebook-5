#include <iostream>

template<typename T>
class Box {
    T value;
public:
    explicit Box(T v) : value(v) {}
    T get() const { return value; }
};

int main() {
    // CTAD: the compiler deduces the type from the constructor argument.
    Box count(42);       // Box<int>
    Box price(19.5);     // Box<double>
    std::cout << "CTAD: " << count.get() << ' ' << price.get() << '\n';

    // Explicit arguments: the type is written by the programmer.
    Box<int> explicitCount(42);
    Box<double> explicitPrice(19.5);
    std::cout << "Explicit: " << explicitCount.get() << ' ' << explicitPrice.get() << '\n';

    // Explicit arguments can also differ from the argument's own type.
    // Here the int value 42 is converted to double before storing.
    Box<double> converted(42);
    std::cout << "Converted to double: " << converted.get() << '\n';
    return 0;
}
