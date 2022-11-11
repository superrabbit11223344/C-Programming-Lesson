#include <stdio.h>
int main()
{
    int n;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    int steps = 0, x1[n], x2[n], b[n][n];
    for (int i = 0; i < n; i++)
    {
        int min = a[i], mini = i;
        for (int j = i; j < n; j++)
            if (a[j] < min)
            {
                min = a[j];
                mini = j;
            }
        if (i != mini)
        {
            steps++;
            x1[steps] = i;
            x2[steps] = mini;
            a[mini] = a[i];
            a[i] = min;
            for (int j = 0; j < n; j++)
                b[steps][j] = a[j];
        }
    }

    for (int i = steps; i > 0; i--)
    {
        printf("%d<->%d:", x1[i] + 1, x2[i] + 1);
        for (int j = 0; j < n; j++)
            printf("%d ", b[i][j]);
        printf("\n");
    }

    printf("Total steps:%d\n", steps);
    printf("Right order:");
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);

    return 0;
}