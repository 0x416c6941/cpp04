#ifndef ICE_HPP
#define ICE_HPP

#include <AMateria.hpp>
#include <ICharacter.hpp>

class Ice : public AMateria {
    public:
        Ice();
        Ice(const Ice & src);
        Ice & operator = (const Ice & src);
        virtual ~Ice();

        virtual Ice * clone() const;
        virtual void use(ICharacter & target) const;
};

#endif  // ICE_HPP
