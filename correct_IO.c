#include <stdio.h>

int main()
{
    /*corrected program*/
    int num1;
    int num2;
    /*float num3; this variable is not used anywhere*/
    
    /*the value were on the wrong side of the variable for num2*/
    num1 = 400;
    num2 = 600;
    
    printf("the value of num1 is %d\n", num1);
    printf("num2 is %d\n", num2);
    
    getchar();
    return 0;
}