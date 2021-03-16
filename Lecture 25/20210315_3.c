/*Задача 3. Да се построи наредено двоично дърво за
търсене чрез последователно добавяне на следните
върхове:
а) 7, 14, 28, 35, 65, 12, 18, 42, 81, 64, 61, 4, 13
б) 12, 7, 14, 81, 42, 18, 61, 4, 64, 35, 13, 28, 65
в) 4, 7, 12, 13, 14, 18, 28, 35, 42, 61, 64, 65, 81
г) 81, 65, 64, 61, 42, 35, 28, 18, 14, 13, 12, 7, 4
д) 28, 64, 13, 42, 7, 81, 61, 4, 12, 65, 35, 18, 14
Да се сравнят получените дървета. Какви изводи могат
да се направят?*/
#include "3.h"
#define ARRSIZE 13

treeNode_t *rootA=NULL;
treeNode_t *rootB=NULL;
treeNode_t *rootV=NULL;
treeNode_t *rootG=NULL;
treeNode_t *rootD=NULL;

int A[ARRSIZE]={7, 14, 28, 35, 65, 12, 18, 42, 81, 64, 61, 4, 13};
int B[ARRSIZE]={12, 7, 14, 81, 42, 18, 61, 4, 64, 35, 13, 28, 65};
int V[ARRSIZE]={4, 7, 12, 13, 14, 18, 28, 35, 42, 61, 64, 65, 81};
int G[ARRSIZE]={81, 65, 64, 61, 42, 35, 28, 18, 14, 13, 12, 7, 4};
int D[ARRSIZE]={28, 64, 13, 42, 7, 81, 61, 4, 12, 65, 35, 18, 14};

int main(){
    for(int i=0; i<ARRSIZE; i++){
        insertKey(A[i],&rootA);
        insertKey(B[i],&rootB);
        insertKey(V[i],&rootV);
        insertKey(G[i],&rootG);
        insertKey(D[i],&rootD);
    }
    preorder(rootA);
    printf("\n");
    preorder(rootB);
    printf("\n");
    preorder(rootV);
    printf("\n");
    preorder(rootG);
    printf("\n");
    preorder(rootD);
    printf("\n");
    return 0;
}
© 2021 GitHub, Inc.