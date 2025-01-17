#include <Brain.hpp>
#include <cstddef>
#include <string>
#include <stdexcept>

Brain::Brain() : m_ideas_cnt(0) {
    // Probably unneeded stuff.
    for (std::size_t i = 0; i < m_IDEAS_SIZE; i++) {
        m_ideas[i] = std::string();
    }
}

Brain::Brain(const Brain & src) : m_ideas_cnt(src.m_ideas_cnt) {
    for (std::size_t i = 0; i < src.m_ideas_cnt; i++) {
        m_ideas[i] = src.m_ideas[i];
    }
    for (std::size_t i = src.m_ideas_cnt; i < m_IDEAS_SIZE; i++) {
        m_ideas[i] = std::string();
    }
}

Brain & Brain::operator = (const Brain & src) {
    if (this == &src) {
        return *this;
    }
    m_ideas_cnt = src.m_ideas_cnt;
    for (std::size_t i = 0; i < src.m_ideas_cnt; i++) {
        m_ideas[i] = src.m_ideas[i];
    }
    for (std::size_t i = src.m_ideas_cnt; i < m_IDEAS_SIZE; i++) {
        m_ideas[i] = std::string();
    }
    return *this;
}

Brain::~Brain() {
}

std::size_t Brain::get_max_ideas_cnt() const {
    return m_IDEAS_SIZE;
}

std::size_t Brain::get_ideas_cnt() const {
    return m_ideas_cnt;
}

const std::string & Brain::get_idea(size_t idx) const {
    if (idx >= m_ideas_cnt) {
        throw std::domain_error("Brain::get_idea(): idx is out of range.");
    }
    return m_ideas[idx];
}

void Brain::add_idea(const std::string & idea) {
    std::size_t i = m_ideas_cnt;

    // Shifting ideas to the right.
    if (i >= m_IDEAS_SIZE) {
        i = m_IDEAS_SIZE - 1;
    }
    while (i > 0) {
        m_ideas[i] = m_ideas[i - 1];
        i--;
    }
    *m_ideas = idea;
}
