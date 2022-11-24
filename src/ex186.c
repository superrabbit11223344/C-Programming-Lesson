#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    long N;     // 输入的整数
    scanf("%ld", &N);

    int ifNegative = N < 0 ? 1 : 0;     // 判断是否为负数

    long value = labs(N);   // 取绝对值

    // 若为负数，先打印“-”
    if (ifNegative)
    {
        printf("-");
    }

    int pre = 0;    // 前一位数字
    int flag = 0;   // 若已经出现第一个不是0的数，则标记为1
    while (value != 0)
    {
        // 从个位开始取，依次往前
        int cur = value % 10;
        // 从第一个不为0的数开始打印
        if ((cur != pre && pre == 0) || (flag == 1)) {
            flag = 1;
            printf("%d", cur);
        }
        pre = cur;
        value /= 10;
    }

    return 0;
}