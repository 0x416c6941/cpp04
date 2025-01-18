#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <ICharacter.hpp>
#include <string>
#include <cstddef>
#include <AMateria.hpp>
#include <World.hpp>

class Character : public ICharacter {
    private:
        std::string m_name;

        static const std::size_t m_MATERIAS_SIZE = 4;
        AMateria * m_materias[m_MATERIAS_SIZE];
        std::size_t m_equipped_materias;

        World & m_world;    // Where to store dropped (unequiped) materias.

    public:
        Character(const std::string & name, World & world);
        Character(const Character & src);
        Character & operator = (const Character & src);
        virtual ~Character();

        virtual const std::string & getName() const;
        virtual void equip(AMateria * m);
        virtual void unequip(int idx);
        virtual void use(int idx, ICharacter & target) const;
};

#endif  // CHARACTER_HPP
