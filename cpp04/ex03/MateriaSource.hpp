#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include <IMateriaSource.hpp>
#include <cstddef>
#include <AMateria.hpp>
#include <string>

class MateriaSource : public IMateriaSource {
    private:
        static const std::size_t m_MATERIAS_SIZE = 4;
        const AMateria * m_materias[m_MATERIAS_SIZE];
        std::size_t m_learnt_materias;

    public:
        MateriaSource();
        MateriaSource(const MateriaSource & src);
        MateriaSource & operator = (const MateriaSource & src);
        virtual ~MateriaSource();

        virtual void learnMateria(AMateria * m);
        virtual AMateria * createMateria(const std::string & type) const;
};

#endif  // MATERIASOURCE_HPP
