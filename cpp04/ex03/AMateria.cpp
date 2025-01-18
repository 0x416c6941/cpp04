#include <AMateria.hpp>
#include <string>

AMateria::AMateria(const std::string & type) : m_type(type) {
}

AMateria::AMateria(const AMateria & src) : m_type(src.m_type) {
}

AMateria & AMateria::operator = (const AMateria & src) {
    if (this == &src) {
        return *this;
    }
    // "While assigning a Materia to another,
    //  copying the type doesn't make sense."
    // Very well then, I won't.
    return *this;
}

AMateria::~AMateria() {
}

const std::string & AMateria::getType() const {
    return m_type;
}
