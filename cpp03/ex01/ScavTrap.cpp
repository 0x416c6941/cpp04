#include <ScavTrap.hpp>
#include <ClapTrap.hpp>
#include <string>
#include <iostream>

ScavTrap::ScavTrap(const std::string & name) : ClapTrap(name), m_guard_gate(false) {
    std::cout << "ScavTrap::ctor is called" << std::endl;
    m_hp = 100;
    m_ep = 50;
    m_ad = 20;
}

ScavTrap::ScavTrap(const ScavTrap & src) : ClapTrap(src), m_guard_gate(src.m_guard_gate) {
    std::cout << "ScavTrap::copy ctor is called" << std::endl;
    m_hp = src.m_hp;
    m_ep = src.m_ep;
    m_ad = src.m_ad;
}

ScavTrap & ScavTrap::operator = (const ScavTrap & src) {
    if (this == &src) {
        return *this;
    }
    ClapTrap::operator = (src);
    m_hp = src.m_hp;
    m_ep = src.m_ep;
    m_ad = src.m_ad;
    return *this;
}

ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap()::dector is called" << std::endl;
}

void ScavTrap::attack(const std::string & target) {
    if (m_hp <= 0) {
        std::cout << "ScavTrap " << m_name
                  << " is dead and therefore couldn't attack " << target << std::endl;
        return;
    }
    else if (m_ep <= 0) {
        std::cout << "ScavTrap " << m_name
                  << " is tired and couldn't attack " << target << std::endl;
        return;
    }
    else if (m_guard_gate) {
        std::cout << "ScavTrap " << m_name
                  << " is on guard mode and therefore wouldn't attack "
                  << target << std::endl;
        return;
    }
    std::cout << "ScavTrap " << m_name << " attacks " << target
              << ", causing " << m_ad << " points of damage!" << std::endl;
    m_ep--;
}

void ScavTrap::guardGate() {
    if (m_hp <= 0) {
        std::cout << "ScavTrap " << m_name
                  << " is dead and therefore couldn't be set to guard mode" << std::endl;
        return;
    }
    else if (m_ep <= 0) {
        std::cout << "ScavTrap " << m_name
                  << " is tired and therefore couldn't be set to guard mode" << std::endl;
        return;
    }
    else if (m_guard_gate) {
        std::cout << "ScavTrap " << m_name
                  << " is already on guard mode" << std::endl;
        return;
    }
    m_guard_gate = true;
    std::cout << "ScavTrap " << m_name
              << " is now on guard mode" << std::endl;
}
