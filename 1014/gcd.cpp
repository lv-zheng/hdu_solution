#include <algorithm>
#include <iostream>
#include <iomanip>

int main()
{
	int a, b;
	while (std::cin >> a >> b) {
		std::cout << std::setw(10) << a << std::setw(10) << b
			<< "    "
			<< (std::__gcd(a, b) == 1 ? "Good Choice" : "Bad Choice")
			<< std::endl
			<< std::endl;
	}
}
