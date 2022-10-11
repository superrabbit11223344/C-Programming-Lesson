#include <stdio.h>

int main() {
    int n, m;
    int i, j;
    char start;

    scanf("%d%d", &n, &m);
    for (i = 0; i < n; i++) {
        // 输出前半段: DCBA
        int num1 = 0;
        start = 'A' + i;
        while (start != 'A' && num1 < m) {
            printf("%c", start);
            start -= 1;
            num1++;
        }

        // 输出后半段: ABC...
        int num2 = m - i;
        start = 'A';
        for (j = 0; j < num2; j++) {
            printf("%c", start + j);
        }
        printf("\n");
    }
    return 0;
}