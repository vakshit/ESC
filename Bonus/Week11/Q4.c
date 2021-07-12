#include <stdio.h>
#include <string.h>
#include<stdlib.h>

int check (char s1[], char s2[], int n1, int n2) {
    int flag = 0, count = 0;
    if (n1 >= n2) {
        char *temp = (char*)malloc(strlen(s2)*sizeof(char));
        for(int i = 0; i < n2; i++) {
            strncpy(s2, temp, n2-i);
            if (strstr(s1, temp)) {
                count = i;
                flag = 1;
                break;
            }
        }
        if (flag == 1) return n1 - n2 + count;
        else return n2;
    }

    else {
        // char *temp = s1;
        char *temp = (char*)malloc(strlen(s1)*sizeof(char));
        for(int i = 0; i < n1; i++) {
            strncpy(s1, temp, n1-i);
            if (strstr(s2, temp)) {
                count = i;
                flag = 1;
                break;
            }
        }
        if (flag == 1) return n2 - n1 + count;
        else return n1;
    }
}

int main()
{
    //Fill this area with your code.
    
    int n1, n2;
    scanf("%d %d\n", &n1, &n2);
    char s1[n1], s2[n2];
    gets(s1);
    gets(s2);
    
    printf("%d", check(s1, s2, n1, n2));
    
    return 0;
}