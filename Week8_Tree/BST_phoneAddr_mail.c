/*
    Hạ Hồng Sơn  20215130
    Date: 16/12/2022
*/
// Exercise
// - Create an binary search tree with 10 nodes. 
// - Ask user to input an email and search for it.
// - Print the content of the trees. 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "bst.h"


void showNode(tree_t node){
    printf("%-10s%-15s%-15s\n",node->data.name,node->data.tel,node->data.email);
}

int main() {
    data_t A[11]={
        {"K", "0397541644", "A@gmail.com"},
        {"C", "0397541644", "C@gmail.com"},
        {"D", "0397541644", "D@gmail.com"},
        {"B", "0397541644", "B@gmail.com"},
        {"E", "0397541644", "E@gmail.com"},
        {"S", "0397541644", "S@gmail.com"},
        {"P", "0397541644", "P@gmail.com"},
        {"A", "0397541644", "K@gmail.com"},
        {"N", "0397541644", "N@gmail.com"},
        {"I", "0397541644", "I@gmail.com"},
    };
  tree_t tree = NULL;
  
  // Create an binary search tree with 10 nodes.
  for(int i=0;i<10;i++){
    insertNode(A[i],&tree);
  }
  // Print the content of the trees. 
  prettyPrint(tree);  printf("\n");

  char mail[30];  // mail: email wanted to be searched.
  while (1) {
    // Ask user to input an email and search for it.
      printf("\nPress email to search (Enter \"Q\" to quit): ");  fflush(stdin);
      scanf("%s",mail);
      if(strcmp(mail,"Q")==0)
          break;
    // Search 
      tree_t p;
      p = search(mail,tree);

      if (p != NULL){
          printf("Key %s found on the tree\n\n", mail);
          printf("%-10s%-15s%-15s\n","name","telephone","email");
          showNode(p);
      }
      else {
        printf("Not found!\nAdd information in tree: name-telephone\n");
        data_t newdata;
        printf("Enter name: "); scanf("%s",newdata.name);
        printf("Enter telephone: "); scanf("%s",newdata.tel);
        strcpy(newdata.email,mail);
        insertNode(newdata,&tree);
        prettyPrint(tree);
      }
  }
  freeTree(tree);
  return EXIT_SUCCESS;
}
