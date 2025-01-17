#include <FragTrap.hpp>
#include <ClapTrap.hpp>
#include <string>
#include <iostream>

FragTrap::FragTrap(const std::string & name) : ClapTrap(name) {
    std::cout << "FragTrap::ctor is called" << std::endl;
    m_hp = m_DEFAULT_HP;
    m_ep = m_DEFAULT_EP;
    m_ad = m_DEFAULT_AD;
}

FragTrap::FragTrap(const FragTrap & src) : ClapTrap(src) {
    std::cout << "FragTrap::copy ctor is called" << std::endl;
    m_hp = src.m_hp;
    m_ep = src.m_ep;
    m_ad = src.m_ad;
}

FragTrap & FragTrap::operator = (const FragTrap & src) {
    if (this == &src) {
        return *this;
    }
    ClapTrap::operator = (src);
    m_hp = src.m_hp;
    m_ep = src.m_ep;
    m_ad = src.m_ad;
    return *this;
}

FragTrap::~FragTrap() {
    std::cout << "FragTrap()::dector is called" << std::endl;
}

void FragTrap::attack(const std::string & target) {
    if (m_hp <= 0) {
        std::cout << "FragTrap " << m_name
                  << " is dead and therefore couldn't attack " << target << std::endl;
        return;
    }
    else if (m_ep <= 0) {
        std::cout << "FragTrap " << m_name
                  << " is tired and couldn't attack " << target << std::endl;
        return;
    }
    std::cout << "FragTrap " << m_name << " attacks " << target
              << ", causing " << m_ad << " points of damage!" << std::endl;
    m_ep--;
}

void FragTrap::highFivesGuys() const {
    if (m_hp <= 0) {
        std::cout << "FragTrap " << m_name
                  << " is dead and therefore couldn't request high fives" << std::endl;
        return;
    }
    else if (m_ep <= 0) {
        std::cout << "FragTrap " << m_name
                  << " is tired and therefore couldn't request high fives" << std::endl;
        return;
    }
    std::cout << "FragTrap " << m_name
              << " is now requesting high fives from you" << std::endl;
}
