#include <stdio.h>
#include <string.h>

int main()
{
    char a[300];
    fgets(a, 300, stdin);

    int i;
    for (i = 0; i < strlen(a); i++)
    {
        if (a[i] >= 'A' && a[i] <= 'Z')
        {
            a[i] = a[i] + 'a' - 'A';
        }
    }

    struct cha
    {
        char chara;
        int num;
    };

    struct cha character[30];

    for (i = 0; i < 26; i++)
    {
        character[i].chara = 'a' + i;
        character[i].num = 0;
    }

    int j;
    for (i = 0; i < strlen(a); i++)
    {
        for (j = 0; j < 26; j++)
        {
            if (a[i] == character[j].chara)
            {
                character[j].num++;
                break;
            }
        }
    }

    struct cha temp;
    for (i = 25; i >= 0; i--)
    {
        for (j = 0; j < i; j++)
        {
            if (character[j].num > character[j + 1].num)
            {
                temp = character[j];
                character[j] = character[j + 1];
                character[j + 1] = temp;
            }
            else if (character[j].num == character[j + 1].num)
            {
                if (character[j].chara < character[j + 1].chara)
                {
                    temp = character[j];
                    character[j] = character[j + 1];
                    character[j + 1] = temp;
                }
                else
                {
                    ;
                }
            }
            else
            {
                ;
            }
        }
    }

    for (i = 25;; i--)
    {
        if (character[i].num == 0 || i < 0)
        {
            break;
        }
        else
        {
            printf("%c %d\n", character[i].chara, character[i].num);
        }
    }

    return 0;
}