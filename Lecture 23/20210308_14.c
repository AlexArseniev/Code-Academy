/*
Напишете програма, която да обръща всички символи в
текстов файл, с главни букви запишете резултата в друг
временен файл. След това преименувайте новия файл
с името на оригиналния файл и изтрийте временното
име. Отпечатайте съдържанието на файл на
стандартния изход с главни букви.
*/


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(void){

    FILE *foriginal, *fcopy;

    foriginal = fopen("original14.txt", "w+");

    if(foriginal == NULL){
        perror("File not found");
        exit(1);
    }

    fputs("Nosete si novite drehi, momcheta", foriginal);

    fcopy = fopen("copy14.txt", "w+");

    if(fcopy == NULL){
        perror("File not found");
        exit(1);
    }

    char c;

    while ((c = fgetc(foriginal)) != EOF){
        fputc(toupper(c), fcopy);
    }
    
    fclose(foriginal);
    fclose(fcopy);

    remove("original14.txt");
    rename("copy14.txt", "original14.txt");
    remove("copy14.txt");

    fcopy = fopen("original14.txt", "r");

    while ((c = fgetc(fcopy)) != EOF){
        printf("%c", c);
    }
    
    fclose(fcopy);

    return 0;
}