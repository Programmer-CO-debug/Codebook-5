#include <iostream>
#include <string>

template<typename T = int>          // default TEMPLATE argument: T is int if not given
class Box {
    T value;
public:
    explicit Box(T v = T()) : value(v) {}   // default FUNCTION argument: 0, 0.0 or ""
    const T& get() const { return value; }
};

int main() {
    Box<> count(10);              // default type: Box<int>
    Box<> emptyCount;             // default type int, default value 0
    Box<double> price(19.5);
    Box<double> emptyPrice;       // default value 0.0
    Box<std::string> name("Neha");
    Box<std::string> emptyName;   // default value ""

    std::cout << count.get() << '\n' << name.get() << '\n';
    std::cout << "Empty int: " << emptyCount.get() << '\n';
    std::cout << "Empty double: " << emptyPrice.get() << '\n';
    std::cout << "Empty string: [" << emptyName.get() << "]\n";
    std::cout << "Price: " << price.get() << '\n';

    // Default TYPE argument chooses int when no type is written.
    // Default FUNCTION argument chooses the value when no value is passed.
    return 0;
}
