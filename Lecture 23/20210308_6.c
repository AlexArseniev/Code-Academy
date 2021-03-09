/*
Отворете и прочетете съдържанието от файл с fscanf.
int fscanf(FILE *stream, const char *format,....)
Има същите формати, както scanf.
Първият аргумент е пойнтер към файла, от който ще четем.
Вторият аргумент е формата- Стрингът може да има следните параметриспейс, неспейс, спецификатори;
*/
#include <stdio.h>
#include <stdlib.h>

int main () {
   char str1[20];
   char str2[20];

   FILE *pf = NULL;

   pf = fopen("hello.txt", "w+");
   
   if(pf == NULL) {
      perror("File not found");
      exit(1);
   }

   fputs("Hello World!", pf);

   rewind(pf);

   fscanf(pf, "%s %s", str1, str2);

   printf("String one = %s\n", str1);
   printf("String two = %s\n", str2);


   fclose(pf);
   
   return(0);
}