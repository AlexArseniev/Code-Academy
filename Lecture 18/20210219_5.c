/*Задача 5. а) Направете поле 15 на 15, като принтирате тирета в конзолата.
b) Направете точка а(3, 4), като на това място принтирате @
c) Направете точка b(7, 10), като на това място принтирате @
d) Попълнете правоъгълника с @
*/

#include <stdio.h>

struct coordinates {
    int x;
    int y;
};

int main(void){

char board[15][15];
struct coordinates a = {3, 4};
struct coordinates b = {7, 10};

printf("PODTOCHKA A\n");
for(int i = 0; i < 15; i++){
    for(int j = 0; j < 15; j++){
        board[i][j] = '-';
        printf("%c", board[i][j]);
    }
    printf("\n");
}

printf("PODTOCHKA B\n");
board[a.x][a.y] = '@';
for(int i = 0; i < 15; i++){
    for(int j = 0; j < 15; j++){
        printf("%c", board[i][j]);
    }
    printf("\n");
}

printf("PODTOCHKA C\n");
board[b.x][b.y] = '@';
for(int i = 0; i < 15; i++){
    for(int j = 0; j < 15; j++){
        printf("%c", board[i][j]);
    }
    printf("\n");
}

printf("PODTOCHKA D\n");

for(int i = a.x; i <= b.x; i++){
    for(int j = a.y; j <= b.y; j++){
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

