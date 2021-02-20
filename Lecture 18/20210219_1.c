/*
Задача 1. Дефиниране на структура, достъп до членове
#include <stdio.h>
#include <string.h>
struct tagPaper {
unsigned m_nBookId;
char m_szTitle[64];
char m_szAuthor[64];
char m_szSubject[256];
};
*/


#include <stdio.h>
#include <string.h>

typedef struct book
{
    char title[64];
    char author[64];
    char subject[64];

}book;


int main(void){

    book mefistofel  = {"Mefistofel", "Klaus Man", "Novel"};
    printf("Title: %s   Author: %s  Subject: %s \n", mefistofel.title, mefistofel.author, mefistofel.subject);

    book vendeta  = {"V for Vendeta", "Alan Moor", "Comics"};
    printf("Title: %s   Author: %s  Subject: %s \n", vendeta.title, vendeta.author, vendeta.subject);

    book sapiens  = {"Sapiens", "Harari", "Sience"};
    printf("Title: %s   Author: %s  Subject: %s \n", sapiens.title, sapiens.author, sapiens.subject);


    return 0;
}
