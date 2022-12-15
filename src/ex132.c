#include <stdio.h>
#include <stdlib.h>

int findMax(int *p, int nSize)
{
    int max = p[0];
    int maxIndex = 0;
    for (int i = 1; i < nSize; i++) {
        if (max < p[i]) {
            max = p[i];
            maxIndex = i;
        }
    }
    // 交换
    int tmp = p[maxIndex];
    p[maxIndex] = p[0];
    p[0] = tmp;
    return max;
}

int main()
{
    int ary[2100] = {3, 2, 1, 5, 6, 7, 9, 10}, n = 8, nMax, i;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
        scanf("%d", &ary[i]);

    nMax = findMax(ary, n);

    for (i = 0; i < n; i++)
        printf("%d ", ary[i]);
    printf("\n");

    printf("%d\n", nMax);
    return 0;
}