//Задача 9. Напишете макрос, който прави идентификатор на низ (стринг)


#include <stdio.h>
#define STRING(x) #x

int main() {
    int number = 0;
    printf(STRING(number));
    printf("\n%d", number);
    
    return 0;
}
