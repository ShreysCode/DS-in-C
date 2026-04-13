#include <stdio.h>

int main() {
    int n;

    printf("Enter number of subjects: ");
    scanf("%d", &n);

    char subjects[n][50];
    float marks[n];

    float sum = 0;
    int count = 0;

    for (int i = 0; i < n; i++) {
        printf("\nEnter name of subject %d: ", i + 1);
        scanf("%s", subjects[i]);
        printf("Enter marks for %s: ", subjects[i]);
        scanf("%f", &marks[i]);
    }

    printf("\n--- Passed Subjects ---\n");
    for (int i = 0; i < n; i++) {
        if (marks[i] >= 40) {
            printf("%s: %.2f\n", subjects[i], marks[i]);
            sum += marks[i];
            count++;
        }
    }

    if (count > 0) {
        float average = sum / count;
        printf("\nAverage of passed subjects = %.2f\n", average);
    } else {
        printf("\nStudent failed in all subjects. No average.\n");
    }

    return 0;
}