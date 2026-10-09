#include <stdio.h>

int main() {
    int n, i, band;
    char regNo[20];
    char name[50];
    float marks;
    char grade;

    printf("Enter number of students: ");
    while (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid number. Enter a positive integer: ");
        while (getchar() != '\n');
    }

    for (i = 1; i <= n; i++) {
        printf("\n--- Student %d of %d ---\n", i, n);

        printf("Enter Registration Number: ");
        scanf("%19s", regNo);

        printf("Enter Student Name: ");
        scanf(" %49[^\n]", name);

        printf("Enter Marks (0-100): ");
        while (scanf("%f", &marks) != 1 || marks < 0 || marks > 100) {
            printf("Invalid marks. Enter a value between 0 and 100: ");
            while (getchar() != '\n');
        }

        // A switch needs discrete values, so reduce marks to a "band":
        // 100 -> 10, 90-99 -> 9, 80-89 -> 8, 70-79 -> 7, 60-69 -> 6, ...
        band = (int)marks / 10;

        // Grade using switch-case
        switch (band) {
            case 10:
            case 9:
            case 8:
            case 7:
                grade = 'A';
                break;
            case 6:
                grade = 'B';
                break;
            case 5:
                grade = 'C';
                break;
            case 4:
                grade = 'D';
                break;
            default:            // 0-39
                grade = 'F';
                break;
        }

        printf("\n===== Student Result =====\n");
        printf("Registration No : %s\n", regNo);
        printf("Name            : %s\n", name);
        printf("Marks           : %.2f\n", marks);
        printf("Grade           : %c\n", grade);

        // Pass/Fail (performance classification) using switch-case on the grade
        switch (grade) {
            case 'F':
                printf("Status          : FAIL\n");
                break;
            default:            // A, B, C, D
                printf("Status          : PASS\n");
                break;
        }
    }

    return 0;
}
