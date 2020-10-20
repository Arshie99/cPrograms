/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Arshad shah
 *
 * Created on 01 October 2019, 09:30
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int main() 
{
    //volume of a box
    
    //volume variables declared and initialized
    int height = 10;
    float length = 11.5;
    float width = 2.5;
    float volume;
    float surface;
    
    //calculation of volume
    volume = length * width * height;
    printf("The volume of the box is %f cm^3.\n",volume);
    
    //calculation for rectangular cuboid 
    surface = 2*( height*length + width*height + width*length);
    printf("The Surface Area of the object is %f cm^2.\n",surface);
    
    return 0;
}

