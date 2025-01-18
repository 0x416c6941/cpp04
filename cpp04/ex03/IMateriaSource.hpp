#ifndef IMATERIASOURCE_HPP
#define IMATERIASOURCE_HPP

#include <AMateria.hpp>
#include <string>

class IMateriaSource {
    public:
        virtual ~IMateriaSource();
        virtual void learnMateria(AMateria *) = 0;
        virtual AMateria * createMateria(const std::string & type) const = 0;
};

#endif  // IMATERIASOURCE_HPP
