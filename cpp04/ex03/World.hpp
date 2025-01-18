#ifndef WORLD_HPP
#define WORLD_HPP

#include <AMateria.hpp>

// When character drops (unequips) a materia, it will be saved in a world.
class World {
    private:
        AMateria ** m_materias;
        std::size_t m_materias_size;

    public:
        World();
        World(const World & src);
        World & operator = (const World & src);
        virtual ~World();

        void save_materia(AMateria * m);
};

#endif  // WORLD_HPP
