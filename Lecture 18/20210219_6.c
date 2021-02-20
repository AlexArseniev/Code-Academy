// Задача 6. Направете по подобен начин триъгълник:

#include <stdio.h>
#include <stdlib.h>

struct triangle{
    int x;
    int y;
};

int main(void){

    char board[15][15];

    for(int i = 0; i < 15; i++){
        for(int j = 0; j < 15; j++){
            board[i][j] = '-';
        }
    }

    struct triangle  a = {3, 4};
    struct triangle  b = {7, 10};


    for(int i = a.x; i <= b.y; i++){
        for(int j = i; j<= b.y; j++){
            board[i][j] = '@';
        }
    }

   for(int i = 0; i < 15; i++){
    for(int j = 0; j < 15; j++){
        printf("%c", board[i][j]);
    }
    printf("\n");
}
    


    return 0;
}
