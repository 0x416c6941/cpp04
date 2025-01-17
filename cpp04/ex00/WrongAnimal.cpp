#include <WrongAnimal.hpp>
#include <string>
#include <iostream>

WrongAnimal::WrongAnimal() : m_type() {
}

WrongAnimal::WrongAnimal(const std::string & type) : m_type(type) {
}

WrongAnimal::WrongAnimal(const WrongAnimal & src) : m_type(src.m_type) {
}

WrongAnimal & WrongAnimal::operator = (const WrongAnimal & src) {
    if (this == &src) {
        return *this;
    }
    m_type = src.m_type;
    return *this;
}

WrongAnimal::~WrongAnimal() {
}

const std::string & WrongAnimal::getType() const {
    return m_type;
}

void WrongAnimal::makeSound() const {
    std::cout << "WrongAnimal::makeSound() was called."
              << " You're probably doing something wrong." << std::endl;
}
