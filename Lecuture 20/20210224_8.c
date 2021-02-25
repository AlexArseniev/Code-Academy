/*
Задача 8. Напишете макрос, който свързва два идентификатора в
един общ (конкатениране на идентификатори)
*/

#include <stdio.h>
#define MY_CONCAT(x,y) x##y


int main(void) {
    
    MY_CONCAT(print,f)("\nThis is a test\n");
    MY_CONCAT(pr,intf)("CODEACADEMY");
    
    return 0;
}
