#include <stdio.h>
#define DASH '-'
int main(int argc, char* argv[]) {
  int c, num_words,num_character,num_line=0;
  int end_char = DASH;
  while((c = getchar()) != EOF) {
    num_character++;
    if (c == '\n')
      num_line++;
    /* for the if and else if, if the condition of if is true 
     * then even if the condition of else if is true, the statements
     * of else is would not execute*/
    if ((c == '\n' || c == '\t' || c == ' ') && 
        !(end_char == '\n' || end_char == '\t' || end_char == ' ')) {
      num_words++;
      putchar('\n');
    }
    else if (!(c == '\n'|| c == '\t' || c == ' '))
      putchar(c);
    end_char = c;
  }

  if (end_char != '\n')
    num_line++;
  printf("The number of character is\t%d\n,the  number of line is\t%d\nthe number of words is\t%d\n",num_character,num_line,num_words);
  return 0;
}
