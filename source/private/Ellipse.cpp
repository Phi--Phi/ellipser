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

long double ellipse::arc_length(long double t1, long double t2) const
{
	const long double phi = 1.0L - powl(_b/_a, 2.0L);
	const long double T1 = std::ellint_2l(phi, t1-(0.5L*std::numbers::pi_v<long double>));
	const long double T2 = std::ellint_2l(phi, t2-(0.5L*std::numbers::pi_v<long double>));
	return _a * (T2- T1);
}

long double ellipse::slope(point p) const
{
	return -(_b*_b*p.x) / (_a*_a*p.y);
}

long double ellipse::slope(long double t) const
{
	return slope(point(_a*cosl(t), _b*sinl(t)));
}

long double ellipse::bin_search_x2(long double t1, long double lower_t2, long double upper_t2, long double target_arc_length, long double tolerance) const
{
	const long double midpoint = (upper_t2+lower_t2) / 2.0L;
	const long double current_arc_length = arc_length(t1, midpoint);
	const long double delta = current_arc_length - target_arc_length;
	
	if (fabsl(upper_t2 - lower_t2) < tolerance)
	{
		return lower_t2;
	}

	if (fabsl(delta) < tolerance)
	{
		return midpoint;
	}

	if (current_arc_length > target_arc_length)
	{
		return bin_search_x2(t1, lower_t2, midpoint, target_arc_length, tolerance);
	}

	return bin_search_x2(t1, midpoint, upper_t2, target_arc_length, tolerance);
	
}
