#include<stdio.h>

int main() {
    char x;
    scanf("%c", &x);

    if (x >= 'A' && x <= 'Z') {             // 判断输入的字符是否为大写字母
        x = x + 32;
    } else if (x >= 'a' && x <= 'z') {      // 判断输入的字符是否为小写字母
        x = x - 32;
    }
    printf("%c\n", x);
}