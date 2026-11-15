#include <iostream>
#include <stdexcept>
#include <string>

class Guard {
    std::string name;
public:
    explicit Guard(const std::string& n) : name(n) {
        std::cout << "Acquire " << name << '\n';
    }
    ~Guard() {
        std::cout << "Release " << name << '\n';
    }
};

void worker() {
    Guard first("A");
    Guard second("B");
    throw std::runtime_error("Worker failed");
}

void service() {
    try {
        worker();
    } catch (const std::exception&) {
        std::cout << "Logged\n";
        throw;   // rethrow the original exception
    }
}

int main() {
    try {
        service();
    } catch (const std::exception& e) {
        std::cout << e.what() << '\n';
    }
    return 0;
}
