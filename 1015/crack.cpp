#include <algorithm>
#include <functional>
#include <iostream>
#include <string>

int targ;
int n;
std::string cand;

typedef __int128 LLL;

#define rep(i, n) for (int i = 0; i < n; ++i)

bool eval(int i, int j, int k, int l, int m)
{
	LLL a = cand[i] - 'A' + 1;
	LLL b = cand[j] - 'A' + 1;
	LLL c = cand[k] - 'A' + 1;
	LLL d = cand[l] - 'A' + 1;
	LLL e = cand[m] - 'A' + 1;
	LLL r = 0;
	r += a;
	r -= b * b;
	r += c * c * c;
	r -= d * d * d * d;
	r += e * e * e * e * e;
	return r == targ;
}

void work()
{
	n = cand.size();
	std::sort(cand.begin(), cand.end(), std::greater<char>());
	rep(i, n)
	rep(j, n) if (j != i)
	rep(k, n) if (k != i && k != j)
	rep(l, n) if (l != i && l != j && l != k)
	rep(m, n) if (m != i && m != j && m != k && m != l)
	if (eval(i, j, k, l, m)) {
		std::cout
			<< cand[i]
			<< cand[j]
			<< cand[k]
			<< cand[l]
			<< cand[m]
			<< std::endl;
		return;
	}
	std::cout << "no solution" << std::endl;
}

int main()
{
	std::ios::sync_with_stdio(false);
	while (std::cin >> targ >> cand && (targ != 0 || cand != "END"))
		work();
	return 0;
}
