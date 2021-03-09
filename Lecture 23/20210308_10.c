/*
Намерете позицията си във файла.
long ftell(FILE *pfile);
Функцията приема указател към файла като параметър и връща long
int, който отговаря на позицията във файла.
Дефинирате променлива
long fpos = ftell(pfile)
Променливата съхранява текущата ви позицията в байтове от
началото на файла и вие можете да се върнете на нея по всяко
време.
*/

#include <stdio.h>
#include <stdlib.h>

int main(void){

    FILE *fp = NULL;

    fp = fopen("task10.txt", "w+");

    if(fp == NULL){
        perror("File not found");
        exit(1);
    }

    fputs("Something...somthing...dark side", fp);

    long fpos = ftell(fp);

    printf("%ld\n", fpos);

    rewind(fp);

    fpos = ftell(fp);

    printf("%ld", fpos);

    fclose(fp);
    
    return 0;
}