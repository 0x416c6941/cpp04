#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>
#include <Brain.hpp>

class Animal {
    protected:
        std::string m_type;

        Brain * m_brain;

    public:
        Animal();
        Animal(const std::string & type);
        Animal(const Animal & src);
        Animal & operator = (const Animal & src);
        virtual ~Animal();

        const std::string & getType() const;
        virtual void makeSound() const;
        Brain & get_brain();
};

#endif  // ANIMAL_HPP
