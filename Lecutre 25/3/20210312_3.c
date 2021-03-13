/*Задача 3.
Направете едносвързан списък, съдържащ числата 1-14 и
принтирайте петия елемент от края му.*/
#include <stdio.h>
#include <stdlib.h>
#include "3.h"

node_t *start;

int main(){
    init();
    add(1);
    for(int i=2;i<=14;i++){
        addEnd(i);
    }
    printList();
    node_t *p=start;
    int count=1;
    while(p->next!=NULL){ 
        p=p->next;
        count++;
    }
    printf("\nElements total: %d\n",count);
    p=start;
    int i=1;

    while (i!=(count-5)){
        p=p->next;
        i++;
    }

    printf("The 5th element from the end is %d\n",p->data);

    return 0;
}
