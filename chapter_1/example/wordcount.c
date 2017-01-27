#include <stdio.h>
#define IN 1 /* Inside a word*/
#define OUT 0 /* Outside a word*/
/******************************
 *The parameter state is used to examine the character is 
 * inside or outside the word. If the character equals ' ', '\t',
 * or '\n', then the state would be OUT, which means that the
 * character is outside the word. Besides, if the character is the first
 * character of the word, which denotes a new words. Then the number of
 * words would increase.
 * ****************************/
int main(int argc, char* argv[]){
  int ch, nc, nl, nw, state;
  state = OUT;
  nc = nl = nw = 0;
  while((ch = getchar()) != EOF) {
    nc++;
    if (ch == '\n') nl++;
    if (ch == ' ' || ch == '\n' || ch == '\t') {
      state = OUT;
    }
    else if (state == OUT) {
      state = IN;
      nw++;
    }
  }

  printf("%d %d %d\n", nc,nl,nw);
  return 0;
}
