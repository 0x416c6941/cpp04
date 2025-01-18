#include <WrongCat.hpp>
#include <WrongAnimal.hpp>
#include <string>
#include <iostream>

WrongCat::WrongCat() : WrongAnimal("WrongCat") {
}

WrongCat::WrongCat(const WrongCat & src): WrongAnimal(src) {
}

WrongCat & WrongCat::operator = (const WrongCat & src) {
    if (this == &src) {
        return *this;
    }
    WrongAnimal::operator = (src);
    return *this;
}

WrongCat::~WrongCat() {
}

void WrongCat::makeSound() const {
    std::cout << "meow >:(" << std::endl;
}
