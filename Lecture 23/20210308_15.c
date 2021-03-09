/*
Напишете програма, която печата съдържанието на файл в обратен
ред.
Използвайте fseek функцията, за да отидете накрая на файла.
Използвайте ftell функцията, за да намерите позицията на пойнтера.
Покажете на екран файла, обърнат в обратен ред.
*/

#include <stdlib.h>
#include <stdio.h>

int main(void){

    FILE *fp;
    fp = fopen("task15.txt", "w+");
    if(fp == NULL){
        perror("File not found");
        exit(1);
    }
    fputs("I need coffee", fp);

    printf("The reverse string: ");

    int cPosistion = 0;
    fseek(fp, 0, SEEK_END);
    cPosistion = ftell(fp);

    for(int i = 1; i <= cPosistion; i++){
        fseek(fp, -i, SEEK_END);
        printf("%c", fgetc(fp));
    } 

    fclose(fp);
    return 0;
}