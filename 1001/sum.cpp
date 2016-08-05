#include <iostream>

int main()
{
	std::ios::sync_with_stdio(false);
	long long n;
	while (std::cin >> n)
		std::cout << n * (n + 1) / 2 << std::endl << std::endl;
	return 0;
}
