/*Задача 4. Да се изтрият в този ред върховете 1, 7, 12 и
14 от дървото на*/

#include "sq.h"
treeNode_t *root = NULL;

int arr[11] = {6, 5, 3, 1, 10, 8, 7, 13, 11, 12, 14};

int main()
{

    for (int i = 0; i < 11; i++){
        insertKey(arr[i], &root);
    }
    preorder(root);
    printf("\n");

    root = delElement(root, 1);
    preorder(root);
    printf("\n");

    root = delElement(root, 7);
    preorder(root);
    printf("\n");

    root = delElement(root, 12);
    preorder(root);
    printf("\n");

    root = delElement(root, 14);
    preorder(root);
    return 0;
}