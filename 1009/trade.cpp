#include <iostream>
#include <algorithm>
#include <utility>
#include <iomanip>

typedef std::pair<int, int> pii;
pii arr[1100];

bool comp(pii a, pii b)
{
	return a.first * b.second > a.second * b.first;
}

int n, m;

int main()
{
	while (std::cin >> m >> n && ~n) {
		for (int i = 0; i < n; ++i) {
			std::cin >> arr[i].first >> arr[i].second;
		}
		std::sort(arr, arr + n, comp);
		int remain = m;
		long double got = 0;
		for (int i = 0; i < n; ++i) {
			if (remain > arr[i].second) {
				got += arr[i].first;
				remain -= arr[i].second;
			} else {
				got += (long double) arr[i].first / arr[i].second * remain;
				remain = 0;
				break;
			}
		}
		std::cout << std::fixed << std::setprecision(3) << got + 1e-8 << std::endl;
	}
	return 0;
}
