#include <iostream>
#include <string>
#include <unordered_map>

int n;

void work()
{
	std::unordered_map<std::string, int> map;
	for (int i = 0; i < n; ++i) {
		std::string s;
		std::cin >> s;
		++map[s];
	}
	const std::string *ans = nullptr;
	int count = 0;
	for (auto& p : map) {
		if (p.second > count) {
			count = p.second;
			ans = &p.first;
		}
	}
	std::cout << *ans << std::endl;
}

int main()
{
	while (std::cin >> n && n)
		work();
	return 0;
}
