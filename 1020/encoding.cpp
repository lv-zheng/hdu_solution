#include <iostream>
#include <string>

int main()
{
	std::ios::sync_with_stdio(false);
	int t;
	std::cin >> t;
	while (t --> 0) {
		std::string s;
		std::cin >> s;
		s.push_back(0);
		char prev = 0;
		int cnt = 0;
		for (auto ch : s) {
			if (ch != prev) {
				if (cnt) {
					if (cnt > 1)
						std::cout << cnt << prev;
					else
						std::cout << prev;
				}
				prev = ch;
				cnt = 1;
			} else {
				++cnt;
			}
		}
		std::cout << std::endl;
	}
	return 0;
}
