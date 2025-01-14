#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact {
    private:
        std::string m_name, m_last_name, m_phone, m_secret;

    public:
        Contact();
        Contact(const Contact & src);
        Contact & operator = (const Contact & src);
        virtual ~Contact();

        void set_name(const std::string & name);
        void set_last_name(const std::string & last_name);
        /**
         * Sets a phone number of the contact.
         * @param   phone               New phone number of the contact.
         * @throws  invalid_argument    \p phone contains illegal characters
         *                              (it's invalid).
         */
        void set_phone(const std::string & phone);
        void set_secret(const std::string & secret);

        const std::string & get_name() const;
        const std::string & get_last_name() const;
        const std::string & get_phone() const;
        const std::string & get_secret() const;
};

#endif  // CONTACT_HPP
