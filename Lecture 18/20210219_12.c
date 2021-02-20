#include <stdio.h>
#include <math.h>

struct point{
    int x;
    int y;
};

double distance(struct point a, struct point b){
    double distance;
    distance = sqrt(((b.x - a.x) * (b.x - a.x)) + ((b.y - a.y) * (b.y - a.y)));
    return distance;
}

int main(void){
    int xA, yA, xB, yB;

    printf("Enter coordinates for point 'a'");
    printf("\nX a = ");
    scanf(" %d", &xA);
    printf("Y a = ");
    scanf(" %d", &yA);

    printf("\nEnter coordinates for point 'b'");
    printf("\nX b = ");
    scanf(" %d", &xB);
    printf("Y b = ");
    scanf(" %d", &yB);

    struct point a = {xA, yA};
    struct point b = {xB, yB};

    double result = distance(a, b);

    printf("\nThe distance between a(%d,%d) and b(%d,%d) is %f\n\n", a.x, a.y, b.x, b.y, result);

    return 0;
}
