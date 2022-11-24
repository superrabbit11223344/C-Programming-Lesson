#include <stdio.h>
#include <string.h>

int main()
{
    char s1[60], s2[60];
    char s1_copy[60];
    gets(s1);
    gets(s2);
    strcpy(s1_copy, s1);
    strcat(s1, s1_copy);
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