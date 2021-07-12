#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node * next;
}NODE;

void printList(NODE *);//function to print the solution
NODE* input();//Function to take input
NODE* solve(NODE*);//function to solve the problem
//define any function prototype you want to use
NODE* createNode(int);    

int main(){
    NODE* head=input();
    printList(solve(head));
    return 0;
}//DO NOT modify the main function or ANY OTHER function in the templete


NODE* solve(NODE* A){
    if(A==NULL||A->next==NULL)
        return A;
    NODE* curr=A,*agla=A->next,*root=createNode(-1),*ans=root;
    int flag;
    while(agla!=NULL){
        flag=0;
        if(curr->data==agla->data){
            while(agla!=NULL&&curr->data==agla->data){
                curr=agla;
                agla=agla->next;
            }
            flag=1;
        }
        else{
            ans->next=curr;
            ans=ans->next;
        }
        curr=agla;
        if(agla)
            agla=agla->next;
        if(flag==1&&agla==NULL){
            ans->next=curr;
            ans=ans->next;
        }
    }
    //if(root->next!=NULL)
        return root->next;
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


NODE* createNode(int dt){
    NODE* n=(NODE*)calloc(1, sizeof(NODE));
    n->data=dt;
    n->next=NULL;
    return n;
}//Function that creates and returns a pointer to a NODE


NODE* input(){
    NODE* head=NULL,*tail=NULL,*pt;
    int num,n =6;
    // scanf("%d",&n);
    int arr[6] = {1, 2, 3, 3, 4, 4};
    for(int i=0;i<n;i++){
        // scanf("%d",&num);
        // num = arr[i];
        pt=createNode(arr[i]);
        if(head==NULL)
            head=tail=pt;
        else{
            tail->next=pt;
            tail=pt;
        }
    }
    return head;
}//function that takes in the input in the form of a linked list and returns the head
