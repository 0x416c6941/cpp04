#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include <ClapTrap.hpp>
#include <string>

class FragTrap : public ClapTrap {
    public:
        FragTrap(const std::string & name);
        FragTrap(const FragTrap & src);
        FragTrap & operator = (const FragTrap & src);
        virtual ~FragTrap();

        virtual void attack(const std::string & target);
        void highFivesGuys() const;
};

#endif  // SCAVTRAP_HPP
