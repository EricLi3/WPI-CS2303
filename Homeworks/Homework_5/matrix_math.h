struct matrix{ 
    int size; 
    float *data; 
};
typedef struct matrix Matrix;

/**
 * This function reads in an input file and allocates the array in the matrix struct
 * @param char* filename
 * @returns pointer to instance of a matrix struct 
*/
struct matrix* readMatrix(char* filename); 

/**
 * This function reads in a matrix struct and deletes the matrix. 
 * @param struct matrix *A
 * @returns nothing
*/
int deleteMatrix(struct matrix *A);

//addition of Matrices 
/**
 * This function takes in two input matrices, A and B, It expects them to have the same size (i.e., the same number of elements), 
 * so it can perform element-wise addition of the two matrices.
 * @param Matrix *A
 * @param Matrix *B
 * @returns pointer to new array which is the result of adding the two matrices
*/
Matrix* addition(Matrix *A, Matrix *B);

//subtraction of matrices
/**
 * This function takes in two input matrices, A and B, It expects them to have the same size (i.e., the same number of elements), 
 * so it can perform element-wise subtraction of the two matrices.
 * @param Matrix *A
 * @param Matrix *B
 * @returns pointer to new array which is the result of subtracting the two matrices
*/
Matrix* subtraction(Matrix *A, Matrix *B);