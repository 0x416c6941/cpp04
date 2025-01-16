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

        static Fixed & min(Fixed & lhs, Fixed & rhs);
        static const Fixed & min(const Fixed & lhs, const Fixed & rhs);
        static Fixed & max(Fixed & lhs, Fixed & rhs);
        static const Fixed & max(const Fixed & lhs, const Fixed & rhs);
};

std::ostream & operator << (std::ostream & os, const Fixed & a);

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

Fixed & operator ++ (Fixed & a);
Fixed operator ++ (Fixed & a, int);
Fixed & operator -- (Fixed & a);
Fixed operator -- (Fixed & a, int);

#endif  // FIXED_HPP
