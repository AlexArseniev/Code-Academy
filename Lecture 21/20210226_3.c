/*
Задача 3. Дефинирайте потребителски тип към
указател.Създайте променлива, насочете указателя
към нея, използвайки новия потребителски тип.
*/

#include <stdio.h>
typedef int Type;
typedef int * nType;
int main(){
    printf("size of Type: %d\n",sizeof(Type));
    Type a=1000;
    nType
 p=&a;
    printf("%d\n",*p);
    return 0;
}