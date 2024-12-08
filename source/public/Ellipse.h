#pragma once
#include <cmath>
#include <numbers>

struct point{
	long double x, y;
	point() : x(0.0L), y(0.0L){}
	point(long double inx, long double iny) : x(inx), y(iny){}
};

class ellipse
{
public:
	ellipse(long double a, long double b);
	long double eccentricity() const;
	long double semilatus_rectum() const;
	long double perimeter() const;
	long double area() const;
	long double arc_length(long double t1, long double t2) const;
	long double slope(point p) const;
	long double slope(long double t) const;
	static inline long double degrees(long double slope)
	{
		return 180.0L * atanl(slope) / std::numbers::pi_v<long double>;
	}
	long double bin_search_x2(long double t1, long double lower_t2, long double upper_t2, long double target_arc_length, long double tolerance) const;
private:
	long double _a, _b, _c;
};
