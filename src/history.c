#include "history.h"
#include "stdio.h"
#include "stdlib.h"

/*  
typedef struct s_Item{
  int id;       
  char *str;
  struct s_Item *next;
}Item;

typedef struct s_List{
  struct s_Item *root;
}List;

*/

//checks length of a sting use in add history
int string_length(char str[]){

  int i;
  for(i=0;str[i] != '\0'; ++i);
  return i;

}

List* init_history(){
  List *list = (List*)malloc(sizeof(List));
  list ->root = NULL;
  return list;
}


void add_history(List *list, char *str) {

  // Allocate memory for the new history item

  Item *tempItem = (Item*)malloc(sizeof(Item));



  // Initialize variables

  Item *temp = list->root; // Temporary pointer to traverse the list

  int id = 0; // Initialize the history ID counter



  // Assign the string to the new history item

  tempItem->str = str;



  // Check if the history list is empty

  if (list->root == NULL) {

    // If the list is empty, make the new item the root

    tempItem->next = NULL;

    tempItem->id = id;

    list->root = tempItem;

  } else {

    // If the list is not empty, find the last item

    id++; // Increment the ID counter



    // Traverse the list until the last item

    while (temp->next != NULL) {

      temp = temp->next;

      id++; // Increment the ID counter for each existing item

    }



    // Assign the ID and set the next pointer of the last item to

    tempItem->next = NULL;

    tempItem->id = id;

    temp->next = tempItem;

  }

}


char *get_history(List *list, int id) {

  // Start from the root of the history list

  Item *current = list->root;



  // Traverse the history list until reaching the end

  while (current != NULL) {

    // Check if the ID of the current history item matches the requested ID

    if (current->id == id) {

      // If found, return the string associated with the current history item

      return current->str;

    }

    // Move to the next history item

    current = current->next;

  }



  // If the requested ID is not found in the history list, return NULL

  return NULL;

}
void print_history(List *list) {

  Item *current = list->root;

  while (current != NULL) {

    printf("%d: %s\n", current->id, current->str);

    current = current->next;

  }

}


void free_history(List *list) {

  Item *current = list->root;

  while (current != NULL) {

    Item *temp = current;

    current = current->next;

    free(temp->str);

    free(temp);

  }

  free(list);

}
//int main(){}
