#include <Point.hpp>
#include <Fixed.hpp>

Point::Point() : m_x(), m_y() {
}

Point::Point(const float x, const float y) : m_x(x), m_y(y) {
}

Point::Point(const Point & src) : m_x(src.m_x), m_y(src.m_y) {
}

Point & Point::operator = (const Point & src) {
    if (this == &src) {
        return *this;
    }
    Point(src.m_x.toFloat(), src.m_y.toFloat());
    return *this;
}

Point::~Point() {
}

const Fixed & Point::get_x() const {
    return m_x;
}

const Fixed & Point::get_y() const {
    return m_y;
}
