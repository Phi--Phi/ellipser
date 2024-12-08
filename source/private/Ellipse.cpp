#include "Ellipse.h"

ellipse::ellipse(long double a, long double b) : _a(a), _b(b)
{
    _c = sqrtl(a*a - b*b);
}

long double ellipse::eccentricity() const
{
    return _c / _a;
}

long double ellipse::semilatus_rectum() const
{
    return _b*_b / _a;
}

long double ellipse::perimeter() const
{
    return 4*_a*std::comp_ellint_2l(eccentricity());
}

long double ellipse::area() const
{
    return std::numbers::pi_v<long double>*_a*_b;
}

long double ellipse::arc_length(long double x1, long double x2) const
{
    const long double phi = 1.0L - (_a*_a/_b*_b);
    return _b * (std::ellint_2l(acosl(x2/_a), phi) - std::ellint_2l(acosl(x1/_a), phi));
}

long double ellipse::slope(point p) const
{
    return -(_b*_b*p.x) / (_a*_a*p.y);
}

long double ellipse::slope(long double x) const
{
    return slope(point(x, sqrtl((_a*_a)-(x*x))*_b/_a));
}
