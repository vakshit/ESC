#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    //define the details of the structure
    int data;
    struct node* next;
}NODE;


void printList(NODE *);//function to print the solution
NODE* input();//Function to take input
NODE* solve(NODE**, int);//function to solve the problem, returns a single list with all buyers in descending order.
NODE* createNode(int n);


int main()
{   int n;
    scanf("%d", &n);
    NODE** lists;
    lists = (NODE **)malloc(n*sizeof(NODE*));
    for(int i=0; i<n; i++) lists[i] = input();

    printList(solve(lists, n));
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
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
    printf("\n");
}


NODE* SortedMerge(NODE* a, NODE* b)
{
    NODE* result = NULL;
 
    /* Base cases */
    if (a == NULL)
        return (b);
    else if(b == NULL)
        return (a);
 
    /* Pick either a or b, and recur */
    if(a->data >= b->data)
    {
        result = a;
        result->next = SortedMerge(a->next, b);
    }
    else
    {
        result = b;
        result->next = SortedMerge(a, b->next);
    }
 
    return result;
}

NODE* solve(NODE **arr, int n){
    // repeat until only one list is left
    // int last = n-1;
    // while (last != 0)
    // {
    //     int i = 0, j = last;
 
    //     // (i, j) forms a pair
    //     while (i < j)
    //     {
    //         // merge List i with List j and store
    //         // merged list in List i
    //         arr[i] = SortedMerge(arr[i], arr[j]);
 
    //         // consider next pair
    //         i++, j--;
 
    //         // If all pairs are merged, update last
    //         if (i >= j)
    //             last = j;
    //     }
    // }

    // while(arr[0]->next != NULL){
    //     arr[0] = arr[0]->next;
    // }
    // printf("%d", arr[0]->data);
    NODE* ptr = arr[0];
    for (int i = 0; i < n-1; i++)
    {
        // NODE* ptr = arr[0];

        // code to merge all the lists
        if (arr[i] == NULL) continue;
        while(arr[i]->next != NULL){
            arr[i] = arr[i]->next;
        }
        int j = i;
        if (arr[i+1] == NULL){
            while (arr[j+1] == NULL) j++;
            arr[i]->next = arr[j+1];
            i = j;
        }
        else arr[i]->next = arr[i+1];
            
    }

    
    //pasted code here



    return ptr;
}

void bubbleSort(struct Node *start)
{
    int swapped, i;
    struct Node *ptr1;
    struct Node *lptr = NULL;
  
    /* Checking for empty list */
    if (start == NULL)
        return;
  
    do
    {
        swapped = 0;
        ptr1 = start;
  
        while (ptr1->next != lptr)
        {
            if (ptr1->data > ptr1->next->data)
            { 
                swap(ptr1, ptr1->next);
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    }
    while (swapped);
}
  
/* function to swap data of two nodes a and b*/
void swap(struct Node *a, struct Node *b)
{
    int temp = a->data;
    a->data = b->data;
    b->data = temp;
}
