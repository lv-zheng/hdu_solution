#include <iostream>

int main()
{
	std::ios::sync_with_stdio(false);
	int a, b;
	while (std::cin >> a >> b)
		std::cout << a + b << std::endl;
	return 0;
}
