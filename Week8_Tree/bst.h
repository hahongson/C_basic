#ifndef __BST_H__
#define __BST_H__

typedef struct phoneAddr_s{
    char name[20];
    char tel[12];
    union {
        char email[28];
        char key[28];
    };
} phoneAddr_t;       //data
typedef char *key_t;      //string

typedef phoneAddr_t data_t; //information

typedef struct node_s{
    data_t data;
    struct node_s *left;
    struct node_s *right;
}node_t;                   //A node of Tree have data, leftchild, rightchild

typedef node_t *tree_t;   //type TREE_T

tree_t search(key_t x,tree_t root);  //trả về giá node chứa giá trị x  
void insertNode(data_t x, tree_t *pRoot);   //Thêm mọt cây con
key_t deleteMin(tree_t *pRoot);        //Xóa nút có giá trị bé nhất
void deleteNode(key_t x,tree_t *pRoot);  //Xóa node bất kỳ trên cây
void prettyPrint(tree_t tree);         //In ra toàn bộ cây
void freeTree(tree_t tree);            //Giải phóng bộ nhớ



#endif
