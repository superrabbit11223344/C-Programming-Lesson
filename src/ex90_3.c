#include <stdio.h>

struct student
{
    int xuehao;
    int tishu;
    int tihao[100];
};

int main()
{
    freopen("../data/ex90.in", "r", stdin);

    int n, m, k, i, xi, zhong, j, t, zuihou, num[100], b;
    int ti[100];
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &ti[i]); // 所要做的题号
    }
    scanf("%d%d", &m, &k);
    struct student student[100]; // m个学生
    struct student tmp;        // 定义struct 中间量
    for (i = 0; i < m; i++)
    {
        scanf("%d%d", &student[i].xuehao, &student[i].tishu);
        for (j = 0; j < student[i].tishu; j++)
            scanf("%d", &student[i].tihao[j]);
    } // 结束了输入 排序 大小
    for (i = 0; i < m - 1; i++)
    {
        for (j = 0; j < m - i - 1; j++)
        {
            if (student[j].xuehao > student[j + 1].xuehao)
            {
                tmp = student[j];
                student[j] = student[j + 1];
                student[j + 1] = tmp;
            }
        }
    } // 已经给学号大小排好序
    // 判断是不是在规定题目内
    for (i = 0; i < m; i++)
    { // 第几个学生进行判断
        zuihou = 0;
        for (j = 0; j < student[i].tishu; j++)
        {
            for (t = 0; t < n; t++)
            {

                if (student[i].tihao[j] == ti[t])
                    zuihou++;
            }
        }
        num[i] = zuihou; // m个学生做出了多少道
    }                    // 计算出了每一个学生做出来多少题
    // 根据做出的题目多少进行排序

    for (i = 0; i < m - 1; i++)
    {
        for (j = 0; j < m - 1 - i; j++)
        {
            if (num[j] < num[j + 1])
            {
                zhong = num[j];
                num[j] = num[j + 1];
                num[j + 1] = zhong;
                xi = student[j].xuehao;
                student[j].xuehao = student[j + 1].xuehao;
                student[j + 1].xuehao = xi;
            }
        }

    } // 根据题号多少排好序
    b = 0;
    for (i = 0; i < k + b && i < m; i++)
    {
        if (num[i] == num[i + 1])
            b++;
        printf("%d ", student[i].xuehao);
    }
    return 0;
}