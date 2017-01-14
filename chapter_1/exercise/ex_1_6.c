#include <stdio.h>
/* *******************************
 * this program is to test the value
 * of getchar() != EOF is 0 or 1
 * *******************************/
/*int main(int argc, char* argv[]) {
  int c = getchar();
  if (c == EOF) putchar('+');
  else putchar('-');
  
  return 0;
}*/

int main(int argc, char* argv[]) {
  int c;
  while ((c = getchar()) != EOF) {
    printf("character c not equal to EOF%d",c != EOF);
    if (c == ' ') {
      printf("blank");
    }
    else {
      putchar(c);
    }
    putchar('\n');
  }
  printf("\n%d\n",c != EOF); /*this is 
  the statement when c equals EOF would be executed*/
  return 0;
}
