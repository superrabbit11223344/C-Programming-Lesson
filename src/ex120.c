#include <stdio.h>

// 两数交换
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// 选择排序（迭代法）
void selectionSort_1(int arr[], int len, int *step)
{
    int i, j;

    for (i = 0; i < len - 1; i++)
    {
        int min = i;
        for (j = i + 1; j < len; j++)
        {
            if (arr[j] < arr[min])
                min = j;
        }
        // 交换数据
        swap(&arr[min], &arr[i]);

        // 输出交换步骤，但是是正序
        if (min != i)
        {
            (*step)++;
            printf("%d<->%d:", i + 1, min + 1);
            for (int i = 0; i < len; i++)
            {
                printf("%d ", arr[i]);
            }
            printf("\n");
        }
    }
}

// 选择排序（递归法）
int result[100];    // 全局变量，用来保存排序结果

void selectionSort_2(int arr[], int len, int left, int right, int *step)
{
    if (left <= right)
    {
        // 排序过程
        int min = left; // 最小值
        for (int j = left + 1; j <= right; j++)
        {
            if (arr[j] < arr[min])
                min = j;
        }
        swap(&arr[min], &arr[left]);    // 交换当前数值和最小数值
        selectionSort_2(arr, len, left + 1, right, step);   // left加1，继续递归

        // 输出交换步骤
        if (min != left)
        {
            (*step)++;
            printf("%d<->%d:", left + 1, min + 1);
            for (int i = 0; i < len; i++)
            {
                printf("%d ", arr[i]);
            }
            printf("\n");
        }
        // 回溯
        swap(&arr[min], &arr[left]);
        // 递归写在这里会正序输出交换步骤
        // selectionSort_2(arr, len, left + 1, right, step);
    }
    // 当left > right时，说明排序结束
    else
    {
        // 保存最终的排序结果
        for (int i = 0; i < len; i++) {
            result[i] = arr[i];
        }
    }
}

int main()
{
    // 读入本地测试用例
    freopen("../data/ex120.in", "r", stdin);

    int n;            // 表示n个元素
    int a[100] = {0}; // n个整数，存放在a数组中
    int step = 0;

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    // 选择排序
    // selectionSort_1(a, n, &step);
    selectionSort_2(a, n, 0, n - 1, &step);

    // 输出交换次数
    printf("Total steps:%d\n", step);

    // 输出排序结果
    printf("Right order:");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", result[i]);
    }
    printf("\n");

    return 0;
}