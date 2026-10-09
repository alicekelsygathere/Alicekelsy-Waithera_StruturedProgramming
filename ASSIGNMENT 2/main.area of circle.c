#include <stdio.h>
#include <stdlib.h>

 int main()

{
    //variables
    double area;
    double r;
    const double pi=3.142;

    //request radius

    printf("Please enter radius\n");
    scanf("%lf",&r);
    area=pi*r*r;
    printf("The area is %lf\n",area);
    return 0;
}
