#include <iostream>
#include <cstring>
#include <string>

std::string s1, s2;
int a[2000];
int b[2000];

void work()
{
	std::memset(a, 0, sizeof(a));
	std::memset(b, 0, sizeof(b));
	for (unsigned i = 0; i < s1.size(); ++i)
		a[s1.size() - 1 - i] = s1[i] - '0';
	for (unsigned i = 0; i < s2.size(); ++i)
		b[s2.size() - 1 - i] = s2[i] - '0';
	for (int i = 0; i < 1200; ++i) {
		int s = a[i] + b[i];
		a[i] = s % 10;
		a[i + 1] += s / 10;
	}
	int p = 1200;
	while (p > 0 && a[p] == 0)
		--p;
	std::cout << s1 << " + " << s2 << " = ";
	for (int i = p; i >= 0; --i)
		std::cout << a[i];
	std::cout << std::endl;
}

int main()
{
	std::ios::sync_with_stdio(false);
	int t = 0;
	std::cin >> t;
	for (int i = 0; i < t; ++i) {
		std::cout << "Case " << i + 1 << ":" << std::endl;
		std::cin >> s1 >> s2;
		work();
		if (i != t - 1)
			std::cout << std::endl;
	}
	return 0;
}
