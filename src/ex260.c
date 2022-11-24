#include <stdio.h>
#include <stdlib.h>

int comp(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

int main() {
    int n;  // 集合的元素个数
    scanf("%d", &n);
    int m;  // 带查找元素
    scanf("%d", &m);
    int nums[n];    // n个正整数
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    // 从小到大排序
    qsort(nums, n, sizeof(int), comp);

    // 二分查找
    int left = 0;
    int right = n - 1;
    int compareNum = 0;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        compareNum++;
        if (nums[mid] > m) {
            right = mid - 1;
        } else if (nums[mid] < m) {
            left = mid + 1;
        } else {
            printf("%d\n", mid);
            printf("%d", compareNum);
            return 0;
        }
    }
    printf("-1\n");
    printf("%d", compareNum);
}