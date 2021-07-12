#include <stdio.h>
#include<math.h>

struct point {
    int x;
    int y;
};

struct triangle{
    struct point p1;
    struct point p2;
    struct point p3;
};

float area_triangle(struct triangle t)
{
   return abs((t.p1.x*(t.p2.y-t.p3.y) + t.p2.x*(t.p3.y-t.p1.y)+ t.p3.x*(t.p1.y-t.p2.y))/2.0);
}

float area_subtrianlge(struct triangle t, struct point p) {
    float area = 0;
    area += abs((p.x*(t.p2.y-t.p3.y) + t.p2.x*(t.p3.y-p.y)+ t.p3.x*(p.y-t.p2.y))/2.0);
    area += abs((t.p1.x*(p.y-t.p3.y) + p.x*(t.p3.y-t.p1.y)+ t.p3.x*(t.p1.y-p.y))/2.0);
    area += abs((t.p1.x*(t.p2.y-p.y) + t.p2.x*(p.y-t.p1.y)+ p.x*(t.p1.y-t.p2.y))/2.0);
    return area;
}

int main() {
    
    struct triangle t;
    struct point p;
    float x, y;
    scanf("%f %f", &p.x, &t.p1.y );
    scanf("%f %f", &t.p2.x, &t.p2.y );
    scanf("%f %f", &t.p3.x, &t.p3.y );
    scanf("%f %f", &p.x, &p.y);

    if (area_triangle(t) - area_subtrianlge(t, p) <=0.0001) printf("INSIDE");
    else printf("OUTSIDE");


    return 0;
}

