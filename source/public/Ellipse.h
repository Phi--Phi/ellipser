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
    long double arc_length(long double x1, long double x2) const;
    long double slope(point p) const;
    long double slope(long double x) const;
    static inline long double degrees(long double m)
    {
        return 180.0L * atanl(m) / std::numbers::pi_v<long double>;
    }
private:
    long double _a, _b, _c;
};
