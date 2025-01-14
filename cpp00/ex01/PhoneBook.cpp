#include <PhoneBook.hpp>
#include <cstddef>
#include <stdexcept>

PhoneBook::PhoneBook() : m_contacts_cnt(0) {
}

PhoneBook::PhoneBook(const PhoneBook & src)
    : m_contacts_cnt(src.m_contacts_cnt) {
    for (std::size_t i = 0; i < src.m_contacts_cnt; i++) {
        m_contacts[i] = src.m_contacts[i];
    }
}

PhoneBook & PhoneBook::operator = (const PhoneBook & src) {
    if (this == &src) {
        return *this;
    }
    m_contacts_cnt = src.m_contacts_cnt;
    for (std::size_t i = 0; i < src.m_contacts_cnt; i++) {
        m_contacts[i] = src.m_contacts[i];
    }
    return *this;
}

PhoneBook::~PhoneBook() {
}

void PhoneBook::add_contact(const Contact & contact) {
    // Easiest case: we have room for the new contact
    if (m_contacts_cnt < m_MAX_CONTACTS) {
        m_contacts[m_contacts_cnt++] = contact;
        return;
    }
    // Otherwise, we'll need to shift already existing contacts to the right
    // and replace the oldest contact with the new one.
    for (std::size_t i = m_MAX_CONTACTS - 1; i > 0; i--) {
        m_contacts[i] = m_contacts[i - 1];
    }
    *m_contacts = contact;
}

std::size_t PhoneBook::get_contacts_cnt() const {
    return m_contacts_cnt;
}

const Contact & PhoneBook::get_contact(std::size_t idx) const {
    if (idx >= m_contacts_cnt) {
        throw std::out_of_range("PhoneBook::get_contact(): Index out of range.");
    }
    return m_contacts[idx];
}
