#include <stdio.h>

int main() {
    int a1, a2, b1, b2, m, f;
    float sum1, sum2, sum, sum3;
    scanf("%d %d\n%d %d", &a1, &a2, &b1, &b2);
    m = b1 + b2;
    sum = a1 * b1 + a2 * b2;

    if (m <= 2) {
        sum1 = 0.8 * sum;
    } else if (m >= 3) {
        sum1 = 0.7 * sum;
    }

    if (sum >= 200) {
        sum2 = sum - 50;
    } else sum2 = sum;

    if (sum1 > sum2) {
        sum3 = sum2;
        f = 2;
    } else if (sum1 <= sum2) {
        sum3 = sum1;
        f = 1;
    }
    printf("%d %.1f", f, sum3);
    return 0;
}