#include <iostream>
#include <iomanip>

//#include <boost/multiprecision/cpp_bin_float.hpp>
//typedef boost::multiprecision::cpp_bin_float_double ldb;

typedef long double ldb;
typedef long long lli;

ldb e(int a)
{
	if (a == 0)
		return 1;
	lli f = 1;
	ldb ans = 0;
	for (long long i = 1; i <= a + 1; ++i) {
		ans += (ldb) 1 / f;
		f *= i;
	}
	return ans;
}

int main()
{
	std::cout << "n e" << std::endl;
	std::cout << "- -----------" << std::endl;
	std::cout << "0 1" << std::endl;
	std::cout << "1 2" << std::endl;
	std::cout << "2 2.5" << std::endl;
	for (int i = 3; i < 10; ++i) {
		std::cout << i << ' ' << std::fixed << std::setprecision(9) << e(i) + 1e-12 << std::endl;
	}
}
