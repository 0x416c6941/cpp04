#include <Dog.hpp>
#include <Animal.hpp>
#include <Brain.hpp>
#include <string>
#include <iostream>

Dog::Dog() : Animal("Dog"), m_brain(new Brain()) {
}

Dog::Dog(const Dog & src): Animal(src), m_brain(new Brain(*src.m_brain)) {
}

Dog & Dog::operator = (const Dog & src) {
    if (this == &src) {
        return *this;
    }
    Animal::operator = (src);
    m_brain = new Brain(*src.m_brain);
    return *this;
}

Dog::~Dog() {
    delete m_brain;
}

void Dog::makeSound() const {
    std::cout << "Bark" << std::endl;
}

Brain & Dog::get_brain() {
    return *m_brain;
}
