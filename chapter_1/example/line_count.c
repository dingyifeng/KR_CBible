/*#include <stdio.h>
int main(int argc, char* argv[]) {
  int line_num = 0;
  int char_end;
  int c;
  while ((c = getchar()) != EOF) {
    if (c == '\n') 
      line_num++;
    char_end = c;
  }
  if (char_end != '\n')
    line_num++;
  printf("The line of input is %d\n",line_num);
  return 0;
}*/

#include <stdio.h>
int main(int argc, char* argv[]) {
  int c, end_char;
  int num_line = 0;
  while ((c = getchar()) != EOF) {
    if (c == '\n') {
      num_line++;
    }
    end_char = c;
  }
  if (end_char != '\n') 
    num_line++;
  printf("The line of the input is\t%d",num_line);

  return 0;
}
