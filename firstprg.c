#include <stdio.h>

int main() {
    int n;

    printf("Enter number of subjects: ");
    scanf("%d", &n);

    // Arrays for subject names and marks
    char subjects[n][50];   // each subject name up to 49 chars
    float marks[n];

    float sum = 0;
    int count = 0;

    // Input subject names and marks
    for (int i = 0; i < n; i++) {
        printf("\nEnter name of subject %d: ", i + 1);
        scanf("%s", subjects[i]);   // NOTE: no spaces allowed

        printf("Enter marks for %s: ", subjects[i]);
        scanf("%f", &marks[i]);
    }

    // Process data
    printf("\n--- Passed Subjects ---\n");
    for (int i = 0; i < n; i++) {
        if (marks[i] >= 40) {
            printf("%s: %.2f\n", subjects[i], marks[i]);
            sum += marks[i];
            count++;
        }
    }

    // Output result
    if (count > 0) {
        float average = sum / count;
        printf("\nAverage of passed subjects = %.2f\n", average);
    } else {
        printf("\nStudent failed in all subjects. No average.\n");
    }

    return 0;
}