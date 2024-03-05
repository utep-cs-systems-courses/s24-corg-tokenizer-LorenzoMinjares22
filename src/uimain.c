#include "stdio.h"

int main(){
  char input[100];

  printf(">");
  fgets(input,sizeof(input),stdin);
  printf("%s\n", input);
}
