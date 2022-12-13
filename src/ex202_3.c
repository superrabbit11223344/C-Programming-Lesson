#include <stdio.h>

char like[11][11];
int book[11] = {0}, n = 0, count = 0;
int ans[5000][11];
int take[11];

void divide(int person)
{
    int i, k;
    for (i = 1; i <= n; i++)
    {
        if (take[i] == 0 && like[person][i - 1] == '1')
        {
            take[i] = 1;
            book[person] = i;
            if (person == n)
            {
                count++;
                for (k = 1; k <= n; k++)
                {
                    ans[count][k] = book[k];
                }
            }
            else
            {
                divide(person + 1);
            }
            take[i] = 0;
            book[person] = 0;
        }
    }
}

int main()
{
    int i, j;
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        scanf("%s", like[i]);
        take[i] = 0;
    }
    divide(1);
    if (count != 0)
    {
        printf("%d\n", count);
        for (i = 1; i <= count; i++)
        {
            for (j = 1; j <= n; j++)
            {
                printf("B%d", ans[i][j]);
            }
            printf("\n");
        }
    }
    else
    {
        printf("NO");
    }
    return 0;
}