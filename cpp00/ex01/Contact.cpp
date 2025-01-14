#include <Contact.hpp>
#include <string>
#include <cctype>
#include <iterator>
#include <stdexcept>

Contact::Contact()
    : m_name(), m_last_name(), m_nickname(), m_phone(), m_secret() {
}

Contact::Contact(const std::string & name, const std::string & last_name,
                 const std::string & nickname,
                 const std::string & phone, const std::string & secret) {
    set_name(name);
    set_last_name(last_name);
    set_nickname(nickname);
    set_phone(phone);
    set_secret(secret);
}


Contact::Contact(const Contact & src)
    : m_name(src.m_name), m_last_name(src.m_last_name),
      m_nickname(src.m_nickname),
      m_phone(src.m_phone), m_secret(src.m_secret) {
}

Contact & Contact::operator = (const Contact & src) {
    if (this == &src) {
        return *this;
    }
    m_name = src.m_name;
    m_last_name = src.m_last_name;
    m_nickname = src.m_nickname;
    m_phone = src.m_phone;
    m_secret = src.m_secret;
    return *this;
}

Contact::~Contact() {
}

void Contact::set_name(const std::string & name) {
    m_name = name;
}

void Contact::set_last_name(const std::string & last_name) {
    m_last_name = last_name;
}

void Contact::set_nickname(const std::string & nickname) {
    m_nickname = nickname;
}

void Contact::set_phone(const std::string & phone) {
    const std::string allowed = "+() -";

    for (std::string::const_iterator it = phone.begin(); it != phone.end(); ++it) {
        if (!std::isdigit(*it) && allowed.find(*it) == std::string::npos) {
            throw std::invalid_argument("Contact::set_phone(): Found illegal character.");
        }
    }
    m_phone = phone;
}

void Contact::set_secret(const std::string & secret) {
    m_secret = secret;
}

const std::string & Contact::get_name() const {
    return m_name;
}

const std::string & Contact::get_last_name() const {
    return m_last_name;
}

const std::string & Contact::get_nickname() const {
    return m_nickname;
}

const std::string & Contact::get_phone() const {
    return m_phone;
}

const std::string & Contact::get_secret() const {
    return m_secret;
}
