#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point {

private:
    const Fixed x;
    const Fixed y;

public:
    Point( void );
    ~Point( void );
    Point( const float& x, const float& y);
    Point( const Point& other );
    Point& operator=( const Point& other );

	float	getX( void ) const;
	float	getY( void ) const;

    const Fixed   crossProductFixed( const Point& b, const Point& p ) const;
};

#endif