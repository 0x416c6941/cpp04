#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include <ClapTrap.hpp>
#include <string>

class ScavTrap : public ClapTrap {
    private:
        bool m_guard_gate;

    public:
        ScavTrap(const std::string & name);
        ScavTrap(const ScavTrap & src);
        ScavTrap & operator = (const ScavTrap & src);
        virtual ~ScavTrap();

        virtual void attack(const std::string & target);
        void guardGate();
};

#endif  // SCAVTRAP_HPP
