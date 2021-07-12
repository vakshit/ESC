#include<stdio.h>
#include<stdlib.h>
 
int flag = 0;
struct path {
   int r;
   int c;
   struct path* next;
};

struct path* createNode(int x, int y){
    struct path *n=(struct path*)calloc(1, sizeof(struct path));
    n->r=x;
    n->c = y;
    n->next=NULL;
    return n;
}//Function that creates and returns a pointer to a NODE
 
void printList(struct path* head){
    struct path* ptr=head;
    if(head==NULL)
        return;
    while(ptr!=NULL){
        if(ptr!=head)
            printf("->");
        printf("(%d,%d)",ptr->r, ptr->c);
        ptr=ptr->next;
    }
    printf("\n");
}//Fuction used to print the linked list


void printAllPathsUtil(int *mat, int i, int j, int m, int n, int *path, int pi , struct path* ptr, struct path* pri_head){
    
    struct path* head = ptr, *tail = NULL, *pt, *pri;
    struct path* end;
    // Reached the bottom of the matrix so we are left with
    // only option to move right
    if (i == m - 1)
    {
        // struct path* head = NULL, *tail = NULL, *pt;
        flag = 1;
        for (int k = j; k < n; k++){
            path[pi + k - j] = i+k;
            pt=createNode(i, k);
            if(head==NULL)
                head=tail=pt;
            else{
                tail->next=pt;
                tail=pt;
                end = tail;
            }
        }
        // for (int l = 0; l < pi + n - j; l++)
        //     printf("%d->",path[l]);
        // printf("\n");
        pri_head->next = head;
        printList(pri_head);
        return;
    }

    // Reached the right corner of the matrix we are left with
    // only the downward movement.
    if (j == n - 1)
    {
        // struct path* head = NULL, *tail = NULL, *pt;
        flag = 1;
        for (int k = i; k < m; k++){
            // path[pi + k - i] = k+j;
            pt=createNode(k, j);
            if(head==NULL)
                head=tail=pt;
            else{
                tail->next=pt;
                tail=pt;
            }
    }
        // if (*((mat + (i+1)*n) + j) == 0)
        //     printAllPathsUtil(mat, i+1, j, m, n, path, pi + 1, tail->nex);
        // for (int l = 0; l < pi + m - i; l++)
        //     printf("%d->",path[l]);
        // printf("\n");
        pri_head->next = head;
        printList(pri_head);
        return;
    }
 
    // Add the current cell to the path being generated
    // path[pi] = i+j;
    
    // struct path*pt;
    pt=createNode(i, j);
    if(head==NULL)
        pri_head = head=tail=pt;
    else{
        tail->next=pt;
        tail=pt;
    }

    

    // Print all the paths that are possible after moving right
    if (*((mat + i*n) + (j+1)) == 0)
        printAllPathsUtil(mat, i, j+1, m, n, path, pi + 1, tail->next, pri_head);
 
    // Print all the paths that are possible after moving down
    if (*((mat + (i+1)*n) + j) == 0)
        printAllPathsUtil(mat, i+1, j, m, n, path, pi + 1, tail->next, pri_head);
 
    // Print all the paths that are possible after moving diagonal
    if (*((mat + (i+1)*n) + (j+1)) == 0)
        printAllPathsUtil(mat, i+1, j+1, m, n, path, pi + 1, tail->next, pri_head);
}

void printAllPaths(int *mat, int m, int n)
{
    int *path = (int*)malloc((m+n)*sizeof(int));
    struct path* head = NULL, *tail = NULL;
    printAllPathsUtil(mat, 0, 0, m, n, path, 0, head, tail);
}

int main()
{
//   int mat[3][3] = { {0, 1, 1}, {0, 0, 1}, {0, 0, 0} };
    int n, m;
    scanf("%d %d\n", &m, &n);
    char mat[m][n];
    int matint[m][n];
    for (int i=0; i< m; i++) {
        for (int j =0; j< n; j++) {
            scanf("%c", &mat[i][j]);\
            matint[i][j] = (int)(mat[i][j] - '0');
        }
        scanf("\n");
    }
    
    printAllPaths(*matint, m, n);
    if (flag == 0) {
        printf("NO ESCAPE");
    }
    return 0;
}