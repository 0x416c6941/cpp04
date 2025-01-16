#ifndef FIXED_HPP
#define FIXED_HPP

#include <ostream>

class Fixed {
    private:
        int m_val;

        static const int m_FRACT_BITS = 8;

    public:
        Fixed();
        Fixed(const int num);
        Fixed(const double num);
        Fixed(const Fixed & src);
        Fixed & operator = (const Fixed & src);
        virtual ~Fixed();

        int getRawBits() const;
        void setRawBits(int const raw);

        float toFloat() const;
        int toInt() const;
};

std::ostream & operator << (std::ostream & os, const Fixed & fixed);

bool operator > (const Fixed & lhs, const Fixed & rhs);
bool operator < (const Fixed & lhs, const Fixed & rhs);
bool operator >= (const Fixed & lhs, const Fixed & rhs);
bool operator <= (const Fixed & lhs, const Fixed & rhs);
bool operator == (const Fixed & lhs, const Fixed & rhs);
bool operator != (const Fixed & lhs, const Fixed & rhs);

Fixed operator + (const Fixed & lhs, const Fixed & rhs);
Fixed operator - (const Fixed & lhs, const Fixed & rhs);
Fixed operator * (const Fixed & lhs, const Fixed & rhs);
Fixed operator / (const Fixed & lhs, const Fixed & rhs);

#endif  // FIXED_HPP
