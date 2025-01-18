#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <string>
#include <Weapon.hpp>

class HumanB {
    private:
        std::string m_name;
        const Weapon * m_weapon;

    public:
        HumanB(const std::string & name);
        HumanB(const HumanB & src);
        HumanB & operator = (const HumanB & src);
        virtual ~HumanB();

        void setWeapon(const Weapon & weapon);
        void setWeapon(const Weapon * weapon);
        void attack() const;
};

#endif  // HUMANB_HPP
