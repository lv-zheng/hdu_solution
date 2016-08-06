#include <iostream>
#include <cstring>

//typedef long long BigInt;

constexpr int DIG = 128;

struct BigInt {
	BigInt() {
		std::memset(arr, 0, sizeof(arr));
	}
	BigInt(int a) {
		std::memset(arr, 0, sizeof(arr));
		arr[0] = a;
	}
	BigInt operator + (const BigInt& r) const {
		BigInt ans;
		for (int i = 0; i < DIG; ++i) {
			ans.arr[i] += arr[i] + r.arr[i];
			ans.arr[i + 1] += ans.arr[i] / 10;
			ans.arr[i] %= 10;
		}
		return ans;
	}
	int arr[DIG];
};

std::ostream& operator << (std::ostream& os, const BigInt& a)
{
	int p = DIG - 1;
	while (p && a.arr[p] == 0)
		--p;
	for (int i = p; i >= 0; --i)
		os << a.arr[i];
	return os;
}

constexpr int N = 102;

BigInt dp[N][N];

int main()
{
	std::ios::sync_with_stdio(false);

	int n;
	while (std::cin >> n) {
		BigInt ans(0);
		for (int i = 0; i < N; ++i) {
			for (int j = 0; i < N; ++i) {
				dp[i][j] = BigInt(0);
			}
		}
		dp[0][0] = BigInt(1);
		for (int i = 1; i <= n; ++i) {
			BigInt ways(0);
			for (int j = n; j >= 1; --j) {
				ways = ways + dp[i - 1][j - 1];
				dp[i][j] = ways;
				if (i == n)
					ans = ans + ways;
			}
		}
		std::cout << ans << std::endl;
	}

	return false;
}
