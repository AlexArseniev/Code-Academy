/*
Направете обединение с членове unsigned short и char. Ограничете
използваните битове до 6. Инициализирайте и изведете на
конзолата
*/


#include <stdio.h>

union tagUnion{
    unsigned short int intField: 6;
    char charField: 6;
};

int main(void){
    union tagUnion variable = {7, 'c'};

    printf("Size of sctuct: %d", sizeof(variable));
    printf("\nInteger: %u\nChar: %c", variable.intField, variable.charField);

    return 0;
}
