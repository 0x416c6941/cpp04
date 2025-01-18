#ifndef CURE_HPP
#define CURE_HPP

#include <AMateria.hpp>
#include <ICharacter.hpp>

class Cure : public AMateria {
    public:
        Cure();
        Cure(const Cure & src);
        Cure & operator = (const Cure & src);
        virtual ~Cure();

        virtual Cure * clone() const;
        virtual void use (ICharacter & target) const;
};

#endif  // CURE_HPP
