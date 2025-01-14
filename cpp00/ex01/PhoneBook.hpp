#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <cstddef>
#include <Contact.hpp>
#include <string>

class PhoneBook {
    private:
        static const std::size_t m_MAX_CONTACTS = 8;
        std::size_t m_contacts_cnt;
        Contact m_contacts[m_MAX_CONTACTS];

    public:
        PhoneBook();
        PhoneBook(const PhoneBook & src);
        PhoneBook & operator = (const PhoneBook & src);
        virtual ~PhoneBook();

        void add_contact(const Contact & contact);
        std::size_t get_contacts_cnt() const;
        const Contact & get_contact(std::size_t idx) const;
};

#endif  // PHONEBOOK_HPP
