#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>

class ClapTrap {
    protected:
        std::string m_name;
        unsigned m_hp, m_ep, m_ad;

    public:
        ClapTrap(const std::string & name);
        ClapTrap(const ClapTrap & src);
        ClapTrap & operator = (const ClapTrap & src);
        virtual ~ClapTrap();

        virtual void attack(const std::string & target);
        void takeDamage(unsigned amount);
        void beRepaired(unsigned amount);
};

#endif  // CLAPTRAP_HPP
