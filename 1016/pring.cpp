#include <cstring>
#include <iostream>
#include <bitset>

std::bitset<101> is_prime;
int n;
bool used[100];
int seq[100];

bool test_prime(int a)
{
	for (int i = 2; i < a / 2; ++i) {
		if (a % i == 0)
			return false;
	}
	return true;
}

void dfs(int p)
{
	if (p == n) {
		if (!is_prime[seq[n - 1] + seq[0]])
			return;
		for (int i = 0; i < n; ++i) {
			std::cout << seq[i] << " \n"[i == n - 1];
		}
	}
	for (int i = 1; i <= n; ++i) {
		if (used[i])
			continue;
		if (!is_prime[seq[p - 1] + i])
			continue;
		used[i] = true;
		seq[p] = i;
		dfs(p + 1);
		used[i] = false;
	}
}

void work()
{
	std::memset(used, 0, sizeof(used));
	seq[0] = 1;
	used[1] = true;
	dfs(1);
}

int main()
{
	std::ios::sync_with_stdio(false);
	for (int i = 2; i <= 100; ++i) {
		is_prime[i] = test_prime(i);
	}
	int kase = 0;
	while (std::cin >> n) {
		std::cout << "Case " << ++kase << ":\n";
		work();
		std::cout << '\n';
	}
	return 0;
}
