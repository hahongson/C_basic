#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bst.h"


tree_t search(key_t x,tree_t root){
    if(root == NULL)
        return NULL;
    else if(strcmp(x,root->data.email) == 0)
       return root;
    else if(strcmp(x,root->data.email) < 0)
       return search(x,root->left);
    else 
       return search(x,root->right);
}

void insertNode(data_t x, tree_t *pRoot){
    if(*pRoot == NULL){       // create root for tree
        *pRoot=(node_t *)malloc(sizeof(node_t));
        (*pRoot)->data = x;
        (*pRoot)->left = NULL;
        (*pRoot)->right = NULL;
    } else{
        if(strcmp(x.email,(*pRoot)->data.email)<0)
            insertNode(x, &((*pRoot)->left));
        else
            insertNode(x,&((*pRoot)->right));
    }
}  
//delete min in tree
key_t deleteMin(tree_t *root) {
  if ((*root)->left == NULL) {
    key_t k = (*root)->data.email;
    (*root) = (*root)->right;
    return k;
  } else
    return deleteMin(&(*root)->left);
}
//Find node (min Value) in tree
tree_t minValue(tree_t root){
    tree_t min = root;   
    while(min && min->left != NULL)

       min = min->left;
    return min;
}

void deleteNode(key_t x,tree_t *pRoot){
    if( *pRoot == NULL)
        return ;
    if(strcmp(x,(*pRoot)->data.email)<0){
        deleteNode(x, &(*pRoot)->left);
    }
    else if(strcmp(x,(*pRoot)->data.email)>0){
        deleteNode(x,&(*pRoot)->right);
    }
    else{
        if((*pRoot)->left == NULL)
            (*pRoot)=(*pRoot)->right;
        else if((*pRoot)->right == NULL)
            (*pRoot)=(*pRoot)->left;
        else{
            tree_t temp = minValue((*pRoot)->right);
            (*pRoot)->data = temp->data;
            deleteNode((*pRoot)->data.email,&(*pRoot)->right);
        }
    }
} 



void prettyPrint(tree_t tree){
    static char prefix[200]= "    ";
    char *prefixend=prefix + strlen(prefix);
    if(tree!=NULL){
        printf("'%04s'",tree->data.key);
        if(tree->left!=NULL)
           if(tree->right==NULL){
            printf("\304");
            strcat(prefix, "     ");
           } else{
            printf("\302");
            strcat(prefix,"\263    ");
           }
        prettyPrint(tree->left);
        *prefixend = '\0';
        if(tree->right != NULL)
            if(tree->left != NULL){
                printf("\n%s", prefix);
                printf("\300");
            } else
              printf("\304");
            strcat(prefix, "     ");
            prettyPrint(tree->right);
    }
}    




void freeTree(tree_t tree){
    if(tree!=NULL){
        freeTree(tree->left);
        freeTree(tree->right);
        free((void *)tree);
    }
}            
