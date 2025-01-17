#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include <ClapTrap.hpp>
#include <string>

// Virtual inheritance makes sure only one instance of each of base classes
// is inherited when using diamond inheritance.
class FragTrap : virtual public ClapTrap {
    protected:
        static const unsigned m_DEFAULT_HP = 100,
                              m_DEFAULT_EP = 100,
                              m_DEFAULT_AD = 30;
    public:
        FragTrap(const std::string & name);
        FragTrap(const FragTrap & src);
        FragTrap & operator = (const FragTrap & src);
        virtual ~FragTrap();

        virtual void attack(const std::string & target);
        virtual void highFivesGuys() const;
};

#endif  // SCAVTRAP_HPP
