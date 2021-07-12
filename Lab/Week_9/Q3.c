#include<stdio.h>
#include<stdlib.h>

typedef struct Complex_Number{
    double real,img;
} Complex_Number;

typedef struct sv_term{
    
    int pos;
    Complex_Number value;
    
} sv_term;

typedef struct Sparse_Vector{
    
    int  dim;  // Stores dimension
    int k;     // Number of non-zero sv_terms
    struct sv_term* arr; // of type Pointer to sv_term(to store the terms in the form of an array)
    
} Sparse_Vector;

typedef struct sm_term{
    
    int row, col;
    Complex_Number value;
    
} sm_term;

typedef struct Sparse_Matrix{
    
    int dim1,dim2;   // Stores the dimensions
    int k ;   // Number of non-zero sm_terms
    struct sm_term* arr; // of type Pointer to sm_term(to store the terms in the form of an array)
    
} Sparse_Matrix;

Sparse_Matrix outer_product(Sparse_Vector v1, Sparse_Vector v2){
    
    struct sm_term sm;
    struct Sparse_Matrix matrix;
    matrix.k = v1.k * v2.k;
    matrix.arr = (struct sm_term*)malloc(matrix.k*sizeof(struct sm_term));
    int z = 0;
    for (int i=0; i<v1.k; i++){ //for v1
        for(int j=0 ; j<v2.k; j++) { // for v2
            sm.row = v1.arr[i].pos;
            sm.col = v2.arr[j].pos;
            sm.value.real = v1.arr[i].value.real * v2.arr[j].value.real;
            sm.value.img = v1.arr[i].value.img * v2.arr[j].value.img;
            matrix.arr[z] = sm;
            z++;
        }
    }
    return matrix;
}



int main(){
    struct Sparse_Vector v1;
    struct Sparse_Vector v2;
    scanf("%d %d", &v1.dim, &v2.dim);
    scanf("%d", &v1.k );

    v1.arr = (struct sv_term*) malloc(v1.k*sizeof(struct sv_term));

    for (int i =0; i<v1.k ; i++) {
        scanf("%d %lf %lf", &v1.arr[i].pos, &v1.arr[i].value.real, &v1.arr[i].value.img );
    }

    scanf("%d", &v2.k );
    v2.arr = (struct sv_term*) malloc(v2.k*sizeof(struct sv_term));
    for (int i =0; i<v2.k ; i++) {
        scanf("%d %lf %lf", &v2.arr[i].pos, &v2.arr[i].value.real, &v2.arr[i].value.img );
    }

    int dim = v1.k * v2.k;

    printf("%d\n", dim);

    struct Sparse_Matrix ans = outer_product(v1, v2);
    for(int i =0; i< dim; i++){
        printf("%d %d %lf %lf", ans.arr[i].row, ans.arr[i].col, ans.arr[i].value.real, ans.arr[i].value.img  );
    }

    


    return 0;
}