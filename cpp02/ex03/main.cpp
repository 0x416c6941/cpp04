#include <Point.hpp>
#include <cassert>

// We can't have another header file due to subject's PDF limitation.
bool bsp(const Point & a, const Point & b, const Point & c, const Point & point);

int main(void) {
    assert(bsp(Point(3.0f, 1.5f), Point(5.0f, 7.0f), Point(15.0f, 0.0f),
               Point(7.0f, 5.0f)) == true);
    assert(bsp(Point(3.0f, 1.5f), Point(5.0f, 7.0f), Point(15.0f, 0.0f),
               Point(7.0f, 0.0f)) == false);
    assert(bsp(Point(0.0f, 0.0f), Point(5.0f, 5.0f), Point(15.0f, 10.0f),
               Point(1.0f, 1.0f)) == false);
    return 0;
}
