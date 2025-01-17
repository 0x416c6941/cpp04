#include <Cat.hpp>
#include <Animal.hpp>
#include <string>
#include <iostream>

Cat::Cat() : Animal("Cat"), m_brain(new Brain()) {
}

Cat::Cat(const Cat & src): Animal(src), m_brain(new Brain(*src.m_brain)) {
}

Cat & Cat::operator = (const Cat & src) {
    if (this == &src) {
        return *this;
    }
    Animal::operator = (src);
    m_brain = new Brain(*src.m_brain);
    return *this;
}

Cat::~Cat() {
    delete m_brain;
}

void Cat::makeSound() const {
    std::cout << "Meow :3" << std::endl;
}

Brain & Cat::get_brain() {
    return *m_brain;
}
