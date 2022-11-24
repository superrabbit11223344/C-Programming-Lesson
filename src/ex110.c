#include <stdio.h>
#include <string.h>

int isPalindrome(char s[], int strLen) {
    int left, right;

    for (left = 0, right = strLen - 1; left <= right; left++, right--) {
        if (s[left] != s[right]) return 0;
    }
    return 1;
}

int main() {
    char s[1000];
    gets(s);

    if (isPalindrome(s, strlen(s)) == 1) {
        printf("Yes");
    } else {
        printf("No");
    }
}