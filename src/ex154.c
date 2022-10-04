#include<stdio.h>
#include<math.h>

int main() {
    float x;
    float result;

    scanf("%f", &x);    // 输入一个浮点数
    
    if (x < 0) {
        result = -x;
    } else if (x <= 1) {
        result = sqrt(x);
    } else {
        result = x * x;
    }

    printf("%.2f", result);
}