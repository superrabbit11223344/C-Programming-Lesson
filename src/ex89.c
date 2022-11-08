#include <stdio.h>

int main()
{
    freopen("data/ex89.in", "r", stdin);

    int n;
    double award = 0;
    double profit;
    scanf("%d", &n);
    double a[n + 1][2];
    int i = 1;
    a[0][0] = 0;
    a[0][1] = 0;
    for (; i < n + 1; i++)
    {
        scanf("%lf%lf", &a[i][0], &a[i][1]);
    }
    a[n][0] = 9000001;
    scanf("%lf", &profit);
    if (profit < 0)
    {
        printf("NO");
        return 0;
    }
    if (n == 0)
    {
        printf("%.2f", 0.000);
        return 0;
    }
    for (i = 0; i < n; i++)
    {
        if (a[i][0] < profit && profit <= a[i + 1][0])
        {
            int j = 1;
            for (; j <= i; j++)
            {
                award += (a[j][0] - a[j - 1][0]) * a[j][1];
            }
            award += (profit - a[i][0]) * a[i + 1][1];
            printf("%.2f", award);
            return 0;
        }
    }
}