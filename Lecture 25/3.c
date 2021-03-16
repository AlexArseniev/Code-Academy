#include "3.h"

void preorder(treeNode_t *n)
{
    if (n)
    {
        printf("%d, ", n->data);
        preorder(n->left);
        preorder(n->right);
    }
}

void insertKey(int x, treeNode_t** t)
{
    treeNode_t *temp = NULL;
    if (!(*t)){
        temp = (treeNode_t *)malloc(sizeof(treeNode_t));
        temp->left = temp->right = NULL;
        temp->data = x;
        *t = temp;
        return;
    }
    if (x < (*t)->data){
        insertKey(x, &(*t)->left);
    }
    else if (x > (*t)->data){
        insertKey(x, &(*t)->right);
    }
}