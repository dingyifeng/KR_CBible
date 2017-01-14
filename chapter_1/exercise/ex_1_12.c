#include <stdio.h>
/* *********************************
 * this program is to count the words
 * and output the words in the line
 * *********************************/
#define DASH '-'
int main(int argc, char* argv[]) {
  int c;
  int num_words;
  int end_char = DASH;
  while ((c = getchar()) != EOF) {
    if((c == ' ' || c == '\t' || c == '\n') && 
        (end_char != ' ' && end_char != '\t' && end_char != '\n' )) {
        num_words++;
        putchar('\n');
    }
    else if (c != ' ' && c != '\t' && c!= '\n') 
      putchar(c);
    end_char = c;
  }
  printf("The number of words is\t%d",num_words);

  return 0;
}
