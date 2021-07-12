#include<stdio.h>
#include<stdlib.h>

int len (char str[]) {
    int i=0, count =0;
    while (str[i] != '\0') {
        // count++;
        i++;
    }

    return i;
}


int main()
{
    //  Insert your code here.
    char cipher[100], str[15], out[200];
    FILE *test = fopen("Q3test.txt", "r");
    int i=0;
    while (!feof(test)){
        fscanf(test, "%c", &out[i]);
        // printf("%c ", out[i]);
        if (i<26) str[i] = out[i];
        else if (i>26) cipher[i-27] = out[i];
        i++;
    }
    puts(str);
    // puts(cipher);
    printf("%d\n", len(str));
    
    for(int i=0; i<len(cipher); i++) {
        cipher[i] = str[cipher[i] - 'a'];
    }

    puts(cipher);

    fclose(test);   
    return 0;
}

