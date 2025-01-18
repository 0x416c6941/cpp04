#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <string>
#include <ICharacter.hpp>

// Classes AMateria and ICharacter both refer to each other.
class ICharacter;

class AMateria {
    protected:
        std::string m_type;

    public:
        AMateria(const std::string & type);
        AMateria(const AMateria & src);
        AMateria & operator = (const AMateria & src);
        virtual ~AMateria();

        const std::string & getType() const;
        virtual AMateria * clone() const = 0;
        virtual void use(ICharacter & target) const = 0;
};

#endif  // AMATERIA_HPP
