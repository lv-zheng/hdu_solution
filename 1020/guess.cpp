#include <iostream>

const char s[][4] = { "no", "yes" };

int main()
{
	std::ios::sync_with_stdio(false);
	int x;
	while (std::cin >> x)
		std::cout << s[x % 4 == 2] << std::endl;
	return 0;
}
