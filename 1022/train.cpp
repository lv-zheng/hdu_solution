#include <iostream>
#include <stack>
#include <string>
#include <vector>

int n;
std::string si, so;

std::vector<int> test()
{
	bool onst[256] = {0};
	bool gone[256] = {0};
	std::stack<char> st;
	std::vector<int> ans;
	int p = 0;
	for (auto ch : so) {
		if (gone[ch])
			goto fail;
		if (onst[ch]) {
			if (st.top() != ch)
				goto fail;
			st.pop();
			ans.push_back(0);
			onst[ch] = false;
			gone[ch] = true;
		} else {
			while (si[p] != ch) {
				onst[si[p]] = true;
				st.push(si[p]);
				++p;
				ans.push_back(1);
			}
			ans.push_back(1);
			ans.push_back(0);
			gone[ch] = true;
			++p;
		}
	}
	return ans;
fail:
	ans.clear();
	return ans;
}

void work()
{
	auto ans = test();
	if (ans.size()) {
		std::cout << "Yes." << std::endl;
		for (auto a : ans)
			std::cout << (a ? "in" : "out") << std::endl;
	} else {
		std::cout << "No." << std::endl;
	}
	std::cout << "FINISH" << std::endl;
}

int main()
{
	std::ios::sync_with_stdio(false);
	while (std::cin >> n >> si >> so)
		work();
	return 0;
}
