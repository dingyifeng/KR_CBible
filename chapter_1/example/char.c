#include <stdio.h>
/*int main(int argc, char* argv[]) {

  int c; // the return type of getchar is integer
//  c = getchar();
  int num_Char = 0; 
  while ((c = getchar()) != EOF) {
    putchar(c);
    num_Char++;
 //   c = getchar();
  }
  printf("The number of input char is %d\n",num_Char);
  printf("The value of EOF is %d\n",EOF);
  return 0;
}*/
int main(int argc, char* argv[]) {

  int num_Char;
  for (num_Char = 0; getchar() != EOF;++num_Char);
  printf("The number of input char is %d\n",num_Char);
  return 0;
}
