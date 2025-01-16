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

Fixed & Fixed::min(Fixed & lhs, Fixed & rhs) {
    if (lhs < rhs) {
        return lhs;
    }
    return rhs;
}

const Fixed & Fixed::min(const Fixed & lhs, const Fixed & rhs) {
    if (lhs < rhs) {
        return lhs;
    }
    return rhs;
}

Fixed & Fixed::max(Fixed & lhs, Fixed & rhs) {
    if (lhs < rhs) {
        return rhs;
    }
    return lhs;
}

const Fixed & Fixed::max(const Fixed & lhs, const Fixed & rhs) {
    if (lhs < rhs) {
        return rhs;
    }
    return lhs;
}

std::ostream & operator << (std::ostream & os, const Fixed & a) {
    os << a.toFloat();
    return os;
}

bool operator > (const Fixed & lhs, const Fixed & rhs) {
    return lhs.getRawBits() > rhs.getRawBits();
}

bool operator < (const Fixed & lhs, const Fixed & rhs) {
    return lhs.getRawBits() < rhs.getRawBits();
}

bool operator >= (const Fixed & lhs, const Fixed & rhs) {
    return lhs > rhs || lhs == rhs;
}

bool operator <= (const Fixed & lhs, const Fixed & rhs) {
    return lhs < rhs || lhs == rhs;
}

bool operator == (const Fixed & lhs, const Fixed & rhs) {
    return lhs.getRawBits() == rhs.getRawBits();
}

bool operator != (const Fixed & lhs, const Fixed & rhs) {
    return !(lhs.getRawBits() == rhs.getRawBits());
}

Fixed operator + (const Fixed & lhs, const Fixed & rhs) {
    Fixed ret;

    ret.setRawBits(lhs.getRawBits() + rhs.getRawBits());
    return ret;
}

Fixed operator - (const Fixed & lhs, const Fixed & rhs) {
    Fixed ret;

    ret.setRawBits(lhs.getRawBits() - rhs.getRawBits());
    return ret;
}

Fixed operator * (const Fixed & lhs, const Fixed & rhs) {
    return Fixed(lhs.toFloat() * rhs.toFloat());
}

Fixed operator / (const Fixed & lhs, const Fixed & rhs) {
    return Fixed(lhs.toFloat() / rhs.toFloat());
}

Fixed & operator ++ (Fixed & a) {
    a.setRawBits(a.getRawBits() + 1);
    return a;
}

Fixed operator ++ (Fixed & a, int) {
    Fixed ret(a);

    a.setRawBits(a.getRawBits() + 1);
    return ret;
}

Fixed & operator -- (Fixed & a) {
    a.setRawBits(a.getRawBits() - 1);
    return a;
}

Fixed operator -- (Fixed & a, int) {
    Fixed ret(a);

    a.setRawBits(a.getRawBits() - 1);
    return ret;
}
