#include <stdio.h>
/* *************************************
 * this program is to replace the text with 
 * two or more blanks with one blank
 * ************************************/
#define NONBLANK '-'
int main(int argc, char* argv[]) {
  int c;
  int end_char = NONBLANK;
  while ((c = getchar()) != EOF) {
    if (c == ' ' && end_char != ' ') {
      putchar(c);
    }
    else if (c != ' ') {
      putchar(c);
    }
     end_char = c;
  }
  
  return 0;
}

