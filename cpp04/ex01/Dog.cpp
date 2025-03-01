#include <Dog.hpp>
#include <Animal.hpp>
#include <string>
#include <iostream>

Dog::Dog() : Animal("Dog") {
}

Dog::Dog(const Dog & src): Animal(src) {
}

Dog & Dog::operator = (const Dog & src) {
    if (this == &src) {
        return *this;
    }
    Animal::operator = (src);
    return *this;
}

Dog::~Dog() {
}

void Dog::makeSound() const {
    std::cout << "Bark" << std::endl;
}
