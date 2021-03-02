/*
Задача 7. Напишете масив от структури наречен kaytab[ ], като
използвате тази, дефинирана в горното упражнение - потребителски тип
key_t, която съдържа символен низ и число. Инициализирайте масива с
всички ключови думи на С.
*/

#include <stdio.h>
typedef struct {char *str; int num;} key_t;
typedef key_t keytab;
int main(){
    keytab a[32]={{"auto",0}, 
    {"break",1}, 
    {"case",2},
    {"char",3},
    {"continue",4}, 
    {"do", 5},
    {"default",6}, 
    {"const", 7},
    {"double", 8},
    {"else",9} ,
    {"enum", 10},
    {"extern", 11},
    {"for", 12},
    {"if", 13},
    {"goto", 14},
    {"float", 15},
    {"int", 16},
    {"long", 17},
    {"register", 18},
    {"return", 19},
    {"signed", 20},
    {"static", 21},
    {"sizeof", 22},
    {"short", 23},
    {"struct", 24},
    {"switch", 25},
    {"typedef", 26},
    {"union", 27},
    {"void", 28},
    {"while", 29},
    {"volatile", 30},
    {"unsigned",31}};
    for(int i=0; i<32; i++){
        printf("%d %s\n",a[i].num,a[i].str);
    }
    return 0;
}