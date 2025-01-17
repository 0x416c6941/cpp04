#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>

class Animal {
    protected:
        std::string m_type;

    public:
        Animal(const std::string & type);
        Animal(const Animal & src);
        Animal & operator = (const Animal & src);
        virtual ~Animal();

        const std::string & getType() const;
        virtual void makeSound() const;
};

#endif  // ANIMAL_HPP
