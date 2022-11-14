#include <stdio.h>
#include <math.h>

int main()
{
    freopen("../data/ex91.in", "r", stdin);

    int k, n0[110], n, i, m = 0, f[110], No, NO[110], sum[110] = {0}, temp, j, gap0[20] = {0}, gap[20] = {0};
    scanf("%d", &n0[0]);
    for (i = 1; i < n0[0] + 1; i++)
    {

        scanf("%d", &n0[i]);
        for (j = 0; j < 16; j++)
        {
            if (n0[i] >= 16 * j && n0[i] <= 16 * j + 15)
            {
                gap0[j]++;
                break;
            }
        } //查询乐曲频率分布
    }
    scanf("%d%d", &n, &k);
    for (No = 0; No < n; No++)
    {
        scanf("%d", &f[0]); //输入某一首乐曲长度
        for (i = 1; i < f[0] + 1; i++)
        {
            scanf("%d", &f[i]);
            for (j = 0; j < 16; j++)
            {
                if (f[i] >= 16 * j && f[i] <= 16 * j + 15)
                {
                    gap[j]++;
                    break;
                }
            }
        } //得到一首乐曲与查询乐曲距离的平方
        for (j = 0; j < 16; j++)
        {
            sum[No] += pow(gap[j] - gap0[j], 2);
        }
        NO[m] = No; //将序号赋给数组
        m++;
        // 重置gap数组
        for (int gapNum = 0; gapNum < 20; gapNum++) {
            gap[gapNum] = 0;
        }
    }

    for (j = 0; j < n - 1; j++) //排序
        for (i = 0; i < n - 1 - j; i++)
        {
            if (sum[i] > sum[i + 1])
            {
                temp = sum[i];
                sum[i] = sum[i + 1];
                sum[i + 1] = temp;
                temp = NO[i];
                NO[i] = NO[i + 1];
                NO[i + 1] = temp;
            }
        }
    for (i = 0; i < k; i++)
        printf("%d ", NO[i]);
    return 0;
}