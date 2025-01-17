#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include <ClapTrap.hpp>
#include <FragTrap.hpp>
#include <ScavTrap.hpp>
#include <string>

class DiamondTrap: public FragTrap, public ScavTrap {
    private:
        std::string m_name;

    public:
        DiamondTrap(const std::string & name);
        DiamondTrap(const DiamondTrap & src);
        DiamondTrap & operator = (const DiamondTrap & src);
        virtual ~DiamondTrap();

        // I couldn't care less about overloading other methods...
        virtual void attack(const std::string & target);
        virtual void whoAmI() const;
};

#endif  // SCAVTRAP_HPP
