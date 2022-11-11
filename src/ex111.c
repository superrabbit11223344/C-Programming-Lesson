#include <stdio.h>

// 确定m应该最大从什么开始，按理说应该为n-1，但是可以找一个合适的值
const int M = 150;

int main()
{
    freopen("data/ex111.in", "r", stdin);

    int n;
    // while这种写法用来不断读入数据
    while (scanf("%d", &n) && n > 0)
    {
        // 用来判断是否存在满足条件的m
        int flag = 0;
        int m;
        for (m = M; m >= 2; m--)
        {
            int sum = n, j;
            for (j = 1; j <= m; j++)
            {
                if ((sum - 1) % m != 0)
                    break;
                sum -= 1 + (sum - 1) / m;
            }
            if (j > m && sum % m == 0)
            {
                flag = 1;
                break;
            }
        }

        if (flag)
            printf("%d\n", m);
        else
            printf("no solution\n");
    }

    return 0;
}
