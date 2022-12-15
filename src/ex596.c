#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void *a, const void *b) {
    return strcmp((char*)a, (char*)b);
}

char* checkSubstr(char* s1, char* s2) {
    // 对s1排序
    qsort(s1, strlen(s1), sizeof(char), cmp);
    
    // 比较排序后的s1和子串是否相同即可即可
    char* pRes = s2;
    while (*pRes != '\0') {
        char subStr[200] = "";
        strncpy(subStr, pRes, strlen(s1));
        qsort(subStr, strlen(subStr), sizeof(char), cmp);
        int result = strcmp(subStr, s1);
        if (result == 0) return pRes;
        pRes++;
    }
    return NULL;
}

int main()
{
    char s1[220], s2[220];
    char *pRes = NULL;

    scanf("%s%s", s1, s2);
    pRes = checkSubstr(s1, s2);

    if ( pRes == NULL )
        printf("false\n");
    else{
        pRes[ strlen(s1) ] = '\0';
        printf("%s", pRes);
    }
    return 0;
}