#include<stdio.h>
#include<stdlib.h>

int a[12][12];
int z=0;

struct path {
   int r;
   int c;
   struct path* next;
};

struct path * make(int r, int c, struct path * p){
    struct path * t = calloc(1,sizeof(struct path));
    t->r=r;
    t->c=c;
    p->next=t;
    return t;
}

void print (struct path * head){
    z=1;
    while(head->next!=NULL){
        printf("(%d,%d)->",head->r,head->c);
        head=head->next;
    }
    printf("(%d,%d)\n",head->r,head->c);
}

void fn(int i, int j, int m, int n, struct path * head, struct path * entry){
    if(i==m-1 && j==n-1){
        print(entry);
        return;
    }
    if(i<m-1 && j<n-1){
        if(a[i][j+1]==0){
            fn(i,j+1,m,n,make(i,j+1,head),entry);
        }
        if(a[i+1][j]==0){
            fn(i+1,j,m,n,make(i+1,j,head),entry);
        }
        if(a[i+1][j+1]==0){
            fn(i+1,j+1,m,n,make(i+1,j+1,head),entry);
        }
    }
    else if(i<m-1){
        if(a[i+1][j]==0){
            fn(i+1,j,m,n,make(i+1,j,head),entry);
        }
    }
    else if(j<n-1){
        if(a[i][j+1]==0){
            fn(i,j+1,m,n,make(i,j+1,head),entry);
        }
    }
    return;
}
 
int main()
{
    int m,n;
    scanf("%d %d\n",&m,&n);
    char ch;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            scanf("%c",&ch);
            a[i][j]=ch-'0';
        }
        scanf("\n");
    }
    struct path * entry = calloc(1,sizeof(struct path));
    entry->r=0;
    entry->c=0;
    fn(0,0,m,n,entry,entry);
    if(z==0){
        printf("NO ESCAPE");
    }
   return 0;
}