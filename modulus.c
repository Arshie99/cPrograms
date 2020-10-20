/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Arshad shah
 *
 * Created on 01 October 2019, 10:41
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int main() 
{
    //variables declared and initialized
    float mod1 = 2 % 2;
    float mod2 = 3 % 2;
    float mod3 = 5 % 2;
    float mod4 = 7 % 3;
    float mod5 = 100 % 33;
    float mod6 = 100 % 7;
    
    
    //calculation of the modulus
    printf("The modulus of the values are as follows %f\n",mod1);
    printf("The modulus of the values are as follows %f\n",mod2);
    printf("The modulus of the values are as follows %f\n",mod3);
    printf("The modulus of the values are as follows %f\n",mod4);
    printf("The modulus of the values are as follows %f\n",mod5);
    printf("The modulus of the values are as follows %f",mod6);
    return 0;
}

