#include <Ice.hpp>
#include <AMateria.hpp>
#include <string>
#include <ICharacter.hpp>
#include <iostream>

Ice::Ice() : AMateria("ice") {
}

Ice::Ice(const Ice & src) : AMateria(src.m_type) {
}

Ice & Ice::operator = (const Ice & src) {
    if (this == &src) {
        return *this;
    }
    AMateria::operator = (src);
    return *this;
}

Ice::~Ice() {
}

Ice * Ice::clone() const {
    return new Ice(*this);
}

void Ice::use(ICharacter & target) const {
    std::cout << "* shoots an ice bolt at "
              << target.getName() << " *" << std::endl;
}
