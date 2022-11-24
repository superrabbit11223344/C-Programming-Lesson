#include <stdio.h>
long long a[1000000];
long long num[20000000];

int main() {
    freopen("../data/ex854.in", "r", stdin);

	long long max = 0;
	long long i, j, n;
	long long sum = 0;
	scanf("%lld", &n);
	for (i = 0; i < 20000000; i++) {
		num[i] = 0;
	}
	for (i = 0; i < n; i++) {
		scanf("%lld", &a[0]);
		for (j = 1; j <= a[0]; j++) {
			scanf("%lld", &a[j]);
			num[a[j] + 10000000]++;
		}
	}
	for (i = 0; i < 20000000; i++) {
		if (num[i] == 1) {
			sum = sum + i - 10000000;
		}
	}
	printf("%lld", sum);
	return 0;
}