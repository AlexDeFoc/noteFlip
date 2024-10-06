#include <print.hpp>

void clearScreen() {
    std::cout << "\e[1;1H\e[2J";
};

void greenText() {
    std::cout << "\033[1;32m";
}

void redText() {
    std::cout << "\033[1;31m";
}

void resetTextColor() {
    std::cout << "\033[0m";
}
