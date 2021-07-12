#include<stdio.h>
#include <stdlib.h>

typedef struct node{
    char data;
    struct node * next;
}NODE;

NODE* createNode(char dt){
    NODE* n=(NODE*)calloc(1, sizeof(NODE));
    n->data=dt;
    n->next=NULL;
    return n;
}//Function that creates and returns a pointer to a NODE


NODE* input(int n){
    NODE* head=NULL,*tail=NULL,*pt;
    char val;
    for(int i=0;i<n;i++){
        scanf("%c ",&val);
        pt=createNode(val);
        if(head==NULL)
            head=tail=pt;
        else{
            tail->next=pt;
            tail=pt;
        }
    }
    return head;
}//function that takes in the input in the form of a linked list and returns the head

void solve(NODE* A, int n, char key){
    char data;
    if (n == 0) printf("Not Exists");
    int count = 0;
    while(A != NULL){
        data = A->data;
        if (data == key){
            while (A != NULL) {
                if (A->data == key) count =0;
                count ++;
                A = A->next;
            }
        }
        else A = A->next;
    }
    printf("%d", count-1);
}

int main()
{
    //  Write your code here.
    int num;
    char c;
    scanf("%d %c\n",&num, &c);
    
    NODE* head=input(num);
    solve(head, num, c);
    return 0;
}