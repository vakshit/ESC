#include<stdio.h>

struct point {
    int x;
    int y;
};
struct point make_point(int x, int y) {
    struct point temp;
    temp.x = x;
    temp.y = y;
    return temp;
}


struct rectangle {
    char label;
    struct point top_left;
    struct point bottom_right;
};

int intersect (struct rectangle rect1, struct rectangle rect2 ) {
    if (rect1.top_left.x > rect2.bottom_right.x || rect2.top_left.x > rect1.bottom_right.x )
    return 0;
    if (rect1.top_left.y < rect2.bottom_right.y || rect2.top_left.y < rect1.bottom_right.y )
    return 0;

    return 1;
}

int main()
{
    char label = 'a';
    int x1,y1, x2, y2;
    int n;
    scanf("%d\n", &n);
    struct rectangle arr[n], temp;

    for (int i=0; i<n; i++, label++){
        scanf("%d %d %d %d\n", &x1,&y1, &x2, &y2 );
        temp.label = label;
        temp.top_left = make_point(x1, y1);
        temp.bottom_right = make_point(x2, y2);
        arr[i] = temp;
    }

    for (int i=0; i<n ; i++) {
        for (int j = i+1; j< n ; j++) {
            if (intersect (arr[i], arr[j]))
            printf ("%c,%c\n", arr[i].label, arr[j].label);
        }
    }
    
    return 0;
}