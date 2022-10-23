#include <stdio.h>
#include <math.h>
#include <stdlib.h>

# define PI 3.14159265

int main() {
    double x;
    double epsilon;
    double sinResult = 0, cosResult = 0;
    scanf("%lf%lf", &x, &epsilon);

    while (fabs(x) > 2 * PI) {
        x -= 2 * PI;
    }

    // 先计算sinx
    int i = 1;
    double error;
    double value = x;
    sinResult += value;
    do {
        value = value * pow(x, 2) / ((2 * i) * (2 * i + 1)) * (-1);
        sinResult += value;
        error = fabs(sin(x) - sinResult);
        i += 1;
    } while (error >= epsilon);

    // 后计算cosx
    int j = 1;
    value = 1;
    cosResult += value;
    do {
        value = value * pow(x, 2) / ((2 * j - 1) * (2 * j)) * (-1);
        cosResult += value;
        error = fabs(cos(x) - cosResult);
        j += 1;
    } while (error >= epsilon);
    printf("%.6f\n%.6f", sinResult, cosResult);

    return 0;
}