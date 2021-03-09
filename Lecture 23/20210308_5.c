/*
Напишете програма, която чете числа от един текстов файл и ги записва
в друг текстов файл
*/

#include <stdlib.h>
#include <stdio.h>

int main(void){

    FILE *pfile1, *pfile2;

    char filename[200];
    char c;

    printf("Enter the file you want to read: ");
    scanf("%s", &filename);

    pfile1 = fopen(filename, "r");

    if(pfile1 == NULL){
        perror("File was not found");
        exit(1);
    }

    printf("Enter the file you want to write in: ");
    scanf("%s", &filename);

    pfile2 = fopen(filename, "w");

    if(pfile2 == NULL){
        perror("File was not found");
        exit(1);
    }

    while ((c = fgetc(pfile1)) != EOF) {
        fputc(c, pfile2);
    }

    printf("Job done!");
    
    fclose(pfile1);
    fclose(pfile2);

    return 0;
}