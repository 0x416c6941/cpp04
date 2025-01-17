#include <DiamondTrap.hpp>
#include <FragTrap.hpp>
#include <ScavTrap.hpp>
#include <ClapTrap.hpp>
#include <string>
#include <iostream>

DiamondTrap::DiamondTrap(const std::string & name) : ClapTrap(name + "_clap_name"),
                                                     FragTrap(name + "_clap_name"),
                                                     ScavTrap(name + "_clap_name"),
                                                     m_name(name) {
    std::cout << "DiamondTrap::ctor is called" << std::endl;
    m_hp = FragTrap::m_DEFAULT_HP;  // Accessing base class members.
    m_ep = ScavTrap::m_DEFAULT_EP;
    m_ad = FragTrap::m_DEFAULT_AD;
}

DiamondTrap::DiamondTrap(const DiamondTrap & src) : ClapTrap(src),
                                                    FragTrap(src), ScavTrap(src),
                                                    m_name(src.m_name) {
    std::cout << "DiamondTrap::copy ctor is called" << std::endl;
    m_hp = src.m_hp;
    m_ep = src.m_ep;
    m_ad = src.m_ad;
}

DiamondTrap & DiamondTrap::operator = (const DiamondTrap & src) {
    if (this == &src) {
        return *this;
    }
    ClapTrap::operator = (src);
    m_name = src.m_name;
    m_hp = src.m_hp;
    m_ep = src.m_ep;
    m_ad = src.m_ad;
    return *this;
}

DiamondTrap::~DiamondTrap() {
    std::cout << "DiamondTrap()::dector is called" << std::endl;
}

void DiamondTrap::attack(const std::string & target) {
    if (m_hp <= 0) {
        std::cout << "DiamondTrap " << m_name
                  << " is dead and therefore couldn't attack " << target << std::endl;
        return;
    }
    else if (m_ep <= 0) {
        std::cout << "DiamondTrap " << m_name
                  << " is tired and couldn't attack " << target << std::endl;
        return;
    }
    else if (m_guard_gate) {
        std::cout << "DiamondTrap " << m_name
                  << " is on guard mode and therefore wouldn't attack "
                  << target << std::endl;
        return;
    }
    std::cout << "DiamondTrap " << m_name << " attacks " << target
              << ", causing " << m_ad << " points of damage!" << std::endl;
    m_ep--;
}

void DiamondTrap::whoAmI() const {
    // Accessing base members again.
    // Yep, simple, just type the base class you'd like to access members from.
    std::cout << "DiamondTrap name: " << m_name
              << ", ClapTrap name: " << ClapTrap::m_name << std::endl;
}
