#include "stdio.h"
#include "stdlib.h"
#include "tokenizer.h"
#include "history.h"
 
int main(){
  char input[100]; // Added a semicolon

  char *str;

  char **tokens;

  List *link_list = init_history();

  goto userInput;

  
 userInput:

  printf("Input string input enter when done:");

  while (1) {

    printf(">");

    fgets(input, sizeof(input), stdin);



    if (input[0] == '\n')

      break;

    str = input;

    tokens = tokenize(str);

    for (int i = 0; i < count_tokens(str); i++) {

      add_history(link_list, tokens[i]);

    }

    free(tokens); // Free the memory allocated for tokens

  }

  goto history;



 history:

  printf("Get all history: h |  Get specific history: ! | Done: d \n");



  char his;

  int id; // Changed id to integer type



  while (1) {

    his = getchar();

    if (his == '\n')

      continue;

    if (his == 'h') {

      print_history(link_list);

      printf("Get all history: h |  Get specific history: ! | Done: d \n");

    } else if (his == '!') {

      printf("input ID of history: ");

      scanf("%d", &id); // Read integer ID

      getchar();        // Consume newline character

      printf("history at ID: %d \t %s\n", id, get_history(link_list, id));

      printf("Get all history: h |  Get specific history: ! | Done: d \n");

    } else if (his == 'i') {
      goto userInput;

    } else if (his == 'd'){
      break;
    }

  }



  printf("thank you !!!");



  return 0;

}
