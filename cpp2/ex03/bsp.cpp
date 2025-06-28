#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point) {
    Fixed   abp = a.crossProductFixed(b, point);
    Fixed   bcp = b.crossProductFixed(c, point);
    Fixed   cap = c.crossProductFixed(a, point);

    return abp.isPositif() == bcp.isPositif() && abp.isPositif() == cap.isPositif();
}