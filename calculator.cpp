#include <iostream>
#include <cmath>

void perform_operation(char operation, double x, double y) {
    double result = 0;
    switch (operation) {
        case '+':
            result = std::abs(x + y);
            break;
        case '-':
            result = std::abs(x - y);
            break;
        case '*':
            result = std::abs(x * y);
            break;
        case '/':
            if (y == 0) {
                std::cout << "Error: Division by zero is not allowed.\n";
                return;
            }
            // Ako je y veći od x, delimo y sa x
            if (y > x) {
                result = y / x;
            } else {
                result = x / y;
            }
            break;
        default:
            std::cout << "Invalid operation!\n";
            return;
    }
    std::cout << "Result: " << result << "\n";
}

void perform_all_operations(double x, double y) {
    std::cout << "Addition: " << std::abs(x + y) << "\n";
    std::cout << "Subtraction: " << std::abs(x - y) << "\n";
    std::cout << "Multiplication: " << std::abs(x * y) << "\n";
    if (y != 0) {
        // Prikazujemo samo "Division", bez ikakvih dodatnih informacija
        if (y > x) {
            std::cout << "Division: " << (y / x) << "\n";  // Ako je y veći, delimo y sa x
        } else {
            std::cout << "Division: " << (x / y) << "\n";  // Inače delimo x sa y
        }
    } else {
        std::cout << "Division by zero is not allowed.\n";
    }
}

int main() {
    double x, y;
    char operation;
    std::string answer;

    std::cout << "Enter first number: ";
    std::cin >> x;

    std::cout << "Enter second number: ";
    std::cin >> y;

    std::cout << "Do you want to calculate all operations (yes/no)? ";
    std::cin >> answer;

    if (answer == "yes" || answer == "Yes") {
        std::cout << "\nPerforming all operations:\n";
        perform_all_operations(x, y);
    } else {
        std::cout << "Choose operation (+, -, *, /): ";
        std::cin >> operation;

        perform_operation(operation, x, y);
    }

    return 0;
}
