#include <array>
#include <iostream>

int modulus = 7;

int a, b, n;

void work()
{
	n %= 2016;
	if (n == 0)
		++n;
	if (n < 3) {
		std::cout << 1 << std::endl;
		return;
	}
	int last = 1;
	int lbst = 1;
	for (int i = 2; i < n; ++i) {
		int lcst = (a * lbst + b * last) % modulus;
		last = lbst;
		lbst = lcst;
	}
	std::cout << lbst << std::endl;
}

int main()
{
	while (std::cin >> a >> b >> n && n)
		work();
	return 0;
}
