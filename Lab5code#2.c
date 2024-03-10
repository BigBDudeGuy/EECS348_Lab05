#include <stdio.h>
void calculateScoreCombinations(int score, int td, int fg, int safety, int td2pt, int td1pt) {
    for (int tdCount = 0; tdCount <= score / td; tdCount++) {
        for (int fgCount = 0; fgCount <= score / fg; fgCount++) {
            for (int safetyCount = 0; safetyCount <= score / safety; safetyCount++) {
                for (int td2ptCount = 0; td2ptCount <= score / td2pt; td2ptCount++) {
                    for (int td1ptCount = 0; td1ptCount <= score / td1pt; td1ptCount++) {
                        int totalScore = tdCount * td + fgCount * fg + safetyCount * safety + td2ptCount * td2pt + td1ptCount * td1pt;
                        if (totalScore == score) {
                            printf("%d TDs, %d Field Goals, %d Safeties, %d 2-point Conversions, %d 1-point Field Goals\n", td2ptCount, td1ptCount, tdCount, fgCount, safety);
                        }
                    }
                }
            }
        }
    }
}

int main() {
    int userNumber;
    const int TD = 6;
    const int FG = 3;
    const int Safety = 2;
    const int TD_Conv = 8;
    const int TD_FG = 7;

    printf("Please enter a number: ");
    scanf("%d", &userNumber);
    if (userNumber == 0 || userNumber == 1) {
        printf("Program ending. 1 or 0 is not possible\n");
        return 0;
    } else {
        printf("Here are all possible combinations for the score: %d:\n", userNumber);
        calculateScoreCombinations(userNumber, TD_Conv, TD_FG, TD, FG, Safety);
    }
    return 0;
}
