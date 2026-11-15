#include <iostream>
#include <stdexcept>

void validate(int marks) {
    if (marks < 0 || marks > 100) {
        throw std::out_of_range("Marks outside 0..100");
    }
}

int main() {
    for (int marks : {-1, 0, 100, 101}) {
        try {
            validate(marks);
            std::cout << "Valid: " << marks << '\n';
        } catch (const std::exception& e) {
            std::cout << e.what() << " (given " << marks << ")\n";
        }
    }
    return 0;
}

