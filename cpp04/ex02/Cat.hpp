#ifndef CAT_HPP
#define CAT_HPP

#include <Animal.hpp>
#include <Brain.hpp>

class Cat : public Animal {
    private:
        Brain * m_brain;

    public:
        Cat();
        Cat(const Cat & src);
        Cat & operator = (const Cat & src);
        virtual ~Cat();

        virtual void makeSound() const;
        Brain & get_brain();
};

#endif  // CAT_HPP
