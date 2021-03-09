/*
Напишете текст с форматиращ параметър.
int fprint(FILE* stream, const char *forma…);
Първият параметър е файл стрийм, вторият е
форматиращият знак, следван от броя му и т.н.
Форматиращият знак може да е спейс, спецификатор и
т. н.
При успешно изпълнение функцията връща броя на
записаните символи, при грешка връща негативна
стойност.
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(void){

    FILE *fp = NULL;
    fpos_t position;

    fp = fopen("task9.txt", "w+");

    if(fp == NULL){
        perror("File not found. Sorry");
        exit(-1);
    } else{
        fprintf(fp,"%s %s %s", "This is", "some random", "message");
        fgetpos(fp, &position);
        printf("%d characters were printed to the file", position);
    }

    fclose(fp);
    return 0;
}