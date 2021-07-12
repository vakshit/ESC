#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    //define the details of the structure
    int data;
    struct node* next;
}NODE;


NODE* createNode(char dt){
    NODE* n=(NODE*)calloc(1, sizeof(NODE));
    n->data=dt;
    n->next=NULL;
    return n;
}//Function that creates and returns a pointer to a NODE


NODE* input(int n){
    NODE* head=NULL,*tail=NULL,*pt;
    int num;
    for (int i=0; i<n; i++){
        scanf("%d",&num);
        pt=createNode(num);
        if(head==NULL)
            head=tail=pt;
        else{
            tail->next=pt;
            tail=pt;
        }
    }
    return head;
}


void printList(NODE* head){
    NODE* ptr=head;
    if(head==NULL)
        return;
    while(ptr!=NULL){
        if(ptr!=head)
            printf("->");
        printf("%d",ptr->data);
        ptr=ptr->next;
    }
    printf("\n");
}//Fuction used to print the linked list

static void reverse(NODE** head_ref) {

    NODE* prev   = NULL;
    NODE* current = *head_ref;
    NODE* next;
    while (current != NULL)
    {
        next  = current->next;  
        current->next = prev;   
        prev = current;
        current = next;
    }
    *head_ref = prev;
}

NODE*copy(NODE*start1, int a, int b) {

    while(a!=1){
        start1 = start1->next;
        a--;
        b--;
    } 
    NODE* head=NULL,*tail=NULL,*pt;
    int num;
    for (int i=0; i<b; i++){
        // scanf("%d",&num);
        pt=createNode(start1->data);
        start1 = start1->next;
        if(head==NULL)
            head=tail=pt;
        else{
            tail->next=pt;
            tail=pt;
        }
    }
    reverse(&head);
    return head;
}

int main(){
    NODE* head=NULL;
    NODE* tail=NULL;
    int n, a, b;
    scanf("%d %d %d",&n, &a, &b);
    head=input(n);
    NODE* head_copy = head, *ptr = head;
    NODE* sub = copy(head, a ,b);
    if (a ==1 && b ==1 ) printList(ptr);
    else {
        for (int i = 0; i<b; i++){
        head_copy = head_copy->next;
    }
    // printList(head_copy);

    for (int i = 1; i<a-1; i++){
        head = head->next;
    }
    // printList(head);

    head ->next = sub;
    head = head->next;

    // printList(head);

    for (int i = 0; i<b-a; i++){
        // head = sub->next;
        head = head->next;
        // printList(head);
    }
    head->next = head_copy;
    if (a == 1) ptr = ptr->next;
    printList(ptr);
    }
    
    return 0;
}

