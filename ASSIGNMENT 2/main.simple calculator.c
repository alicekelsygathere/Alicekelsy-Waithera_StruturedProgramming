#include <stdio.h>

int main()
{ //variable declaration
    int a, b;
    int add, sub, multi, mod;
    float div;

    //a) take two numbers as input
    printf("Please enter first number (a):");
    scanf("%d", &a);
    printf("Enter the second number (b);");
    scanf("%d", &b);

    //b) perform arithmetic operations
    add=a + b;
    sub=a - b;
    multi=a * b;

    //c) display results to the user
    printf("\nResults: \n");
    printf("Addition   :%d + %d = %d\n",a, b, add);
    printf("Subtraction  :%d - %d = %d\n",a ,b, sub);
    printf("Multiplication : %d * %d = %d\n", a, b, multi);
 //d) division and modulus need b !=0
 if (b !=0) {
    div =(float)a  / b;
    mod =a %  b;
    printf("Division       : %d / %d =%.2f\n",a ,b, div);
    printf("Modulus        : %d %% %d = %d\n",a ,b, mod);                                                                                                                                                                                                                                                                          }
}  else {
    printf("Division and modulus: cannot divide by zero.\n");

}
    return 0;
    }

