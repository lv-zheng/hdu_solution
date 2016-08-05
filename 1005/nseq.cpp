#include <array>
#include <iostream>

int modulus = 7;

int a, b, n;

typedef std::array<int, 4> Mat;

Mat mmul(const Mat& a, const Mat& b)
{
	Mat ans{0, 0, 0, 0};
	for (int i = 0; i < 2; ++i) {
		for (int j = 0; j < 2; ++j) {
			for (int k = 0; k < 2; ++k) {
				ans[i * 2 + j] += a[i * 2 + k] * b[k * 2 + j];
				ans[i * 2 + j] %= modulus;
			}
		}
	}
	return ans;
}

Mat mpower(const Mat& base, int p)
{
	Mat ans{1, 0, 0, 1};
	if (p == 0)
		return ans;
	if (p == 1)
		return base;
	Mat h = mpower(base, p / 2);
	ans = mmul(h, h);
	if (p % 2)
		ans = mmul(ans, base);

	return ans;
}

void work()
{
	if (n < 3) {
		std::cout << 1 << std::endl;
		return;
	}
	Mat base{0, b, 1, a};
	Mat mat = mpower(base, n - 2);
	std::cout << (mat[1] + mat[3]) % modulus << std::endl;
}

int main()
{
	while (std::cin >> a >> b >> n && n)
		work();
	return 0;
}
