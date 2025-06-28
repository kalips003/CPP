#include "Point.hpp"

///////////////////////////////////////////////////////////////////////////////]
Point::Point( void ) 
: x(0.0f), y(0.0f) {
}
Point::~Point( void ) {
}
Point::Point( const float& x, const float& y)
: x(x), y(y) {
}
Point::Point( const Point& other ) 
: x(other.x), y(other.y) {
}
Point& Point::operator=( const Point& other ) {
	(void)other;
	return *this;
}

///////////////////////////////////////////////////////////////////////////////]
float	Point::getX( void ) const {
	return x.toFloat();
}
float	Point::getY( void ) const {
	return y.toFloat();
}

///////////////////////////////////////////////////////////////////////////////]
// AB x AP = a.crossProductFixed(b, p)
const Fixed   Point::crossProductFixed( const Point& b, const Point& p ) const {
    Fixed abx(b.x - x);
    Fixed aby(b.y - y);
    Fixed apx(p.x - x);
    Fixed apy(p.y - y);

    return Fixed(abx * apy - aby * apx);
}
