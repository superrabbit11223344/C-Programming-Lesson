#include <stdio.h>
#include <string.h>
int main()
{
    char str[101] = {0}, str2[101] = {0};
    char a;
    int i = 0, k;
    gets(str);
    gets(str2);
    for (i = 0; i < 101; i++)
    {
        if (str[i] != str2[i])
        {
            k = str[i] - str2[i];
            break;
        }
        else
            k = 0;
    }
    printf("%d", k);
    return 0;
}
