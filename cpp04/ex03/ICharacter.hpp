#ifndef ICHARACTER_HPP
#define ICHARACTER_HPP

#include <string>
#include <AMateria.hpp>

// Classes AMateria and ICharacter both refer to each other.
class AMateria;

class ICharacter {
    public:
        virtual ~ICharacter();

        virtual const std::string & getName() const = 0;
        virtual void equip(AMateria * m) = 0;
        virtual void unequip(int idx) = 0;
        virtual void use(int idx, ICharacter & target) const = 0;
};

#endif  // ICHARACTER_HPP
