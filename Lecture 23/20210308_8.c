/*
Напишете стринг в текстов файл.
int fputs (const char *str, FILE *pfile);
Първият параметър е указател към стринга, който искаме да
запишем, вторият параметър е указател към файла, в който ще
пишем.
Функцията ще записва символи от стринга догато достигне
терминиращ символ \0, но не го пише в новия файл.
*/

#include <stdio.h>
#include <stdlib.h>

int main(void){

    FILE *fp = NULL;
    
    fp = fopen("task8.txt", "w+");

    if(fp == NULL){
        perror("File not found");
        exit(1);
    }

    fputs("My cat loves to sleep", fp);
    fputs(" and eat", fp);

    fclose(fp);
    return 0;
}