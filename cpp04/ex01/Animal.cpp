#include <Animal.hpp>
#include <string>
#include <Brain.hpp>
#include <iostream>

Animal::Animal() : m_type(), m_brain(new Brain()) {
}

Animal::Animal(const std::string & type) : m_type(type), m_brain(new Brain()) {
}

Animal::Animal(const Animal & src) : m_type(src.m_type),
                                     m_brain(new Brain(*src.m_brain)) {
}

Animal & Animal::operator = (const Animal & src) {
    if (this == &src) {
        return *this;
    }
    m_type = src.m_type;
    m_brain = new Brain(*src.m_brain);
    return *this;
}

Animal::~Animal() {
    delete m_brain;
}

const std::string & Animal::getType() const {
    return m_type;
}

void Animal::makeSound() const {
    std::cout << "Animal::makeSound() was called."
              << " You're probably doing something wrong." << std::endl;
}

Brain & Animal::get_brain() {
    return *m_brain;
}
