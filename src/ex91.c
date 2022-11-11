#include <stdio.h>
#include <math.h>

int main()
{
    freopen("data/ex91.in", "r", stdin);

    int music0[100] = {0};
    int n0 = 0;
    scanf("%d ", &n0);
    int i;
    for (i = 0; i < n0; i++)
        scanf("%d", &music0[i]); // 最开始的歌曲录入
    int m[16] = {0}, t = 0;      // m用来表示频率，t用来表示频率里的次数
    for (i = 0; i < n0; i++)
    {
        for (t = 0; t < 16; t++)
        {
            if (music0[i] >= 16 * t && music0[i] < 16 * (t + 1))
                m[t]++;
        }
    } // 现在得到的m[16]就是原始歌曲的频率
    int n = 0, k = 0;
    scanf("%d %d\n", &n, &k);
    int a[100] = {0};
    int music[100][100] = {0};
    int b[100][16] = {0}; // b[第几首歌][频率]
    for (int num = 0; num < n; num++)
    {
        scanf("%d", &a[num]); // 第num首歌里有几个代表频率的数
        for (int j = 0; j < a[num]; j++)
        {
            scanf("%d", &music[num][j]);
        }
        int t = 0; // m用来表示频率，t用来表示频率里的次数
        for (t = 0; t < 16; t++)
        {
            for (int j = 0; j < a[num]; j++)
            {
                if (music[num][j] >= 16 * t && music[num][j] < 16 * (t + 1))
                    b[num][t]++;
            }
        }
    } // n首乐曲都录进来了
    printf("\n");
    double c[100] = {0};
    for (int i = 0; i < n; i++) // i是第几首歌
    {
        double sum[100] = {0};
        for (int j = 0; j < 16; j++) // j是第几个频率
        {
            if (j != 0)
                sum[j] = sum[j - 1] + 0.0 + (m[j] - b[i][j]) * (m[j] - b[i][j]); // sum【第几个频率】 前面几个的和
            else
                sum[j] = (m[j] - b[i][j]) * (m[j] - b[i][j]);
        }
        c[i] = sqrt(sum[15] + 0.0);
    }
    double p = 0.0;
    double d[100] = {0};
    for (i = 0; i < n; i++)
    {
        d[i] = c[i];
    }
    for (i = 0; i < n; i++) // 开始冒泡
    {
        for (int j = 1; j < n - i; j++)
        {
            if (d[j - 1] > d[j])
            {
                p = d[j];
                d[j] = d[j - 1];
                d[j - 1] = p;
            }
        }
    } // d是已经排好序的乐曲
    int e[100] = {0};
    for (int x = 0; x < n; x++)
    {
        for (i = 0; i < n; i++)
        {
            if (d[i] == d[i - 1] && i != 0)
                continue;
            for (int j = 0; j < n; j++)
            {
                if (c[j] == d[i])
                {
                    e[x] = j;
                    x++;
                }
            }
        }
    }
    for (int x = 0; x < k; x++)
    {
        printf("%d ", e[x]);
    }
    return 0;
}