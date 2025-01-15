#ifndef HUMANA_HPP
#define HUMANA_HPP

#include <string>
#include <Weapon.hpp>

class HumanA {
    private:
        std::string m_name;
        Weapon & m_weapon;

    public:
        HumanA(const std::string & name, Weapon & weapon);
        HumanA(const HumanA & src);
        HumanA & operator = (const HumanA & src);
        virtual ~HumanA();

        void attack() const;
};

#endif  // HUMANA_HPP
