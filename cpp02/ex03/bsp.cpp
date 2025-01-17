// Props to GeeksForGeeks and @tblaase :)

#include <Point.hpp>
#include <Fixed.hpp>

/**
 * Calculates the area of a triangle given by points \p p1, \p p2 and \p p3.
 * @param   p1  First point of a triangle.
 * @param   p2  Second point of a triangle.
 * @param   p3  Third point of a triangle.
 */
float calculate_area(const Point & p1, const Point & p2, const Point & p3) {
    float ret =  (p1.get_x().toFloat() * (p2.get_y().toFloat() - p3.get_y().toFloat())
                  + p2.get_x().toFloat() * (p3.get_y().toFloat() - p1.get_y().toFloat())
                  + p3.get_x().toFloat() * (p1.get_y().toFloat() - p2.get_y().toFloat()))
                 / 2;

    // Area can't be negative.
    if (ret < 0) {
        ret *= -1;
    }
    return ret;
}

bool bsp(const Point & a, const Point & b, const Point & c, const Point & point) {
    float abc = calculate_area(a, b, c),
          pab = calculate_area(point, a, b),
          pbc = calculate_area(point, b, c),
          pac = calculate_area(point, a, c);

    return pab != 0 && pbc != 0 && pac != 0 && (pab + pbc + pac) == abc;
}
