#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <string>
#include <Weapon.hpp>

class HumanB {
    private:
        std::string m_name;
        // Subject's PDF with the example code is borked:
        // jim.setWeapon(club);
        // Here club is sent as a reference, which implies
        // that HumanB has some reference member to weapon.
        // However, HumanB doesn't take any weapons in it's constructor,
        // and having an uninitialized
        // (don't confuse initialization with assignment)
        // reference members even in constructor is considered to be an error.
        const Weapon * m_weapon;

    public:
        HumanB(const std::string & name);
        HumanB(const HumanB & src);
        HumanB & operator = (const HumanB & src);
        virtual ~HumanB();

        void setWeapon(const Weapon * weapon);
        void attack() const;
};

#endif  // HUMANB_HPP
