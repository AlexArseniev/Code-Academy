/*
Създайте test.txt файл в избрана от вас директория. Сложете
някакви данни в него на латиница- име, поздрав, брой. Отворете
файла за редактиране. Внимавайте за мястото, къде поставяте
файла. Трябва да е там, където е сорс файлът.
*/

#include <stdio.h>
#include <stdlib.h>

int main(void){

    FILE *pfile = fopen("myfile.txt", "w");

    if(pfile == NULL){
        printf("Failed to open the file");
        exit(1);
    }

    fprintf(pfile, "Hello World!");

    if(rename("myfile.txt", "renamed_myfile.txt"))
        printf("Flie renamed");
    else
        printf("Failed to rename");

    fclose(pfile);
    remove("renamed_myfile.txt");
    
    return 0; 
}