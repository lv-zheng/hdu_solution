#include <algorithm>
#include <iostream>

typedef long long int lli;

int main()
{
	std::ios::sync_with_stdio(false);
	int t;
	std::cin >> t;
	while (t --> 0) {
		int n;
		std::cin >> n;
		lli ans = 1;
		while (n --> 0) {
			lli x;
			std::cin >> x;
			ans = ans / std::__gcd(ans, x) * x;
		}
		std::cout << ans << std::endl;
	}
	return 0;
}
