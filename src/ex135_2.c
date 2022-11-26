#include <stdio.h>
#include <string.h>

char id[100000][20];

/*void sort(char *id[], int left, int right) {
 char tmp[20];
 char mid[20] = id[(left + right) / 2];///这里有问题，但不清楚为什么
 int i = left;
 int j = right;
 while (i <= j) {
  while (strncmp(id[i] + 6, mid + 6, 8) > 0 || (strncmp(id[i] + 6, mid + 6, 8) == 0 && strncmp(id[i], mid, 6) > 0))
   i++;
  while (strncmp(id[j] + 6, mid + 6, 8) < 0 || (strncmp(id[j] + 6, mid + 6, 8) == 0 && strncmp(id[j], mid, 6) < 0))
   j++;
  if (i <= j) {
   strncpy(tmp, id[i], 18);
   strncpy(id[i], id[j], 18);
   strncpy(id[i], tmp, 18);
   i++;
   j--;
  }
 }
 if (i < right)
  sort(id, i, right);
 if (j > left)
  sort(id, left, j);
}*/

int main()
{
    freopen("../data/ex135.in", "r", stdin);

    int n;
    char tmp[20];
    scanf("%d", &n);
    int i, j;
    for (i = 0; i < n; i++)
    {
        scanf("%s", &id[i]);
    }
    /*sort(&id, 0, n - 1);*/ // 稀烂的快排，救救
    int count = 0;
    for (i = 0; i < n - 1; i++)
    { // 还是冒泡好，呜呜
        for (j = 0; j < n - 1 - i; j++)
        {
            count = 0;
            if (strncmp(id[j] + 6, id[j + 1] + 6, 8) < 0 || (strncmp(id[j] + 6, id[j + 1] + 6, 8) == 0 && strncmp(id[j], id[j + 1], 6) < 0))
            {
                strncpy(tmp, id[j], 18);
                strncpy(id[j], id[j + 1], 18);
                strncpy(id[j + 1], tmp, 18);
                count++;
            }
        }
        if (count = 0)
            break;
    }
    for (i = 0; i < n; i++)
    {
        printf("%s\n", id[i]);
    }
    return 0;
}