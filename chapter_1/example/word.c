#include <stdio.h>
#define IN 1 /* Inside the word*/
#define OUT 0 /* Outside the word*/

int main(int argc, char* argv[]) {
  int ch;
  int nc, nl, nw, state;
  nc = nl = nw = 0;
  state = OUT;
  while ((ch = getchar()) != EOF) {
    nc++;
    if (ch == '\n' || ch == ' ' || ch == '\t')
      state = OUT;
    else if (state == OUT) {
      state = IN;
      nw++;
    }
  }

  printf("%d %d %d\n",nc,nl,nw);
  return 0;
}
