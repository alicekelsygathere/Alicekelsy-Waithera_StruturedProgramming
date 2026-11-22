#include <stdio.h>

#define MAX 100
#define BUFFER_SIZE 5


int readSize(void)
{
    int n;
    printf("Input the number of elements (1-%d): ", MAX);
    scanf("%d", &n);
    if (n < 1 || n > MAX) {
        printf("Invalid size!\n");
        return 0;
    }
    return n;
}

void readElements(int arr[], int n)
{
    printf("Input %d elements in the array:\n", n);
    for (int i = 0; i < n; i++) {
        printf("element - %d : ", i);
        scanf("%d", &arr[i]);
    }
}
void task1(void)
{
    int arr[MAX];
    int n = readSize();
    if (n == 0) return;
    readElements(arr, n);

    printf("Values: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    printf("\nReversed: ");
    for (int i = n - 1; i >= 0; i--)
        printf("%d ", arr[i]);
    printf("\n");
}
void task2(void)
{
    int arr[MAX], sum = 0;
    int n = readSize();
    if (n == 0) return;
    readElements(arr, n);

    for (int i = 0; i < n; i++)
        sum += arr[i];

    printf("Sum = %d\n", sum);
}
void task3(void)
{
    int arr[MAX];
    int n = readSize();
    if (n == 0) return;
    readElements(arr, n);

    printf("Unique elements: ");
    for (int i = 0; i < n; i++) {
        int count = 0;
        for (int j = 0; j < n; j++)
            if (arr[i] == arr[j])
                count++;
        if (count == 1)
            printf("%d ", arr[i]);
    }
    printf("\n");
}
void task4(void)
{
    int arr[MAX];
    int n = readSize();
    if (n == 0) return;
    readElements(arr, n);

    int max = arr[0], min = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) max = arr[i];
        if (arr[i] < min) min = arr[i];
    }
    printf("Maximum = %d\nMinimum = %d\n", max, min);
}
void task5(void)
{
    int arr[MAX];
    int n = readSize();
    if (n == 0) return;
    readElements(arr, n);

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    printf("Sorted: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
void task6(void)
{
    int arr[MAX + 1];
    int n = readSize();
    if (n == 0 || n == MAX) return;
    readElements(arr, n);

    int value, pos;
    printf("Value to insert: ");
    scanf("%d", &value);
    printf("Position (1-%d): ", n + 1);
    scanf("%d", &pos);
    if (pos < 1 || pos > n + 1) {
        printf("Invalid position!\n");
        return;
    }

    printf("Current list: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    for (int i = n; i >= pos; i--)
        arr[i] = arr[i - 1];

    arr[pos - 1] = value;
    n++;

    printf("\nNew list: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
int buffer[BUFFER_SIZE];
int head = 0;
int count = 0;

void insertSample(int value)
{
    buffer[head] = value;
    head = (head + 1) % BUFFER_SIZE;
    if (count < BUFFER_SIZE)
        count++;
}

void printSamples(void)
{
    int start = (count < BUFFER_SIZE) ? 0 : head;
    printf("Samples (oldest to newest): ");
    for (int k = 0; k < count; k++)
        printf("%d ", buffer[(start + k) % BUFFER_SIZE]);
    printf("\n");
}

void task7(void)
{
    int value;
    head = 0;
    count = 0;

    printf("Enter readings one at a time (-1 to stop):\n");
    while (scanf("%d", &value) == 1 && value != -1)
        insertSample(value);

    printSamples();
}
void task8(void)
{
    int arr[6][4] = {
        { 1,  2,  3,  4}, { 5,  6,  7,  8}, { 9, 10, 11, 12},
        {13, 14, 15, 16}, {17, 18, 19, 20}, {21, 22, 23, 24}
    };

    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 4; j++)
            printf("%3d ", arr[i][j]);
        printf("\n");
    }
}
int main(void)
{
    int choice;

    do {
        printf("\n1.Reverse 2.Sum 3.Unique 4.Max/Min 5.Sort 6.Insert 7.Logger 8.2D 0.Exit\n");
        printf("Choose a task: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: task1(); break;
            case 2: task2(); break;
            case 3: task3(); break;
            case 4: task4(); break;
            case 5: task5(); break;
            case 6: task6(); break;
            case 7: task7(); break;
            case 8: task8(); break;
            case 0: printf("Goodbye!\n"); break;
            default: printf("Invalid choice.\n");
        }
    } while (choice != 0);

    return 0;
}
