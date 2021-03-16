#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct treeNode_t treeNode_t;
typedef struct treeNode_t{
int data;
treeNode_t *left;
treeNode_t *right;
}treeNode_t;



extern treeNode_t *rootA;
extern treeNode_t *rootB;
extern treeNode_t *rootV;
extern treeNode_t *rootG;
extern treeNode_t *rootD;


void preorder(treeNode_t *n);


void insertKey(int x, treeNode_t** t);