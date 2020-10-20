
/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Arshad shah
 *
 * Created on 01 October 2019, 10:32
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int main() 
{
    //variables declared
    float radius = 4.8;
    float pi = 3.14;
    float area;
    
    //calculation
    area = pi * radius*radius;
    printf("The area of the circle is %4.2f cm^2",area);
	getchar();
    return 0;
}

