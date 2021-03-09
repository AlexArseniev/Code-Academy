/*
Направете същото ползвайки fgetpos().
int fgetpos(FILE *pfile, fpos_t *position);
Първият параметър е указател към файла, вторият параметър е
указател към стандартен параметър дефиниран в stdio.h
Типа fpos_t може да запише всяка позиция във файла.
Функцията връща 0 при успех и различно от 0 при грешка.
Дефинирайте променлива за fpos_t
*/

#include <stdlib.h>
#include <stdio.h>

int main(void){

    FILE *fp = NULL;
    fpos_t position;

    fp = fopen("task11.txt", "w+");

    if(fp == NULL){
        perror("File was not found");
        exit(1);
    }

    fputs("Raiat e vinagi drugade. Raiat drug ad e", fp);

    fgetpos(fp, &position);

    printf("%d characters were printed in the file", position);
    
    return 0;
}