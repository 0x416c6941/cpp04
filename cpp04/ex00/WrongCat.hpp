#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include <WrongAnimal.hpp>

class WrongCat : public WrongAnimal {
    public:
        WrongCat();
        WrongCat(const WrongCat & src);
        WrongCat & operator = (const WrongCat & src);
        virtual ~WrongCat();

        virtual void makeSound() const;
};

#endif  // WRONGCAT_HPP
