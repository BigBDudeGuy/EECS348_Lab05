#include <stdio.h>
#include <limits.h>

int main() {
    char filename[1000];
    printf("Enter the name of the file: ");
    scanf("%99s", filename);
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening the file");
        return 1;
    }

    FILE *tempFile = fopen("temp.txt", "w");

    if (tempFile == NULL) {
        perror("Error creating temporary file");
        fclose(file);
        return 1;
    }

    char *months[] = {"January ", "February ", "March ", "April ", "May ", "June ", "July ", "August ", "September ", "October ", "November ", "December "};

    char buffer[1024];
    int monthIndex = 0;

    int maxNumber = INT_MIN;
    int minNumber = INT_MAX;
    int totalNumbers = 0;
    double sum = 0.0;

    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        int number;
        if (sscanf(buffer, "$%d", &number) == 1) {
            if (number > maxNumber) {
                maxNumber = number;
            }

            if (number < minNumber) {
                minNumber = number;
            }

            sum += number;
            totalNumbers++;

            fprintf(tempFile, "%s %s", buffer, months[monthIndex]);
            monthIndex = ((monthIndex + 1) % 12);
        } else {
            fprintf(stderr, "Error reading a number from the file\n");
        }
    }

    fclose(file);
    fclose(tempFile);
    double average = totalNumbers > 0 ? sum / totalNumbers : 0.0;
    printf("Sales Numbers with Months:\n");

    tempFile = fopen("temp.txt", "r");
    if (tempFile == NULL) {
        perror("Error opening the temporary file");
        return 1;
    }

    while (fgets(buffer, sizeof(buffer), tempFile) != NULL) {
        printf("%s", buffer);
    }

    printf("\nStatistics:\n");
    printf("Maximum Number: %d\n", maxNumber);
    printf("Minimum Number: %d\n", minNumber);
    printf("Average Number: %.2lf\n", average);

    fclose(tempFile);
    remove("temp.txt");

    return 0;
}