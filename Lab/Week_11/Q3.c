#include <stdio.h>
#include <string.h>

int flag = 0;
int matint[12][12];
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

void recurse (int i, int j, int m, int n){
    if ( i == n-1) { // when reached the right end
        for (int k =j ; k <m ; k++ ){
            if (matint[k] == 1) return;
        }
        
    }
}

int main() {
    int n, m;
    scanf("%d %d\n", &m, &n);
    char mat[m][n];
    // int matint[m][n];
    for (int i=0; i< m; i++) {
        for (int j =0; j< n; j++) {
            scanf("%c", &mat[i][j]);
            matint[i][j] = (int)(mat[i][j] - '0');
        }
        scanf("\n");
    }


}