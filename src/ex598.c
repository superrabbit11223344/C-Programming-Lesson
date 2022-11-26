#include <stdio.h>
#include <string.h>

int main() {
    // 输入字符串
    char s1[200];
    char s2[200];
    scanf("%s%s", &s1, &s2);

    // count数组用来记录每个字母的出现次数
    int count[52] = {0};
    int count_copy[52] = {0};
    for (int i = 0; i < strlen(s1); i++) {
        count[s1[i] - 'a']++;
    }

    // flag用来标记字符串s2的子串中是否有s1中没有的元素
    int flag = 0;

    for (int i = 0; i <= strlen(s2) - strlen(s1); i++) {
        // 初始化count_copy和flag
        memcpy(count_copy, count, sizeof(count));
        flag = 0;

        for (int j = i; j < i + strlen(s1); j++) {
            if (count_copy[s2[j] - 'a'] == 0) {
                break;
            } else {
                count_copy[s2[j] - 'a'] -= 1;
            }
        }
        for (int k = 0; k < 20; k++) {
            if (count_copy[k] != 0) {
                flag = 1;
                break;
            } else {
                continue;
            }
        }
        // s2的子串是s1的一种排列，则输出该子串
        if (flag == 0) {
            for (int k = i; k < i + strlen(s1); k++) {
                printf("%c", s2[k]);
            }
            return 0;
        }
    }

    // s2中不存在s1的排列，则输出false
    if (flag == 1) {
        printf("false");
    }

    return 0;
}