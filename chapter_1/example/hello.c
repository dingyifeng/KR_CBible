#include <stdio.h>
int main(int argc, char * argv[]) { 
  // why the second parameter of main is char* array?
  // think about the main parameter of java is public static void main(String[]
  // args), It is a String array.
  // In C lang, there is no String structure, so char* is used to substitue the
  // String
  printf("Hello\tWorld!\n");
  return 0;
}
