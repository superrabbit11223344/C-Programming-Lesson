#include <stdio.h>
#include <limits.h>

struct shangpin
{
    int b;
    int a[200];
};

int main()
{
    freopen("../data/ex290.in", "r", stdin);

    struct shangpin shangpin[100];
    int i, j, n, k, m;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &shangpin[i].b);
        for (j = 0; j < shangpin[i].b; j++)
        {
            scanf("%d", &shangpin[i].a[j]);
        }
    }
    int c[100], score = 0, p;
    for (i = 0; i < 100; i++)
    {
        c[i] = INT_MIN;
    }
    for (j = 0; j < shangpin[0].b; j++)
    {
        score = 0;
        for (k = 1; k < n; k++)
        {
            for (m = 0; m < shangpin[k].b; m++)
            {
                if (shangpin[0].a[j] == shangpin[k].a[m])
                    score += 1;
            }
        }
        if (score == n - 1)
            c[j] = shangpin[0].a[j];
    }
    for (i = 0; i < 100; i++)
    {
        for (j = 0; j < 100 - 1 - i; j++)
        {
            if (c[j] >= c[j + 1])
            {
                p = c[j];
                c[j] = c[j + 1];
                c[j + 1] = p;
            }
        }
    }
    if (c[99] == INT_MIN)
        printf("NO\n");
    else
    {
        for (i = 0; i < 100; i++)
        {
            if (c[i] != INT_MIN)
                printf("%d ", c[i]);
        }
    }
    return 0;
}