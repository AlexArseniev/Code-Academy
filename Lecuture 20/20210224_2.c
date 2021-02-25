/*
Напишете макрос swap(t, x, y), койтo променя местата на двата аргумента
от тип t.
*/

#include <stdio.h>
#define swap(t,x,y){t z; z = x; x = y; y = z;}


int main(void){

    char a,b;
    a = 'a';
    b = 'b';

    printf("The characters before the swap a = %c,  b = %c\n", a,b);
    
    swap(char,a,b);

    printf("The characters after the swap: a = %c, b = %c", a,b);

    return 0;
}
