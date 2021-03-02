/*Задача 11. тайпдефната структура node, съдържаща един член от
тип инт и един пойнтер към тип самата структура. Заделете динамично
памет за тази структура с malloc по описания по-горе начин.*/
#include <stdio.h>
#include <stdlib.h>
#pragma pack (1)
typedef struct node{int n; node_t *node;}node_t;
typedef node_t * t_ptrNode;
int main(){
    t_ptrNode one=(t_ptrNode)malloc(12);
    printf("%d",sizeof(one));
    free(one);
    return 0;
}