#include <stdio.h>
#include <math.h>

// 将任意进制数转换为10进制数
int toDecimal(int input, int bin)
{
    int value = input;
    int num;
    int i = 0;
    int sum = 0;
    while (value > 0)
    {
        num = value % 10;
        // 判断该位的值是否小于进制数，否则input不是有效的进制数
        // 比如200不是有效的二进制数
        if (num < bin)
        {
            sum += num * pow(bin, i);
            i++;
            value /= 10;
        }
        else
        {
            return -1;
        }
    }
    return sum;
}

// 获得符合条件的最小进制数
int getBin(int a, int b, int c)
{
    int bin = 2;
    for (; bin <= 16; bin++)
    {
        int a_decimal = toDecimal(a, bin);
        int b_decimal = toDecimal(b, bin);
        int c_decimal = toDecimal(c, bin);
        if (a_decimal * b_decimal == c_decimal && a_decimal > 0 && b_decimal > 0 && c_decimal > 0)
        {
            return bin;
        }
    }

    return 0;
}

int main()
{
    freopen("data/ex152.in", "r", stdin);

    int T;
    scanf("%d", &T);
    int a, b, c;
    int bin; // 进制数，范围是2-16
    for (int i = 0; i < T; i++)
    {
        scanf("%d %d %d", &a, &b, &c);
        bin = getBin(a, b, c);
        printf("%d\n", bin);
    }
    return 0;
}