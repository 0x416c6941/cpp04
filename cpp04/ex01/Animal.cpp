#include <Animal.hpp>
#include <string>
#include <iostream>

Animal::Animal(const std::string & type) : m_type(type) {
}

Animal::Animal(const Animal & src) : m_type(src.m_type) {
}

Animal & Animal::operator = (const Animal & src) {
    if (this == &src) {
        return *this;
    }
    m_type = src.m_type;
    return *this;
}

Animal::~Animal() {
}

const std::string & Animal::getType() const {
    return m_type;
}

void Animal::makeSound() const {
    std::cout << "Animal::makeSound() was called."
              << " You're probably doing something wrong." << std::endl;
}
