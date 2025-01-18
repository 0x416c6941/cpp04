#include <Character.hpp>
#include <string>
#include <cstddef>
#include <World.hpp>
#include <AMateria.hpp>
#include <iostream>
#include <ICharacter.hpp>

Character::Character(const std::string & name) : m_name(name),
                                                 m_equipped_materias(0),
                                                 m_world(NULL) {
    for (std::size_t i = 0; i < m_MATERIAS_SIZE; i++) {
        m_materias[i] = NULL;
    }
}

Character::Character(const std::string & name, World & world) : m_name(name),
                                                                m_equipped_materias(0),
                                                                m_world(&world) {
    for (std::size_t i = 0; i < m_MATERIAS_SIZE; i++) {
        m_materias[i] = NULL;
    }
}

Character::Character(const std::string & name, World * world) : m_name(name),
                                                                m_equipped_materias(0),
                                                                m_world(world) {
    for (std::size_t i = 0; i < m_MATERIAS_SIZE; i++) {
        m_materias[i] = NULL;
    }
}

Character::Character(const Character & src) : m_name(src.m_name),
                                              m_equipped_materias(src.m_equipped_materias),
                                              m_world(src.m_world) {
    for (std::size_t i = 0; i < src.m_equipped_materias; i++) {
        m_materias[i] = src.m_materias[i]->clone();
    }
    for (std::size_t i = src.m_equipped_materias; i < m_MATERIAS_SIZE; i++) {
        m_materias[i] = NULL;
    }
}

Character & Character::operator = (const Character & src) {
    if (this == &src) {
        return *this;
    }
    m_name = src.m_name;
    for (std::size_t i = 0; i < src.m_equipped_materias; i++) {
        m_materias[i] = src.m_materias[i]->clone();
    }
    for (std::size_t i = src.m_equipped_materias; i < m_MATERIAS_SIZE; i++) {
        m_materias[i] = NULL;
    }
    m_equipped_materias = src.m_equipped_materias;
    m_world = src.m_world;
    return *this;
}

Character::~Character() {
    for (std::size_t i = 0; i < m_equipped_materias; i++) {
        delete m_materias[i];
    }
}

const std::string & Character::getName() const {
    return m_name;
}

void Character::equip(AMateria * m) {
    // Inventory is full.
    if (m_equipped_materias >= m_MATERIAS_SIZE) {
        return;
    }
    for (std::size_t i = 0; i < m_equipped_materias; i++) {
        // This materia was already equipped.
        if (m_materias[i] == m) {
            return;
        }
    }
    // We don't need to clone the materia, but equip it as it is, right?
    m_materias[m_equipped_materias++] = m;
}

void Character::unequip(int idx) {
    // We don't have an equipped materia with such index.
    if (idx < 0 || (std::size_t) idx >= m_equipped_materias) {
        return;
    }
    // Unequipping the materia
    // and shifting previously equipped materias to the left.
    if (m_world != NULL) {
        m_world->save_materia(m_materias[idx]);
    }
    else {
        std::cerr << "Character::unequip(): Warning:"
                  << " m_world wasn't specified during object creation."
                  << " Materia was destroyed directly." << std::endl;
        delete m_materias[idx];
    }
    for (std::size_t i = (std::size_t) idx; i < m_MATERIAS_SIZE - 1; i++) {
        m_materias[i] = m_materias[i + 1];
    }
    m_materias[m_MATERIAS_SIZE - 1] = NULL;
    m_equipped_materias--;
}

void Character::use(int idx, ICharacter & target) const {
    // We don't have an equipped materia with such index.
    if (idx < 0 || (std::size_t) idx >= m_equipped_materias) {
        return;
    }
    m_materias[idx]->use(target);
}
