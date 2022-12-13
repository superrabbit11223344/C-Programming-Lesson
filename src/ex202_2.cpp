#include <iostream>
using namespace std;

int N = 0; // 共有N个人和N本书
int like[20][20];
char b[20][20];			   // 未知二维数组的大小上限为25*25
int num = 0;			   // 方案数
int take[25], m[5000][25]; // 分书方案，分给具体某个人
bool assigned[25];		   // 某本书是否已经分过


// id是人，i是书
void Try(int ren)
{
	// 递归终止条件：
	if (ren == N)
	{
		num++;
		for (int i = 0; i < N; i++)
			m[num][i] = take[i] + 1;
		return;
	}
	// 为每本书找适合的读者：
	for (int shu = 0; shu < N; shu++)
	{
		if (like[ren][shu] == true && !assigned[shu])
		{ // 第i本书被第id个人喜欢
			// 记录分书情况：
			take[ren] = shu; // 第id本书被第i个人拿了
			assigned[shu] = true;
			// 为下一本书找合适的读者
			Try(ren + 1);
			// 将书退还，递归结束后方便下一次寻找
			assigned[shu] = false;
		}
	}
}

int main()
{
	cin >> N;
	// 输入
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> b[i][j];
			like[i][j] = b[i][j] - '0';
		}
	}
	Try(0); // 从第0个人开始尝试
	if (num == 0)
	{
		cout << "NO";
	}
	else
	{
		cout << num << endl;
		for (int i = 1; i <= num; i++)
		{
			for (int j = 0; j < N; j++)
			{
				cout << "B" << m[i][j];
			}
			cout << endl;
		}
	}

	return 0;
}
