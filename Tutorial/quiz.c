#include <stdio.h>
int main() {
    int i;
    scanf("%d", &i);
    int a[]= {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
    int*ip = a;
    i+=++*ip*3;
    printf("%d %d %d ", i, *(ip+(i/i==i--?3:2)), *ip--);
    printf("%d %d", i*i, *(ip+i));
    return 0;
}