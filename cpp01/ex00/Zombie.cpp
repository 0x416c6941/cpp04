#include <Zombie.hpp>
#include <string>
#include <iostream>

Zombie::Zombie(const std::string & name) : m_name(name) {
}

Zombie::Zombie(const Zombie & src) : m_name(src.m_name) {
}

Zombie & Zombie::operator = (const Zombie & src) {
    if (this == &src) {
        return *this;
    }
    m_name = src.m_name;
    return *this;
}

Zombie::~Zombie() {
    std::cout << m_name << " was purged out of this world. Sad, bye..." << std::endl;
}

void Zombie::announce() const {
    std::cout << m_name << ": : BraiiiiiiinnnzzzZ..." << std::endl;
}
