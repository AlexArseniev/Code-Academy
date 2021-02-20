/*
Задача 7. Направете функция struct point makepoint(int x, int y), която
създава две точки.
*/

#include <stdio.h>

struct point
{
    int x;
    int y;
};

struct point makepoint(int x, int y){
    struct point point = {x,y};
    return point;
}


int main(void){
    int ca,cb,cc,cd;
    printf("Give coordinates for the first point:\n");
    scanf("%d", &ca);
    scanf("%d", &cb);
    printf("Give coordinates for the second point:\n");
    scanf("%d", &cc);
    scanf("%d", &cd);

    struct point a = makepoint(ca, cb);
    struct point b = makepoint(cc, cd);
    printf("The coordinates of point A: x=%d , y=%d\n", a.x, a.y);
    printf("The coordinates of point B: x=%d , y=%d", b.x, b.y);


    return 0;
}
