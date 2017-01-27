#include <stdio.h>
#define is_digit(N) ((N) >= '0' && (N) <= '9')
#define is_white(N) ((N) == ' ' || (N) == '\t' || (N) == '\n')
int main(int argc, char* argv[]) {
  int digit[10];
  int i;
  for (i = 0; i < 10; i++)
    digit[i] = 0;
  int ch;
  int nwhite = 0;
  int nother = 0;
  while ((ch = getchar()) != EOF) {
    /*if (ch >= '0' && ch <= '9')*/
    if (is_digit(ch))
      ++digit[ch - '0'];
   /* else if (ch == ' ' || ch == '\t' || ch == '\n')*/
    else if (is_white(ch))
      ++nwhite;
    else
      ++nother;
  }
  printf("digits = ");
  for (i = 0; i < 10; i++) 
    printf("%d\t",digit[i]);

  printf(", white space = %d, other = %d\n", nwhite, nother);

  return 0;
}
