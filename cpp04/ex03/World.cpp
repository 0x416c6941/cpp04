#include <World.hpp>
#include <cstddef>
#include <AMateria.hpp>

World::World() : m_materias(NULL), m_materias_size(0) {
}

World::World(const World & src) : m_materias_size(src.m_materias_size) {
    m_materias = new AMateria *[src.m_materias_size];
    for (std::size_t i = 0; i < src.m_materias_size; i++) {
        m_materias[i] = src.m_materias[i]->clone();
    }
}

World & World::operator = (const World & src) {
    if (this == &src) {
        return *this;
    }
    m_materias = new AMateria *[src.m_materias_size];
    for (std::size_t i = 0; i < src.m_materias_size; i++) {
        m_materias[i] = src.m_materias[i]->clone();
    }
    m_materias_size = src.m_materias_size;
    return *this;
}

World::~World() {
    for (std::size_t i = 0; i < m_materias_size; i++) {
        delete m_materias[i];
    }
    delete [] m_materias;
}

void World::save_materia(AMateria * m) {
    AMateria ** new_storage;

    for (std::size_t i = 0; i < m_materias_size; i++) {
        // This materia was already saved.
        if (m_materias[i] == m) {
            return;
        }
    }
    new_storage = new AMateria *[m_materias_size + 1];
    for (std::size_t i = 0; i < m_materias_size; i++) {
        new_storage[i] = m_materias[i];
    }
    new_storage[m_materias_size++] = m;
    delete [] m_materias;
    m_materias = new_storage;
}
