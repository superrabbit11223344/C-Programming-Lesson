#include <stdio.h>

int main()
{
    // input
    int n;
    scanf("%d", &n);

    int timu[100];
    int i;
    for (i = 0; i < n; i++)
        scanf("%d", &timu[i]);

    int m, k;
    scanf("%d%d", &m, &k);

    int sno[100];
    int done[100];

    for (i = 0; i < m; i++)
    {
        scanf("%d", &sno[i]);

        // 扫描他做的题，看看是否在老师要求里，适当计数
        done[i] = 0;

        int p;
        scanf("%d", &p);
        int j;
        for (j = 0; j < p; j++)
        {
            int done_timu;
            scanf("%d", &done_timu);

            int found = 0;
            int cha;
            for (cha = 0; cha < n; cha++)
                if (timu[cha] == done_timu)
                {
                    found = 1;
                    break;
                }
            if (found == 1)
                done[i] = done[i] + 1;
        }
    }
    // count finished

    // sort
    // sno  done  m
    // done 从大到小，sno从小到大
    int range;
    for (range = m; range >= 2; range--)
    {
        int temp;
        for (i = 0; i <= range - 2; i++)
        {
            if (done[i] > done[i + 1])
            {
            } // do nothing
            else if (done[i] == done[i + 1])
            {
                if (sno[i] > sno[i + 1])
                {
                    temp = sno[i];
                    sno[i] = sno[i + 1];
                    sno[i + 1] = temp;
                    temp = done[i];
                    done[i] = done[i + 1];
                    done[i + 1] = temp;
                }
                else if (sno[i] == sno[i + 1])
                {
                } // do nothing
                else if (sno[i] < sno[i + 1])
                {
                } // do nothing
            }
            else if (done[i] < done[i + 1])
            {
                temp = sno[i];
                sno[i] = sno[i + 1];
                sno[i + 1] = temp;
                temp = done[i];
                done[i] = done[i + 1];
                done[i + 1] = temp;
            }
        }
    }

    // paiming
    int paiming[100];

    int pm = 1;
    paiming[0] = 1;

    for (i = 1; i <= m - 1; i++)
    // 做题数量跟上一个一样
    // 做题数量跟上一个不一样
    {
        if (done[i] == done[i - 1])
        {
            paiming[i] = paiming[i - 1];
        }
        else if (done[i] != done[i - 1])
        {
            pm = pm + 1;
            paiming[i] = pm;
        }
    }

    // shouji
    int shouji[100];
    int kk = 0;
    for (i = 0; i <= m - 1; i++)
        if (paiming[i] <= k)
        {
            shouji[i] = sno[i];
            kk = kk + 1;
        }

    // output
    for (i = 0; i <= kk - 2; i++)
        printf("%d ", shouji[i]);
    printf("%d\n", shouji[kk - 1]);

    return 0;
}