/*
Напишете програма, която да намери общия брой на
редовете в текстови файл.
Създайте файл, който съдържа няколко реда текст.
Внимавайте къде позиционирате файла.
Отворете файла. Използвайте променлива, която да
брои броя на редовете.
*/

#include <stdio.h>
#include <stdlib.h>

int main(void){

    FILE *fp;
    fp = fopen("task13.txt", "w+");

    if(fp == NULL){
        perror("File not found");
        exit(-1);
    }

    fputs("S prah v dushata i prah po nozete,\ns neponosimoto slunce na ramoto\naz sum trugnal da stigna moreto,\nno ot godini sedia vurhu kamuka.", fp);

    rewind(fp);
    char c;
    int count = 1;

    while ((c = fgetc(fp)) != EOF){
        if(c == '\n'){
            count++;
        }
    }
    printf("There are %d lines in the file", count);

    fclose(fp);
    return 0;
}