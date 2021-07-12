#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    //define the details of the structure
    int data;
    struct node* next;
}NODE;


void printList(NODE *);//function to print the solution
NODE* input();//Function to take input
NODE* solve(NODE*);//function to solve the problem
NODE* createNode(int n);
NODE* helper(NODE*);


int main()
{
    NODE* head;
    head=input();
    printList(solve(head));
    // solve(head);
    return 0;
}

/*Do not modify the main function
 *Define the structure NODE properly
 *Write the body of the above mentioned function*/
 
 
NODE* createNode(int dt){
    NODE* n=(NODE*)malloc(sizeof(NODE));
    n->data=dt;
    n->next=NULL;
    return n;
}//Function that creates and returns a pointer to a NODE


NODE* input(){
    NODE* head=NULL,*tail=NULL,*pt;
    int num;
    while(1){
        scanf("%d",&num);
        if(num==-1)
            return head;
        pt=createNode(num);
        if(head==NULL)
            head=tail=pt;
        else{
            tail->next=pt;
            tail=pt;
        }
    }
}


void printList(NODE* head){
    NODE* ptr=head;
    if(head==NULL)
        return;
    while(ptr!=NULL){
        printf("%d",ptr->data);
        ptr=ptr->next;
    }
    printf("\n");
}


NODE* solve(NODE *head){
    if(head==NULL)
        return NULL;
    return helper(head);
}


NODE* helper(NODE* A){
    int B=A->data;
    int i =B;
    int count =0;
    //printList(A);
    if(A==NULL)
        return A;
    NODE* pre=A,*ptr=A,*nptr=A->next;

    while(pre!=NULL) {
        count ++;
        pre = pre->next;
    }
    B = count -B -1;
    // printf("%d %d",count, B);

    while(nptr!=NULL&&B!=0){
        B--;
        ptr = ptr->next;
        nptr=nptr->next;
    }
    if(nptr==NULL)
        return A->next;
    // nptr=nptr->next;
    // ptr=ptr->next;
    // while(nptr!=NULL){
    //     nptr=nptr->next;
    //     ptr=ptr->next;
    //     pre=pre->next;
    // }
    // pre->next=(pre->next)->next;
    ptr->next = nptr->next;
    
    return A->next;
}