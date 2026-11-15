#include <iostream>
#include <stdexcept>
#include <vector>

int main() {
    std::vector<int> marks{80, 90};
    std::cout << "Size: " << marks.size() << " (valid indices are 0 and 1)\n";

    for (int index : {1, 2}) {
        try {
            std::cout << "marks.at(" << index << ") = "
                      << marks.at(static_cast<std::size_t>(index)) << '\n';
        } catch (const std::out_of_range&) {
            // Index 2 equals size(): it is the end position, one past the last element.
            // end() can be compared, but it cannot be read as an element.
            std::cout << "Invalid index " << index << '\n';
        }
    }
    return 0;
}
