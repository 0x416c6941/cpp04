#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <string>

class WrongAnimal {
    protected:
        std::string m_type;

    public:
        WrongAnimal();
        WrongAnimal(const std::string & type);
        WrongAnimal(const WrongAnimal & src);
        WrongAnimal & operator = (const WrongAnimal & src);
        virtual ~WrongAnimal();

        const std::string & getType() const;
        virtual void makeSound() const;
};

#endif  // WRONGANIMAL_HPP
