#include <Fixed.hpp>
#include <iostream>
#include <cmath>

Fixed::Fixed() : m_val(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int num) : m_val (num << m_FRACT_BITS) {
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const double num) {
    /*
    double num_non_const = num;

    std::cout << "Float constructor called" << std::endl;
    m_val = num_non_const;
    num_non_const -= m_val;
    m_val <<= m_FRACT_BITS;
    for (int i = 0; i < m_FRACT_BITS; i++) {
        num_non_const *= 2; // Shifting bits after floating-point to the left
    }
    m_val += roundf(num_non_const);
     */
    // Literally the same code, but cleaner and probably faster
    // (props to @tblaase).
    std::cout << "Float constructor called" << std::endl;
    m_val = roundf(num * (1 << m_FRACT_BITS));
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

float Fixed::toFloat() const {
    /*
    float fixed_point = m_val & m_MASK;

    for (int i = 0; i < m_FRACT_BITS; i++) {
        fixed_point /= 2;
    }
    return (m_val >> m_FRACT_BITS) + fixed_point;
     */
    // Again, literally the same thing, but faster and cleaner
    // (thanks to @tblaase).
    return (float) m_val / (float) (1 << m_FRACT_BITS);
}

int Fixed::toInt() const {
    return m_val >> m_FRACT_BITS;
}

std::ostream & operator << (std::ostream & os, const Fixed & fixed) {
    os << fixed.toFloat();
    return os;
}
