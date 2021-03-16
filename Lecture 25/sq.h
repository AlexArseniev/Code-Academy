#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct treeNode_t treeNode_t;
typedef struct treeNode_t{
int data;
treeNode_t *left;
treeNode_t *right;
}treeNode_t;

extern treeNode_t *root;

treeNode_t *insert(int d);

void preorder(treeNode_t *n);

treeNode_t *search_iter(treeNode_t *t, int n);

treeNode_t *search(int d);

int del(int n);

void insertKey(int x, treeNode_t** t);

treeNode_t *delElement(treeNode_t *t, int key);