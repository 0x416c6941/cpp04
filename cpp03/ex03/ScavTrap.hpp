#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include <ClapTrap.hpp>
#include <string>

// Virtual inheritance makes sure only one instance of each of base classes
// is inherited when using diamond inheritance.
class ScavTrap : virtual public ClapTrap {
    protected:
        bool m_guard_gate;
        static const unsigned m_DEFAULT_HP = 100,
                              m_DEFAULT_EP = 50,
                              m_DEFAULT_AD = 20;

    public:
        ScavTrap(const std::string & name);
        ScavTrap(const ScavTrap & src);
        ScavTrap & operator = (const ScavTrap & src);
        virtual ~ScavTrap();

        virtual void attack(const std::string & target);
        virtual void guardGate();
};

#endif  // SCAVTRAP_HPP
