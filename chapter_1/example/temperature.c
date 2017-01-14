#include <stdio.h>
#define LOWER 0
#define STEP  20
#define UPPER 300
/*******************************
 * print Fahrenheit-Celsius table
 * for fahr = 0, 20,40, ... 300
 * *****************************/
/*int main(int argc, char* argv[]) {
 // int fahr, celsius;
  int fahr;
  double celsius;
  int lower, upper, step;

  lower = 0;
  upper = 300;
  step = 20;

  fahr = lower;
  while (fahr <= upper) {
   // celsius = (5/9)*(fahr - 32);
   // in this program the celsius is int and the value of 5/9 is zero
   // so no mater what value multiple 5/9 all would be zero, so the correct
   // method is 5 *value / 9
    celsius = 5.0 * (fahr - 32) / 9;
    printf("%3d\t%6.1lf\n",fahr,celsius);
    fahr += step;
  }
  return 0;
}*/

int main (int argc, char* argv[]) {
  int fahr;
  for (fahr = LOWER; fahr <= UPPER; fahr+=STEP) {
    //celsius = 5.0/9.0*(fahr-32);
    printf("%3d\t%6.1f\n",fahr,5.0/9.0*(fahr-32));
  } 
  return 0;
}
