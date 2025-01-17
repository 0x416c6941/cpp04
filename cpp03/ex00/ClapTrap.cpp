#include <ClapTrap.hpp>
#include <string>
#include <iostream>
#include <climits>

ClapTrap::ClapTrap(const std::string & name) : m_name(name),
                                               m_hp(10), m_ep(10), m_ad(0) {
    std::cout << "ClapTrap::ctor is called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap & src) : m_name(src.m_name),
                                           m_hp(src.m_hp), m_ep(src.m_ep), m_ad(src.m_ad) {
    std::cout << "ClapTrap::copy ctor is called" << std::endl;
}

// subject.pdf doesn't specify that ClapTrap::operator = ()
// should produce any output (only ctors are specified).
ClapTrap & ClapTrap::operator = (const ClapTrap & src) {
    if (this == &src) {
        return *this;
    }
    m_name = src.m_name;
    m_hp = src.m_hp;
    m_ep = src.m_ep;
    m_ad = src.m_ad;
    return *this;
}

ClapTrap::~ClapTrap() {
    std::cout << "ClapTrap::dector is called" << std::endl;
}

void ClapTrap::attack(const std::string & target) {
    if (m_hp <= 0) {
        std::cout << "ClapTrap " << m_name
                  << " is dead and therefore couldn't attack " << target << std::endl;
        return;
    }
    else if (m_ep <= 0) {
        std::cout << "ClapTrap " << m_name
                  << " is tired and couldn't attack " << target << std::endl;
        return;
    }
    std::cout << "ClapTrap " << m_name << " attacks " << target
              << ", causing " << m_ad << " points of damage!" << std::endl;
    m_ep--;
}

void ClapTrap::takeDamage(unsigned amount) {
    if (m_hp <= 0) {
        std::cout << "ClapTrap " << m_name << " is already dead" << std::endl;
        return;
    }
    else if (m_hp < amount) {
        std::cout << "ClapTrap " << m_name << " has died" << std::endl;
        m_hp = 0;
        return ;
    }
    std::cout << "ClapTrap " << m_name
              << " took " << amount << "points of damage" << std::endl;
    m_hp -= amount;
}

void ClapTrap::beRepaired(unsigned amount) {
    if (m_hp <= 0) {
        std::cout << "ClapTrap " << m_name
                  << " is dead and therefore couldn't repair itself" << std::endl;
        return;
    }
    else if (m_ep <= 0) {
        std::cout << "ClapTrap " << m_name
                  << " is tired and repair itself" << std::endl;
        return;
    }
    std::cout << "ClapTrap " << m_name
              << " repairs itself by " << amount << " points of health" << std::endl;
    if (m_hp + amount < m_hp) {
        m_hp = UINT_MAX;
    }
    else
        m_hp += amount;
    m_ep--;
}
