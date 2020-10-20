/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Arshad shah
 *
 * Created on 01 October 2019, 09:14
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int main() 
{   
    //variables declared and initialized for sum
    int sum1;
    
    //variables declared and initialized for average
    float num2;
    float sum2;
    float average;
    
    //sum of integers 1 to 5
    sum1 = 1+2+3+4+5;
    printf("The sum of integers 1 to 5 is %d\n",sum1);
    
    //sum and average of floating point values from 1.0 to 2.0
    sum2 = 1.0+1.1+1.2+1.3+1.4+1.5+1.6+1.7+1.8+1.9+2.0;
    average = sum2/10;
    printf("The average of floating values from 1.0 to 2.0 is %f\n",average);
    
    return 0;
}

