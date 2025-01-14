#include <Weapon.hpp>
#include <string>

Weapon::Weapon(const std::string & type) : m_type(type) {
}

Weapon::Weapon(const Weapon & src) : m_type(src.m_type) {
}

Weapon & Weapon::operator = (const Weapon & src) {
    if (this == &src) {
        return *this;
    }
    m_type = src.m_type;
    return *this;
}

Weapon::~Weapon() {
}

const std::string & Weapon::getType() const {
    return m_type;
}

void Weapon::setType(const std::string & type) {
    m_type = type;
}
