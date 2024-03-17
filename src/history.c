#include "history.h"
#include "stdio.h"
#include "stdlib.h"


typedef struct s_Item{
  int id;
  char *str;
  struct s_Item *next;
}Item;

typedef struct s_List{
  struct s_Item *root;
}List;


List* init_history(){
  list *list = (List*)malloc(sizeof(List));
  list ->root = NULL;
  return list;
}

void
add_history(List *list, char *str){
  Item *new_item = (Item*)malloc(sizeof(Item));
  new_item ->id = (list->root == NULL)? 1: list ->root->id +1;

  //allocate memeory for the sting and coppy its contents
  int length = 0;
  while(str[length] != '\O'){
    length++;
  }

  new_item -> str =(char*)malloc((length +1) * sizeof(char));

}
