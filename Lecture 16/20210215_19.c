/*
Задача 19. Дефинирайте стринг: „Baba, kaka, mama” заменете „а“
със „о“
*/

#include <string.h>
#include <stdio.h>


int main(void){

    char string[] = "Baba, kaka, mama";
    char* p = &string;
    int size = strlen(string);
    int i = 0;

    for(i; i < size; i++){
        if(*p == 'a'){
            *p = 'o';
        }
        p++;
    }

    printf("%s", string);

    return 0;
}
