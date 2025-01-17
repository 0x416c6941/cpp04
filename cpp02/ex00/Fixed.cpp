#include <Fixed.hpp>
#include <iostream>

Fixed::Fixed() : m_val(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed & src) : m_val(src.m_val) {
    std::cout << "Copy constructor called" << std::endl;
}

Fixed & Fixed::operator = (const Fixed & src) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this == &src) {
        return *this;
    }
    m_val = src.m_val;
    return *this;
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits() const {
    std::cout << "getRawBits member function called" << std::endl;
    return m_val;
}

void Fixed::setRawBits(int const raw) {
    std::cout << "setRawBits member function called" << std::endl;
    m_val = raw;
}
