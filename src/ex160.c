#include <stdio.h>
#include <string.h>

int main()
{
    char s1[60], s2[26];
    gets(s1);
    gets(s2);
    strcat(s1, s2);
    int i;
    for (i = 0; i < strlen(s1) - strlen(s2); i++)
    {
        if (strncmp(s1 + i, s2, strlen(s2)) == 0)
        {
            printf("true");
            return 0;
        }
    }
    printf("false");
    return 0;
}