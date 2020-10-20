#include <stdio.h>


int main()
{
    int v1;
    float v2;
    char v3;
    
    v1 = 1000;
    v2 = -2.5;
    v3 = 's';
    /* becuse of the wrong delimiter the compiler sort of casts the value into correct value types */
    printf("v1 contains %f \n", v1);
    printf("v2 contains %c \n", v2);
    printf("v3 contains %d \n", v3);
    
    getchar();
    return 0;
    
}