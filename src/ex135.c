#include <stdio.h>
#include <stdlib.h>

// 排序规则
int compare(const void *a, const void *b)
{
    long long int *x = (long long int *)a;
    long long int *y = (long long *)b;
    long long a1 = (*x) % 1000000000000 / 10000;
    long long b1 = (*y) % 1000000000000 / 10000;
    if (b1 > a1)
        return 1;
    else if (b1 < a1)
        return -1;
    else if (*x > *y)
        return -1;
    else if (*x == *y)
        return 0;
    else
        return 1;
}

int main()
{
    freopen("../data/ex135.in", "r", stdin);

    int n;
    scanf("%d", &n);
    long long id[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%lld", &id[i]);
    }

    // 快排
    qsort(id, n, sizeof(id[0]), compare);
    for (int i = 0; i < n; i++)
    {
        printf("%lld\n", id[i]);
    }

    return 0;
}
