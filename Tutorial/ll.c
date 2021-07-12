#include <stdio.h>
typedef struct node{
    int val;
    struct node* prev;
    struct node* next;
}NODE;
NODE* create_node(int value){
    NODE* curr=(NODE*)malloc(sizeof(NODE));
    curr->val=value;
    curr->prev=NULL;
    curr->next=NULL;
    return curr;
}
void reverse(NODE** head){
    NODE* curr=*head;
    if(curr==NULL || curr->next==NULL) return;
    NODE* nxt=curr->next;
    while(nxt!=NULL){
        NODE* tmp=nxt->next;
        nxt->next=curr;
        nxt->prev=tmp;
        curr=nxt;
        nxt=tmp;
    }
    
}
int main(){
    NODE* head=NULL;
    NODE* tail=NULL;
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int v;
        scanf("%d",&v);
        NODE* curr= create_node(v);
        /* inserrt in start
        curr-> next=head;
        head=curr;
        if(tail==NULL) tail=head;*/
        if(tail==NULL){
            tail=head=curr;
        }
        else{
            tail->next=curr;
            curr->prev=tail;
            tail=curr;
        }
    }
    reverse(&head);
}
// 1 -> NULL
// 2 -> 1 -> NULL
// 3 -> 2 -> 1 -> NULL


// 1 -> NULL
// 1 -> 2 ->NULL
// 1 -> 2 ->3 ->NULL