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
 * vertical :
 ***************************************************/
#include <stdio.h>
#define is_lower(N) ((N) >= 'a' && (N) <= 'z')
#define is_upper(N) ((N) >= 'A' && (N) <= 'Z')
#define is_alpha(N) (is_lower(N) || is_upper(N))
#define IN_WORD 0
#define OUT_WORD 1
#define MAX_LEN_WORD 100
int main(int argc, char* argv[]) {
  int word[MAX_LEN_WORD]; 
  int i;
  for (i = 0; i < MAX_LEN_WORD; i++) {
    word[i] = 0;
  }
  int ch;
  int state = OUT_WORD;
  int len;
  int wc = 0;
  int first = 1; // to test whether the word is first one
  while ((ch = getchar()) != EOF) {
    if (is_alpha(ch)) {
      if (state == OUT_WORD) {
        state = IN_WORD;
        /* to aviod wc increase when the alpha is the first character of the
         * first word
         */
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
      first = -1;
      state = OUT_WORD;
    }
  }
  word[wc] = len; // bump the last word, since the procedure process at the very beginning
  // of the word. The while quit without the process of the last word.
  int max_len = 0;
  // the maximum length of the input words
  for (i = 0; i < MAX_LEN_WORD; i++) {
   if (word[i] >= max_len) max_len = word[i]; 
  }
  int j;

  printf("HORIONTAL HISTOGRAPH\n");
  putchar('\n');
  printf("word length |  graph\n");
  for (i = 0; i <= wc; i++) {
    for (j = word[i]; j >= 1; j--) {
      if (j == word[i])
        printf("%11d :  ",i+1);
      putchar('*');
    }
    putchar('\n');
  }

  /* this inserted for loop is to print vertically, the outer loop is to print as column,
   * the inside loop is to print as line*/
  printf("\n\n");
  printf("VERTICAL HISTOGRAPH");
  putchar('\n');
  putchar('\n');

  for (i = max_len; i >= 1; i--) {
      printf("%6d: ",i);
    for (j = 0; j <= wc; j++) {
      if (i <= word[j]){
        putchar('*');
        putchar(' ');
        putchar(' ');
      }
      else {
        putchar(' ');
        putchar(' ');
        putchar(' ');
      }
    }
    putchar('\n');
  }
  printf("        ");
  for (i = 0; i <=wc; i++) {
    putchar('=');
    putchar('=');
    putchar('=');
  }
  putchar('\n');
  printf("Wd Ln:");
  for (i = 0; i <= wc; i++)
    printf("%3d",i+1);
  putchar('\n');

  return 0;
}
