#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>

class Zombie {
    private:
        std::string m_name;

    public:
        Zombie();
        Zombie(const std::string & name);
        Zombie(const Zombie & src);
        Zombie & operator = (const Zombie & src);
        virtual ~Zombie();

        void set_name(const std::string & name);
        void announce() const;
};

#endif  // ZOMBIE_HPP
