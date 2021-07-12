#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[])
{
    if (argc <4) {
        printf("Invalid input\n");
        return 0;
    }

    float a, b;
    char operator, num[100];
    // scanf("%f %f\n", &a, &b);
    // scanf("%c", &operator);
    a = atof(argv[1]);
    b = atof(argv[2]);
    operator = *(argv[3]);
    printf("%d\n", argc);
    if (operator == '+')
        printf("%.2f\n", a+b);
    else if (operator == '*')
        printf("%.2f\n", a*b);
    else if (operator == '-')
        printf("%.2f\n", a-b);
    else if (operator == '/')
        printf("%.2f\n", a/b);
    return 0;
}