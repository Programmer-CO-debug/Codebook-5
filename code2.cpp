#include <iostream>

void raise(int option) {
    switch (option) {
        case 1: throw 7;                   // int
        case 2: throw 2.5;                 // double
        case 3: throw "Other failure";     // const char*
        default: throw true;               // bool: only the catch-all matches
    }
}

int main() {
    for (int option : {1, 2, 3, 4}) {
        try {
            raise(option);
        } catch (int n) {
            std::cout << "Integer: " << n << '\n';
        } catch (double n) {
            std::cout << "Double: " << n << '\n';
        } catch (const char* text) {
            std::cout << "Text: " << text << '\n';
        } catch (...) {
            std::cout << "Other exception\n";
        }
    }
    // catch(...) must be the last handler.
    return 0;
}
