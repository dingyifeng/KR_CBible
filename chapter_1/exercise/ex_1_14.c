/****************************************************
 * Write a program to print a histogram of the frequencies of dif- ferent
 * characters in its input.
 * the ASCII number of the characters can be output is from 33 to 126, there 
 * is 126 - 33 + 1 = 94 characters in total
 * *************************************************/
#include <stdio.h>
#define ch_out(N) ((N) >= 33 && (N) <= 126) 
int main(int argc, char* argv[]) {
  int ch;
  int ch_out[94];
  int i,j;
  int longest = 0;
  for (i = 0; i < 94; i++)
    ch_out[i] = 0;
  while ((ch = getchar()) != EOF) {
    if (ch_out(ch)) {
      ch_out[ch-33]++;
    }
    if (ch_out[ch-33] > longest)
      longest = ch_out[ch-33];
  }
  /*for (i = 0; i < 94; i++)
    printf("%d ", ch_out[i]);*/
  for (i = longest; i >= 1; i--) {
    printf("%2d|",i);
    for (j = 0; j < 94; j++) {
      if (i <= ch_out[j])  {
        printf("%c",j+33);
      }
      else printf(" ");
    }
    putchar('\n');
  }
  printf("  ");
  putchar('+');
  for (i = 0; i < 94; i++)
    putchar('-');
  putchar('\n');
  printf("   ");
  for (i = 0; i < 94; i++)
    printf("%c",i + 33);
  printf("\n");

  return 0;
}
