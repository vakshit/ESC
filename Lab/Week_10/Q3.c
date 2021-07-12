#include <stdio.h>
#include <malloc.h>

typedef struct ListNode {
     char val;
     struct ListNode *next;
}Node;


int isPalindrome(Node *head);
Node* take_input(int n);

// Do not change anything above this line

Node* createNode(char dt){
    Node* n=(Node*)calloc(1, sizeof(Node));
    n->val=dt;
    n->next=NULL;
    return n;
}//Function that creates and returns a pointer to a NODE

int isPalindrome(Node *head) {
    // write code here   
    Node* count = head, *ptr1= head, *ptr2 = head;
    int len = 0;
    if(head == NULL) return 0;

    while (count != NULL) {
        len++;
        count = count->next;
    }
    int i =1, j= 0, temp =0;
    while(i<len/2){
        temp = 0;
        while(temp != len -i ){
            ptr2 = ptr2->next;
            temp ++;
        }
        if (ptr1->val + ptr2->val != 'a' + 'z') return 0;
        ptr2 = head;
        ptr1 = ptr1->next;
        i++;
    }
    return 1;
}

Node* take_input(int n){
	// Write code to take input here, do not change the return type.
	Node* head=NULL,*tail=NULL,*pt;
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
}

// Do not change anything below this line

int main(){
	int n;
	scanf("%d\n",&n);
	Node* head=take_input(n);
	if(isPalindrome(head)) printf("Special String\n");
	else printf("Not a special string\n");

}