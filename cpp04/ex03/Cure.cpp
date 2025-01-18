#include <Cure.hpp>
#include <AMateria.hpp>
#include <string>
#include <ICharacter.hpp>
#include <iostream>

Cure::Cure() : AMateria("cure") {
}

Cure::Cure(const Cure & src) : AMateria(src) {
}

Cure & Cure::operator = (const Cure & src) {
    if (this == &src) {
        return *this;
    }
    AMateria::operator = (src);
    return *this;
}

Cure::~Cure() {
}

Cure * Cure::clone() const {
    return new Cure(*this);
}

void Cure::use(ICharacter & target) const {
    std::cout << "* heals " << target.getName() << "wounds *" << std::endl;
}
