#include <stdio.h>
#define DASH '-'
int main(int argc, char* argv[]) {
  int c;
  int nc = 0; /* the number of the character*/
  int nl = 0; /* the number of the lines*/
  int nw = 0; /* the number of the words*/
 int end_char = DASH;
  while ((c = getchar()) != EOF) {
    nc++;
    if (c == '\n' && end_char != '\n') 
      nl++;
    /* the next statement can not be else if, since if the condition of 
     * if statement is true, then the else if statement would be executed even
     * if the condition of else if is true*/
    if ((c == ' ' || c == '\n' || c == '\t') && (
          !(end_char == ' ' || end_char == '\n' || end_char == '\t'))) {
        nw++;
        putchar('\n');
        }
    else if (c != ' ' && c != '\n' && c != '\t') {
      putchar(c);
    }
    end_char = c;
  }
  if (end_char != '\n') 
    nl++;
  printf("The number of the character is\t%d\n",nc);
  printf("The number of the lines is\t%d\n",nl);
  printf("The number of the words is\t%d\n",nw);
  return 0;
}
