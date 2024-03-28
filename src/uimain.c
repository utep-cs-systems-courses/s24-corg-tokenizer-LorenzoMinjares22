#include "stdio.h"
#include "stdlib.h"
#include "tokenizer.h"
#include "history.h"
 
int main(){
  char input[100] 
  char *str;
  char **tokens = (char**)malloc(100*sizeof(char*));
  List *link_list = init_history();
  goto userInput;
    
 userInput:
   
   printf("Input string input enter when done:");
   while(input[0] != '\n'){
     printf(">");
     fgets(input,sizeof(input),stdin);
     
     if(input[0] == '\n') break;
     str = input;
     tokens =tokenize(str);
     for(int i =0; i<count_tokens(str); i++){
       add_history(link_list, tokens[i]);
     }
   }
   goto history;


 history:
   printf("Get all history: h |  Get specific history: ! |  Done:  \n |  Input More: i");
 
   char his;
   char id;

   his = getchar();
   while(his != '\n'){
     if(his == 'h'){
       print_history(link_list);
       printf("Get all history: h |  Get specific history: ! |  Done:  \n |  Input More: i");
       his = getchar();
    }
     if(his == '!'){
       printf("input ID of history");
       id = getchar();
       printf("history at ID: %d \t %s\n", id, get_history(link_list, id));
       printf("Get all history: h |  Get specific history: ! |  Done:  \n |  Input More: i");
     }

     if(his == 'i'){
       goto userInput;

     }
   } 

printf("thank you !!!");
 

 
}
