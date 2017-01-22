/*********************************************
 *ex_1_13: Write a program to print a histogram of the lengths of words in its
 * input. It is easy to draw the histogram with the bars horizontal; a vertical 
 * orientation is more challenging.
 * This program is more like a frequency statistics process, which counts
 * the time of the very apperance of the words with specified length.
 * *******************************************/

#include <stdio.h>
#define is_lower(N) ((N) >= 'a' && (N) <= 'z')
#define is_upper(N) ((N) >= 'A' && (N) <= 'Z')
#define is_alpha(N) (is_lower(N) || is_upper(N))
#define IN_WORD 0
#define OUT_WORD 1
#define MAX_WD_LEN 100
int main(int argc, char* argv[]) {
  int ch;
  int state = OUT_WORD;
  int len = 0;
  int word[MAX_WD_LEN];
  int i,j;
  int first_char = 0;
  for (i = 0; i < MAX_WD_LEN; i++) {
    word[i] = 0;
  }
  while ((ch = getchar()) != EOF) {
    if (is_alpha(ch)) {
      if (state == OUT_WORD) {
        state = IN_WORD;
        if (first_char == -1) {
          ++word[len];
        }
        len = 1;
      }
      else ++len;
    }
    else {
      first_char = -1;
      state = OUT_WORD;
    }

  }
  ++word[len];

/*  for (i = 0; i <= 10; i++)
    printf("%d\t",word[i]);*/
  int longest = 0, most = 0;
  puts("\nSTATISTICS\n");
  for (i = 1; i < MAX_WD_LEN; i++) {
    if (word[i] && i > longest) longest = i;
    if (word[i] > most) most = word[i];
    if (word[i]) {
      printf("%2d words of length %d\n",word[i],i);
    }
  }
  printf("\ngreatest word length : %d\n",longest);
  printf("most words of a given length: %d\n",most);
  /* horizontal histograph */
  puts("\nHORIONTAL HISTOGRAPH");
  puts("\nword length | graph");
  for (i = 1; i <= longest; i++) {
    printf("%11d : ",i);
    for (j = 1; j <= word[i]; j++) 
      printf("x");
    putchar('\n');
  }

  /* vertical histograph */
  puts("\nVERTICAL HISTOGRAPH");
  puts("\nWd Ct:");
  
  for (i = most; i >= 1; i--) {
    printf("%5d:   ",i);
    for (j = 1; j <= longest; j++) {
      if (word[j] < i) printf("    ");
      else printf("x   ");
    }
    putchar('\n');
  }
  printf("       ");
  for (i = 1; i <= longest; i++) 
    printf("====");
  printf("\nWd Ln:");
  for (i = 1; i <= longest; i++)
    printf("%4d",i);
  putchar('\n');


  return 0;
}
