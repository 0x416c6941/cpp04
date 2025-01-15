#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed {
    private:
        int m_val;
        static const int m_FRACT_BITS = 8;

    public:
        Fixed();
        Fixed(const Fixed & src);
        Fixed & operator = (const Fixed & src);
        virtual ~Fixed();

        int getRawBits() const;
        void setRawBits(int const raw);
};

#endif  // FIXED_HPP
