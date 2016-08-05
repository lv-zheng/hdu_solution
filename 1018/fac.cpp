#include <cmath>
#include <iostream>

const int N = 11000000;
const int interval = 10;

typedef long double ldb;

ldb mem[1200000];

ldb eps = 1e-7;

void init()
{
	ldb ans = 0;
	mem[0] = 0;
	for (int i = 1; i < N; ++i) {
		ans += std::log10(i);
		if (i % interval == 0)
			mem[i / interval] = ans;
	}
}

void work(int a)
{
	int s = a / interval * interval;
	ldb ans = mem[a / interval];
	for (int i = s + 1; i <= a; ++i)
		ans += std::log10(i);
	std::cout << (int) (std::floor(ans + eps) + 1) << std::endl;
}

int main()
{
	std::ios::sync_with_stdio(false);
	init();
	int n;
	std::cin >> n;
	for (int i = 0; i < n; ++i) {
		int x;
		std::cin >> x;
		work(x);
	}
}
