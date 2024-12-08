#include <iostream>
#include <stdint.h>
#include <vector>
#include "Ellipse.h"

int main()
{
	long double a, b;
	uint16_t n;

	std::cout << "Welcome to Ellipser!" << std::endl;
	std::cout << "Enter ellipse characteristics:" << std::endl;
	std::cout << "a= ";
	std::cin >> a;
	std::cout << "b= ";
	std::cin >> b;
	std::cout << "n= ";
	std::cin >> n;

	ellipse eli(a, b);

	long double e, l, C, A, target_arc_length;

	e = eli.eccentricity();
	l = eli.semilatus_rectum();
	C = eli.perimeter();
	A = eli.area();
	target_arc_length = eli.perimeter() / (4 * n);

	std::cout << "e: " << e << std::endl;
	std::cout << "l: " << l << std::endl;
	std::cout << "C: " << C << std::endl;
	std::cout << "A: " << A << std::endl;
	std::cout << "target arclength: " << target_arc_length << std::endl;
	std::cout << "t values:" << std:: endl;

	std::vector<long double> t_values;
	constexpr long double tolerance = 0.00000001L;

	t_values.resize(n, 0.0L);
	for (std::size_t i = 0; i < t_values.size(); i++)
	{
		if (i == 0)
		{
			t_values[i] = eli.bin_search_x2(0.0L, 0.0L, std::numbers::pi_v<long double>, target_arc_length, tolerance);
		}
		else
		{
			t_values[i] = eli.bin_search_x2(t_values[i-1], t_values[i-1], std::numbers::pi_v<long double>, target_arc_length, tolerance);
		}

		std::cout << t_values[i] << std::endl;
	}

	std::cout << "angles:" << std::endl;

	for (auto it : t_values)
	{
		std::cout << ellipse::degrees(eli.slope(it)) << std::endl;
	}

	return 0;
}
