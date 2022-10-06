#include <stdio.h>

int main() {
    int n = 10;
    int result = 1;
    int i;
    
    for (i = 1; i <= n; i++) {
        result *= i;
    }
    printf("%d", result);
}