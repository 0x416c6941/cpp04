#include <Harl.hpp>
#include <iostream>

int main() {
    Harl yapper;

    yapper.complain("DEBUG");
    std::cout << std::endl;
    yapper.complain("INFO");
    std::cout << std::endl;
    yapper.complain("WARNING");
    std::cout << std::endl;
    yapper.complain("ERROR");
    return 0;
}
