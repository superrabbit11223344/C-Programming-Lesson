#include <stdio.h>
#define N 10
int n, sum;
// 记录是否找到符合条件的要素
int hasFounded = 0;
int book[N + 2];
int nums[N + 2];
int C[N + 1][N + 1];
void dfs(int depth);


int main()
{
    int i, j, depth = 1;
    scanf("%d %d", &n, &sum);
    // 0的情况要特判，从0个数中取出0个数只有一种取法
    for (i = 0; i <= n; i++)
    {
        C[0][i] = C[i][i] = 1;
    }
    for (i = 2; i <= n; i++)
    {
        for (j = 1; j < i; j++)
        {
            C[j][i] = C[j - 1][i - 1] + C[j][i - 1];
        }
    }

    dfs(1);

    return 0;
}


// 深度搜索函数定义
void dfs(int depth)
{
    int i, currentSum;
    //如果已经找到了排列，就不运行了
    if (hasFounded)
    {
        return;
    }

    //如果已经枚举到了最后一位，就开始判断排列是否满足条件
    if (depth == n + 1)
    {
        currentSum = 0;

        for (i = 1; i <= n; i++)
        {
            currentSum += C[i - 1][n - 1] * nums[i];
        }

        //如果满足条件直接输出
        if (currentSum == sum)
        {
            for (i = 1; i <= n; i++)
            {
                printf("%d ", nums[i]);
            }
            //标记找到
            hasFounded = 1;
        }
        return;
    }

    for (i = 1; i <= n; i++)
    {
        //该点未被访问而且排列尚未找到，就继续运行
        if (!book[i] && !hasFounded)
        {
            //深度搜索
            book[i] = 1;
            nums[depth] = i;
            dfs(depth + 1);
            book[i] = 0;
        }
    }
}