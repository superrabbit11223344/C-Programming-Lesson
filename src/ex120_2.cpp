#include <iostream>

using namespace std;

int b[100][100] = {0}; //倒序输出用的变量数组
int x[100], y[100];    //倒序输出用的变量

//寻找最小值并且交换的函数
int Select_order(int a[100], int n, int s, int q)
{
    //判断是否排序完成
    int sum = 0; //计数器
    for (int i = 0; i < n - 1; i++)
    {
        if (a[i] > a[i + 1])
            sum = 1;
    }
    if (sum == 0)
        return q;

    //搜索最大量
    int min = a[s];
    int k = s; //用于保存最大数组的i
    for (int i = s; i < n; i++)
    {
        if (a[i] < min)
        {
            min = a[i];
            k = i;
        }
    }

    //如果第一项就是最小项，则直接进行下一次循环
    if (k == s)
    {
        s++;
    }
    //否则开始交换
    else
    {
        //给倒叙输出的变量赋值
        x[q] = s + 1;
        y[q] = k + 1;

        //交换
        int temp = a[k];
        a[k] = a[s];
        a[s] = temp;

        //给倒序输出的函数赋值
        for (int j = 0; j < n; j++)
        {
            b[q][j] = a[j];
        }

        //使原来数组的长度-1
        s++;
        q++;
    }

    //递归
    return Select_order(a, n, s, q);
}

int main()
{
    freopen("data/ex90.in", "r", stdin);

    int a[100], n, p;
    int s = 0;
    int q = 0;
    //输入数字个数
    cin >> n;

    //输入数字
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    //调用函数
    p = Select_order(a, n, s, q);

    //对之前的排序结果进行倒序输出
    for (int i = p - 1; i >= 0; i--)
    {
        cout << x[i] << "<->" << y[i] << ":";
        for (int j = 0; j < n; j++)
        {
            cout << b[i][j] << " ";
        }
        cout << endl;
    }

    cout << "Total steps:" << p << endl;
    cout << "Right order:";
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}