#include<stdio.h>
#include<stdlib.h>
 
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

void recurse(int *mat, int i, int j, int m, int n, int *pathx, int* pathy, int pi )
{
    // only option to move right
    if (i == m - 1)
    {
        // struct path* head = NULL, *tail = NULL, *pt;
        for (int k = j; k < n; k++){
            pathx[pi + k - j] = i;
            pathy[pi + k - j] = k;
            // pt=createNode(i, k);
            // if(head==NULL)
            //     head=tail=pt;
            // else{
            //     tail->next=pt;
            //     tail=pt;
            //     end = tail;
            // }
        }
        for (int l = 0; l < pi + n - j-1; l++)
            printf("(%d,%d)->",pathx[l], pathy[l]);
        printf("(%d,%d)",pathx[pi + n - j-1], pathy[pi + n - j-1]);
        printf("\n");
        // printList(pri_head);
        return;
    }

    // Reached the right corner of the matrix we are left with
    // only the downward movement.
    if (j == n - 1)
    {
        // struct path* head = NULL, *tail = NULL, *pt;
        for (int k = i; k < m; k++){
            pathx[pi + k - i] = k;
            pathy[pi + k - i] = j;
        }
            // pt=createNode(k, j);
            // if(head==NULL)
            //     head=tail=pt;
            // else{
            //     tail->next=pt;
            //     tail=pt;
            // }
        for (int l = 0; l < pi + m - i-1; l++)
            printf("(%d,%d)->",pathx[l], pathy[l]);
        printf("(%d,%d)",pathx[pi + m - i-1], pathy[pi + n - j-1]);
        printf("\n");
        // printList(pri_head);
        return;
    }
 
    // Add the current cell to the path being generated
    pathx[pi] = i;
    pathy[pi] = j;
    
    // // struct path*pt;
    // pt=createNode(i, j);
    // if(head==NULL)
    //     pri_head = head=tail=pt;
    // else{
    //     tail->next=pt;
    //     tail=pt;
    // }

    
    // if (*((mat + i*n) + (j+1)) == 1 && *((mat + (i+1)*n) + j) == 0 && *((mat + (i+1)*n) + (j+1)) == 0){
    //     printf("NO ESCAPE");
    //     return;
    // }
    // Print all the paths that are possible after moving right
    if (*((mat + i*n) + (j+1)) == 0)
        recurse(mat, i, j+1, m, n, pathx, pathy, pi + 1);
 
    // Print all the paths that are possible after moving down
    if (*((mat + (i+1)*n) + j) == 0)
        recurse(mat, i+1, j, m, n, pathx, pathy, pi + 1);
 
    // Print all the paths that are possible after moving diagonal
    if (*((mat + (i+1)*n) + (j+1)) == 0)
        recurse(mat, i+1, j+1, m, n, pathx, pathy, pi + 1);
        
    
}

void printAllPaths(int *mat, int m, int n)
{
    int *pathx = (int*)malloc((m+n)*sizeof(int));
    int *pathy = (int*)malloc((m+n)*sizeof(int));
    recurse(mat, 0, 0, m, n, pathx, pathy, 0);
}

int main()
{

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
    
    // for (int i=0; i< m; i++) {
    //     for (int j =0; j< n; j++){
    //         printf("%d ", matint[i][j]);
    //     }
    //     printf("\n");
    // }
    printAllPaths(*matint, m, n);
    return 0;
}