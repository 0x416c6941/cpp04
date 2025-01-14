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

        /**
         * Add a contact to the phone book.
         * If we already have more than \ref m_MAX_CONTACTS contacts,
         * the oldest one will be deleted.
         * @param   contact             Contact to add.
         * @throws  invalid_argument    \p contact contains some empty fields.
         */
        void add_contact(const Contact & contact);
        std::size_t get_contacts_cnt() const;
        /**
         * @throws  out_of_range    \p idx is out of range.
         */
        const Contact & get_contact(std::size_t idx) const;
};

#endif  // PHONEBOOK_HPP
