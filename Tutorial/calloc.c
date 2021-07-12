#include<stdio.h>
#include <stdlib.h>

int main() {

    int n = 5;
    int *a = (int*)malloc(n*sizeof(int));
    int *b = (int*)calloc(n, sizeof(int));

    for ( int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
    for ( int i = 0; i < n; i++)
    {
        printf("%d ", b[i]);
    }
	return 0;
}

