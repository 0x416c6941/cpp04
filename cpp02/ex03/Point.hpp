#ifndef POINT_HPP
#define POINT_HPP

#include <Fixed.hpp>

class Point {
    private:
        const Fixed m_x;
        const Fixed m_y;

    public:
        Point();
        Point(const float x, const float y);
        Point(const Point & src);
        Point & operator = (const Point & src);
        virtual ~Point();

        const Fixed & get_x() const;
        const Fixed & get_y() const;
};

#endif  // POINT_HPP
