/*Задача 5. Да се напише рекурсивен вариант на
функцията за обхождане на двоично дърво.*/
#include "tree.h"

treeNode_t *search_rec(treeNode_t *t, int n)
{
    if (t != NULL)
        if (t->data < n)
            t = search_rec(t->right, n);
        else if (t->data > n)
            t = search_rec(t->left, n);
    return t;
}

treeNode_t *root=NULL;

int arr[11]={6,5,3,1,10,8,7,13,11,12,14};

int main(){
    for(int i=0; i<11; i++){
        insertKey(arr[i],&root);
    }
    
    treeNode_t *t=search_rec(root,8);

    printf("search_rec() function returns %d",t->data);
    
    return 0;
}