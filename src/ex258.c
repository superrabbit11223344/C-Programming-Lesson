#include <stdio.h>

int main()
{
    int n, gao = 0, di = 0;
    double h, l, a[2001], S = 0, p;
    char e, f, b[2001];
    scanf("%d", &n);
    scanf("%lf%c%lf%c", &h, &e, &l, &f);

    if (e == 'C')
        h = h * 9.0 / 5.0 + 32;
    if (f == 'C')
        l = l * 9.0 / 5.0 + 32;
    for (int i = 1; i <= n; i++)
    {
        scanf("%lf%c", &a[i], &b[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        if (b[i] == 'C')
            a[i] = a[i] * 9 / 5.0 + 32;
        S = S + a[i];
        if (a[i] >= h)
            gao++;
        if (a[i] <= l)
            di++;
    }
    p = S / (n * 1.0);
    printf("%.3lfF\n", p);
    printf("%d %d", gao, di);
    return 0;
}
