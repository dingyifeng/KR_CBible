/************************************************
 * Write a program to print a histogram of the lengths of words in its input. It
 * is easy to draw the histogram with the bars horizontal; a vertical
 * orientation is more challenging.
 * Input I love C programming
 * horizontal :
 * The output should be.:
 * *
 * ****
 * *
 * ***********
 * vertical:
 * *******************************************************/
#include <stdio.h>
#define is_lower(N) ((N) >= 'a' && (N) <= 'z')
#define is_upper(N) ((N) >= 'A' && (N) <= 'Z')
#define is_alpha(N) (is_lower(N) || is_upper(N))
#define IN_WORD 0
#define OUT_WORD 1
#define MAX_WRD_LEN 1000

int main(int argc, char* argv[]) {
  int word[MAX_WRD_LEN];
  int i, j;
  for (i = 0; i < MAX_WRD_LEN; i++) 
    word[i] = 0;
  int ch;
  int first = 0;
  int len = 0;
  int state = OUT_WORD;
  int wc = 0;
  while ((ch = getchar()) != EOF) {
    if (is_alpha(ch)) {
      if (state == OUT_WORD) {
        state = IN_WORD;
        if (first == -1) {
          word[wc++] = len;
        }
        len = 1;
      }
      else {
        len++;
      }
    }
    else {
      state = OUT_WORD;
      first = -1;
    }

  }
  word[wc] = len;

  /*for (i = 0; i <= 10; i++)
    printf("%d\n",word[i]);*/
  puts("STATISTICS\n");
  int most = 0;
  int longest = 0;
  for (i = 1; i <= 20; i++) {
    int sum = 0;
    for (j = 0; j <= wc; j++) {
    if (longest <= word[j]) longest = word[j];
      if (i == word[j]) sum++;
    }
    if (most < sum) most = sum;
    if (sum != 0)
      printf("%d words of length %d\n",sum, i);
  }


  printf("\ngreastest word of length: %d\n",longest);
  printf("most words of a given length: %d\n",most);
  puts("\nHORIONTAL HISTOGRAH\n");
  puts("word input | graph\n");
  for (i = 0; i <= wc; i++){
    printf("%10d : ", i+1);
    for (j = word[i]; j > 0; j--)
      putchar('*');
    putchar('\n');
  }


  puts("\nVERTICAL HISTOGRAPH\n");
  puts("Wd Len");
  for (i = longest; i >= 1; i--) {
    printf("%6d: ",i);
    for(j = 0; j <= wc; j++) {
      if (i <= word[j]) {
        printf("  *");
      } 
      else {
        printf("   ");
      }
    }
    putchar('\n');
  }
  for (i = 8; i > 0; i--)
  printf(" ");
 
  for (i = 0; i <= wc; i++)
    printf("===");
  printf("\nWord  : ");
  for (i = 0; i <= wc; i++)
    printf("%3d",i+1);
  printf("\n");

  
  return 0;
}
