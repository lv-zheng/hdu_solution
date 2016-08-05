#include <cstdio>

int n;

void work()
{
	scanf("%d", &n);
	int sum = 0;
	int minsum = 0;
	int minp = 0;
	int maxsum = 0;
	int maxp = 0;
	int maxq = 0;
	int maxele = 0x80000000;
	int maxep = 0;
	for (int i = 1; i <= n; ++i) {
		int x;
		scanf("%d", &x);
		sum += x;
		if (x > maxele) {
			maxele = x;
			maxep = i;
		}
		if (sum < minsum) {
			minsum = sum;
			minp = i;
		}
		if (sum - minsum > maxsum) {
			maxsum = sum - minsum;
			maxp = i;
			maxq = minp;
		}
	}
	if (maxele < 0)
		printf("%d %d %d\n", maxele, maxep, maxep);
	else
		printf("%d %d %d\n", maxsum, maxq + 1, maxp);
} 

int main()
{
	int t;
	scanf("%d", &t);
	for (int i = 1 ; i <= t; ++i) {
		printf("Case %d:\n", i);
		work();
		if (i != t)
			puts("");
	}
	return 0;
}
