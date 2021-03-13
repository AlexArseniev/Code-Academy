#include <stdio.h>
#include <stdlib.h>
typedef struct node_t node_t;

typedef struct node_t{
int data;
node_t *next;
}node_t;

extern node_t *start;

int add(int data);

int addAfter(int n, int k);

int addPrev(int n, int k);

int addEnd(int n);

int dellFirst(int *n);

void dellElem(int n);

node_t *dellElemReturnAfter(int *n, int k);

void printList();

void printAfter(node_t *curr);

void dellEnd(int *n);

node_t *search_iter(int k);
