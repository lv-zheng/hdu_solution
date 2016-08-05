#include <iostream>
#include <string>
#include <sstream>

int n, m;

void work()
{
	int ans = 0;
	for (int a = 1; a < n - 1; ++a) {
		for (int b = a + 1; b < n; ++b) {
			if ((a * a + b * b + m) % (a * b) == 0)
				++ans;
		}
	}
	std::cout << ans << std::endl;
}

int main()
{
	std::ios::sync_with_stdio(false);
	int blks;
	std::cin >> blks;
	std::string line;
	std::getline(std::cin, line);
	int t = 0;
	int kase = 0;
	while (std::getline(std::cin, line)) {
		if (line.empty()) {
			kase = 0;
			if (t++)
				std::cout << '\n';
			continue;
		}
		std::istringstream iss(line);
		iss >> n >> m;
		if (n == 0 && m == 0)
			continue;
		std::cout << "Case " << ++kase << ": ";
		work();
	}
	return 0;
}
