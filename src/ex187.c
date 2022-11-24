#include <stdio.h>

int main()
{
    int a, b;
    scanf("%d%d", &a, &b);
    for (int i = 1;; i++)
    {
        if (i % a == 0 && i % b == 0)
        {
            printf("%d", i);
            break;
        }
    }

    return 0;
}