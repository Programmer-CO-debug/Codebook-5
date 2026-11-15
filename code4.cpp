#include <iostream>
#include <stdexcept>

class InsufficientBalance : public std::runtime_error {
public:
    InsufficientBalance() : std::runtime_error("Insufficient balance") {}
};

class Account {
    double balance = 1000;   // teaching simplification; real money uses decimal types
public:
    void withdraw(double amount) {
        if (amount <= 0) {
            throw std::invalid_argument("Amount must be positive");
        }
        if (amount > balance) {
            throw InsufficientBalance{};
        }
        balance -= amount;
    }
    double getBalance() const { return balance; }
};

int main() {
    Account account;

    for (double amount : {300.0, 0.0, 1500.0}) {
        try {
            account.withdraw(amount);
            std::cout << "Withdrew " << amount << '\n';
        } catch (const InsufficientBalance& e) {
            std::cout << e.what() << '\n';
        } catch (const std::exception& e) {
            std::cout << e.what() << '\n';
        }
    }

    std::cout << "Balance: " << account.getBalance() << '\n';
    return 0;
}
