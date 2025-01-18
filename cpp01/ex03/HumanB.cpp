#include <HumanB.hpp>
#include <string>
#include <Weapon.hpp>
#include <iostream>
#include <cstddef>

HumanB::HumanB(const std::string & name) : m_name(name), m_weapon(NULL) {
}

HumanB::HumanB(const HumanB & src)
    : m_name(src.m_name), m_weapon(src.m_weapon) {
}

HumanB & HumanB::operator = (const HumanB & src) {
    if (this == &src) {
        return *this;
    }
    m_name = src.m_name;
    m_weapon = src.m_weapon;
    return *this;
}

HumanB::~HumanB() {
}

void HumanB::setWeapon(const Weapon & weapon) {
    m_weapon = &weapon;
}

void HumanB::setWeapon(const Weapon * weapon) {
    m_weapon = weapon;
}

void HumanB::attack() const {
    std::cout << m_name;
    if (m_weapon == NULL) {
        std::cout << " couldn't attack, since they're unarmed." << std::endl;
        return;
    }
    std::cout << " attacks with their " << m_weapon->getType() << std::endl;
}
