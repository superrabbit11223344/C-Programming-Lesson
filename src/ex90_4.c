#include <stdio.h>
int main()
{
    freopen("../data/ex90.in", "r", stdin);

    int n, m, k, p, i, j, q, x; // 定义，n,m,k,p均如题，i,j，q为循环所需， x为排序时暂存空间

    scanf("%d ", &n); // 输入 题目  题号
    int a[100];         // 定义题号数组
    for (i = 1; i <= n; i++)
    {
        scanf("%d ", &a[i]);
    }
    scanf("\n");
    scanf("%d %d\n", &m, &k);
    int sno[100]; // 定义sno学号数组，c前k名做对题目数的数组，b每个学生做对题目数，t为存储学生题号的空间
    int c[100];
    int b[100], t;

    for (i = 1; i <= m; i++) // 输入学号 刷题数
    {
        scanf("%d ", &sno[i]);
        scanf("%d ", &p);
        for (j = 1; j <= p; j++) // 输入题号 判断是否为所给题号
        {
            scanf("%d ", &t);
            for (q = 1; q <= n; q++)
            {
                if (t == a[q])
                    b[i] = b[i] + 1; // 是 b自加，b为做对题数 ，否则不加
                else
                    continue;
            }
        }
        scanf("\n"); // 输入完毕
    }
    for (i = 1; i <= m - 1; i++) // 按做对题数排序，将做对题数和对应学号整体，由大到小
    {
        for (j = i; j <= m - 1; j++)
        {
            if (b[i] < b[j + 1])
            {
                x = sno[i];
                sno[i] = sno[j + 1];
                sno[j + 1] = x;
                x = b[i];
                b[i] = b[j + 1];
                b[j + 1] = x;
            }
            else if (b[i] == b[j + 1]) // 遇做对题数相同者，将学号由小到大排序
            {
                if (sno[i] > sno[j + 1])
                {
                    x = sno[i];
                    sno[i] = sno[j + 1];
                    sno[j + 1] = x;
                }
                else
                    continue;
            }
            else
                continue;
        }
    }
    c[1] = b[1]; // 找到前k名做对题数，排名第i做对 c [i]题，排k名 做对c[k]题
    for (j = 2; j <= k; j++)
    {

        for (i = 1; i <= m; i++)
        {
            if (b[i] < c[j - 1])
            { // 具体过程为：b[1]为第一名，找到第一个小于前一名做对题目数的b，即为第二名做对题数 ，共k个这样的数 {
                c[j] = b[i];
                break;
            }
        }
    }
    for (i = 1; i <= k; i++)
    {
        for (j = 1; j <= m; j++) // 逐个判断是否为第k名，是则输出学号
        {
            if (b[j] == c[i])
                printf("%d ", sno[j]);
            else
                continue;
        }
    }
}