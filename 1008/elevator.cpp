#include <cstdio>

int main()
{
	int n;
	while (~scanf("%d", &n) && n) {
		int cur = 0;
		int t = 0;
		for (int i = 0; i < n; ++i) {
			int x;
			scanf("%d", &x);
			if (x > cur) {
				t += (x - cur) * 6 + 5;
			} else if (x < cur) {
				t += (cur - x) * 4 + 5;
			} else {
				t += 5;
			}
			cur = x;
		}
		printf("%d\n", t);
	}
	return 0;
}
