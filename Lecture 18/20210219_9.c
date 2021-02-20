/* Направете функця add(), която събира две точки.
*/
#include <stdio.h>
#include <stdlib.h>
struct point
{
    int x;
    int y;
};
struct point add(struct point a, struct point b)
{
    struct point c = {a.x + b.x, a.y + b.y};
    return c;
}

int main(int argc, char *argv[])
{
    struct point a = {10, 17};
    struct point b = {32, 11};
    struct point c = add(a, b);
    printf("The coordinates of C: x=%d, y=%d", c.x, c.y);

    return 0;
}
