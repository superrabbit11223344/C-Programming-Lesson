#include <stdio.h>
#include <math.h>

int main() {
    int a;
    int scoreA = 0, scoreB = 0;
    int winner;
    while (!feof(stdin)) {
        scanf("%d", &a);
        if (a == 0) scoreA++; // 林丹得分
        if (a == 1) scoreB++; // 李宗伟得分
        if (scoreA >= 21 || scoreB >= 21) {
            if (abs(scoreA - scoreB) > 1) {
                winner = scoreA > scoreB ? 0 : 1;
                printf("%d", winner);
                return 0;
            }
        }

    }
}