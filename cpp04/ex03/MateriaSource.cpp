#include <MateriaSource.hpp>
#include <cstddef>
#include <AMateria.hpp>
#include <string>

MateriaSource::MateriaSource() : m_learnt_materias(0) {
    for (std::size_t i = 0; i < m_MATERIAS_SIZE; i++) {
        m_materias[i] = NULL;
    }
}

MateriaSource::MateriaSource(const MateriaSource & src) : m_learnt_materias(src.m_learnt_materias) {
    for (std::size_t i = 0; i < src.m_learnt_materias; i++) {
        m_materias[i] = src.m_materias[i]->clone();
    }
    for (std::size_t i = src.m_learnt_materias; i < m_MATERIAS_SIZE; i++) {
        m_materias[i] = NULL;
    }
}

MateriaSource & MateriaSource::operator = (const MateriaSource & src) {
    if (this == &src) {
        return *this;
    }
    m_learnt_materias = src.m_learnt_materias;
    for (std::size_t i = 0; i < src.m_learnt_materias; i++) {
        m_materias[i] = src.m_materias[i]->clone();
    }
    for (std::size_t i = src.m_learnt_materias; i < m_MATERIAS_SIZE; i++) {
        m_materias[i] = NULL;
    }
    return *this;
}

#include <iostream>

MateriaSource::~MateriaSource() {
    for (std::size_t i = 0; i < m_learnt_materias; i++) {
        delete m_materias[i];
    }
}

void MateriaSource::learnMateria(AMateria * m) {
    // Already learnt maximum amount of materias to possibly learn.
    if (m_learnt_materias >= m_MATERIAS_SIZE) {
        return;
    }
    m_materias[m_learnt_materias++] = m;
}

AMateria * MateriaSource::createMateria(const std::string & type) const {
    for (std::size_t i = 0; i < m_learnt_materias; i++) {
        if (m_materias[i]->getType().compare(type) == 0) {
            return m_materias[i]->clone();
        }
    }
    // Materia wasn't learnt yet.
    return NULL;
}
