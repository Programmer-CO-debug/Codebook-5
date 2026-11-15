#include <array>
#include <cstddef>
#include <iostream>
#include <stdexcept>
#include <string>

template<typename T, std::size_t N = 3>
class Stack {
    static_assert(N > 0, "Capacity must be positive");
    std::array<T, N> data{};
    std::size_t used = 0;
public:
    void push(const T& value) {
        if (used == N) {
            throw std::overflow_error("Stack full");
        }
        data[used] = value;
        ++used;
    }

    T pop() {
        if (used == 0) {
            throw std::underflow_error("Stack empty");
        }
        T result = data[used - 1];
        --used;
        return result;
    }

    const T& peek() const {
        if (used == 0) {
            throw std::underflow_error("Stack empty");
        }
        return data[used - 1];
    }

    std::size_t size() const noexcept { return used; }
};

int main() {
    Stack<std::string, 2> stack;

    stack.push("alpha");
    stack.push("beta");
    std::cout << "Size after pushes: " << stack.size() << '\n';

    try {
        stack.push("gamma");   // rejected: capacity is 2
    } catch (const std::overflow_error& e) {
        std::cout << "Rejected push: " << e.what() << '\n';
    }
    std::cout << "Size after rejected push: " << stack.size() << '\n';

    std::cout << "Peek: " << stack.peek() << '\n';   // peek does not change size
    std::cout << "Pop: " << stack.pop() << '\n';
    std::cout << "Pop: " << stack.pop() << '\n';
    std::cout << "Size: " << stack.size() << '\n';

    try {
        stack.pop();          // rejected: stack is empty
    } catch (const std::underflow_error& e) {
        std::cout << "Rejected pop: " << e.what() << '\n';
    }
    std::cout << "Size after rejected pop: " << stack.size() << '\n';

    try {
        std::cout << stack.peek() << '\n';
    } catch (const std::underflow_error& e) {
        std::cout << "Rejected peek: " << e.what() << '\n';
    }
    return 0;
}
