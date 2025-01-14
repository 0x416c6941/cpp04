#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>

class Weapon {
    private:
        std::string m_type;

    public:
        Weapon(const std::string & type);
        Weapon(const Weapon & src);
        Weapon & operator = (const Weapon & src);
        virtual ~Weapon();

        const std::string & getType() const;
        void setType(const std::string & type);
};

#endif  // WEAPON_HPP
