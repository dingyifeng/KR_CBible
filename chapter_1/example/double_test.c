#include <stdio.h>
/* ************************************* 
 * the inputs from keyboard are all characters
 * so integer, float, double, or string are all
 * character string
 * This program to test if the fraction part of 
 * input float is  very long, then whether the output 
 * would have a precision fraction part)
 * *************************************/
int main (int argc, char* argv[]) {
  float x;
  scanf("%f",&x);
  printf("the input float is %f",x);
  return 0;
}
