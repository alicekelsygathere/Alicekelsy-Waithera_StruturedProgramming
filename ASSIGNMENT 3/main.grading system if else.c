#include <stdio.h>

int main() {
    int n, i;
    char regNo[20];
    char name[50];
    float marks;
    char grade;

    printf("Enter number of students: ");
    while (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid number. Enter a positive integer: ");
        while (getchar() != '\n');   // clear bad input
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

        // Grade using if-else if-else
        if (marks >= 70) {
            grade = 'A';
        } else if (marks >= 60) {
            grade = 'B';
        } else if (marks >= 50) {
            grade = 'C';
        } else if (marks >= 40) {
            grade = 'D';
        } else {
            grade = 'F';
        }

        // Display immediately after input
        printf("\n===== Student Result =====\n");
        printf("Registration No : %s\n", regNo);
        printf("Name            : %s\n", name);
        printf("Marks           : %.2f\n", marks);
        printf("Grade           : %c\n", grade);

        // Pass/Fail using if-else
        if (marks >= 40) {
            printf("Status          : PASS\n");
        } else {
            printf("Status          : FAIL\n");
        }
    }

    return 0;
}
