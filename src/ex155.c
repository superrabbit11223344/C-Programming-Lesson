#include <stdio.h>

int main()
{
    int a, b, sq, k, w = 1;
    int sum = 0;
    scanf("%d %d", &a, &b);
    for (k = a; k <= b; k++)
    {
        sq = k * k;

        while (w <= k)
            w *= 10;
        if (((sq - k) % w) == 0)
            sum += k;
    }

    printf("%d", sum);
    return 0;
}