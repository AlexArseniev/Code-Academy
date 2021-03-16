#include "sq.h"

treeNode_t *root=NULL;

int main(){
    insertKey(22,&root);
    insertKey(18,&root);
    insertKey(31,&root);
    insertKey(16,&root);
    insertKey(20,&root);
    preorder(root);
    return 0;
}