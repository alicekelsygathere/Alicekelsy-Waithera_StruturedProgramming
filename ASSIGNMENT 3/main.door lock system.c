#include <stdio.h>
#include <stdlib.h>


#include <stdio.h>

int main()
{
    // variable declaration
    int correctpin = 1234;
    int userpin;

    // prompt and capture PIN
    printf("Please enter pin\n");
    scanf("%d", &userpin);

    if (userpin == correctpin)
    {
        printf("Access Granted\n");
    }
    else
    {
        printf("Access Denied\n");
    }

    return 0;
}
