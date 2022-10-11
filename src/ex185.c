#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int a;
    float x, xn;  // a的平方根
    int t = 0;  // 迭代次数
    scanf("%d", &a);
    x = a / 2.0;    // 给x赋初始值
    while (1) {
        xn = (x + a / x) / 2;
        t++;
        if (fabs(xn - x) < pow(10, -5)) break;
        x = xn;
    }
    printf("%.6f\n", xn);
    printf("%d", t);
}