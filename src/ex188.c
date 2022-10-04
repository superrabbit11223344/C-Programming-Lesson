#include<stdio.h>

int main() {
    int a1, a2; // 第一个点的坐标
    int b1, b2; // 第二个点的坐标
    int c1, c2; // 第三个点的坐标

    int res1_1, res1_2; // 第一个解的坐标
    int res2_1, res2_2; // 第二个解的坐标
    int res3_1, res3_2; // 第三个解的坐标

    int res_num = 3;    // 一定会有三个解，因为三个点都不同并且不在同一条直线上

    scanf("%d%d", &a1, &a2);
    scanf("%d%d", &b1, &b2);
    scanf("%d%d", &c1, &c2);

    res1_1 = a1 + b1 - c1; res1_2 = a2 + b2 - c2;
    res2_1 = a1 + c1 - b1; res2_2 = a2 + c2 - b2;
    res3_1 = b1 + c1 - a1; res3_2 = b2 + c2 - a2;

    printf("%d\n", res_num);
    printf("%d %d\n", res1_1, res1_2);
    printf("%d %d\n", res2_1, res2_2);
    printf("%d %d", res3_1, res3_2);

    return 0;
}