#ifndef DOG_HPP
#define DOG_HPP

#include <Animal.hpp>
#include <Brain.hpp>

class Dog : public Animal {
    private:
        Brain * m_brain;

    public:
        Dog();
        Dog(const Dog & src);
        Dog & operator = (const Dog & src);
        virtual ~Dog();

        virtual void makeSound() const;
        Brain & get_brain();
};

#endif  // DOG_HPP
