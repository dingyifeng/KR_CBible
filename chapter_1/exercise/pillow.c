#include <stdio.h>
#define is_lower(N) ((N) >= 'a' && (N) <= 'z')
#define is_upper(N) ((N) >= 'A' && (N) <= 'Z')
#define is_alpha(N) (is_lower(N) || is_upper(N))
#define MAX_WD_LEN 1000
#define IN_WORD 0 /* the char is inside the word */
#define OUT_WORD 1 /* the char is outside the word */

int main(int argc, char* argv[]) {
  int i,j;
  int word[MAX_WD_LEN]; /* the array of the words input */
  for (i = 0; i < MAX_WD_LEN; i++)
    word[i] = 0;
  int ch;
  int state = OUT_WORD;
  int first = 0;
  int wc = 0; /* the number of words */
  int len = 0;
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
/*  for (i = 0; i <= wc; i++)
    printf("%d\t",word[i]);*/
  puts("\nSTATISTICS\n");
  int longest = 0;
  for (i = 0; i <= wc; i++)
    if (word[i] > longest) longest = word[i];
  int most = 0;
  for (i = 1; i <= longest; i++) {
    int sum = 0;
    for (j = 0; j <= wc; j++) {
      if (word[j] == i) sum++;
    }
    if (sum > most) most = sum;
    if (sum)
    printf("%d words of length %d\n", sum, i);
  }

  printf("\ngreatest word length : %d\n", longest);
  printf("most words of a given length : %d\n",most);
  puts("\nHORIONTAL HISTOGRAPH\n");
  puts("word input | graph");

  for (i = 0; i <= wc; i++) {
    printf("%10d : ",i+1);
    for (j = word[i]; j > 0; j--)
      putchar('*');
    putchar('\n');
  }

  puts("\nVERTICAL HISTOGRAPH\n");
  puts("Wd Len:");
  for (i = longest; i >= 1; i--) {
    printf("%6d:",i);
    for (j = 0; j <= wc; j++) {
      if (i <= word[j])
        printf("  *");
      else 
        printf("   ");
    }
    putchar('\n');
  }
  for (i = 0; i <= 6; i++)
    putchar(' ');
  for (i = 0; i <= wc; i++)
    printf("===");
  printf("\nWd Inp:");
  for (i = 0; i <= wc; i++)
    printf("%3d",i+1);
  printf("\n");
  return 0;
}
