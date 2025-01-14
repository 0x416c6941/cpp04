#include <HumanA.hpp>
#include <string>
#include <Weapon.hpp>
#include <iostream>

HumanA::HumanA(const std::string & name, Weapon & weapon)
    : m_name(name), m_weapon(weapon) {
}

HumanA::HumanA(const HumanA & src)
    : m_name(src.m_name), m_weapon(src.m_weapon) {
}

HumanA & HumanA::operator = (const HumanA & src) {
    if (this == &src) {
        return *this;
    }
    m_name = src.m_name;
    m_weapon = src.m_weapon;
    return *this;
}

HumanA::~HumanA() {
}

void HumanA::attack() const {
    std::cout << m_name
              << " attacks with their " << m_weapon.getType() << std::endl;
}
