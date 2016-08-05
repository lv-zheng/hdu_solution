#include <iostream>

//#include <boost/multiprecision/cpp_int.hpp>
//typedef boost::multiprecision::uint1024_t lli;

typedef long long int lli;

lli dr(lli a)
{
	lli ans = 0;
	while (a > 0) {
		ans += a % 10;
		a /= 10;
	}
	return ans;
}

lli droot(lli a)
{
	while (a >= 10) {
		a = dr(a);
	}
	return a;
}

int main()
{
	std::string s;
	while (std::cin >> s && s != "0") {
		lli a = 0;
		for (auto ch : s)
			a += ch - '0';
		std::cout << droot(a) << std::endl;
	}
}
