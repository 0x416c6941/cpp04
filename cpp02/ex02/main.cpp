#include <Fixed.hpp>
#include <iostream>

int main(void) {
    Fixed a;
    Fixed const b(10);
    Fixed const c(42.42f);
    Fixed const d;

    std::cout << (b > c) << std::endl;
    std::cout << (Fixed(-10) > Fixed(-42.42f)) << std::endl;
    return 0;
}
