#include <stdio.h>
#include <stdlib.h>
#include "matrix_math.h"
/**
 * This function reads in an input file and allocates the array in the matrix struct
 * @param char* filename
 * @returns pointer to instance of a matrix struct 
*/
struct matrix* readMatrix(char* filename){
    FILE *f = fopen(filename, "r");
    if(f == NULL){
        printf("Error opening file\n");
        exit(1);
    }
    //get the size of the matrix
    int size;
    fscanf(f, "%d", &size);

    //Allocate memory for the matrix struct
    Matrix *A = malloc(sizeof(Matrix));
    A->size = size;
    A->data = malloc(size * sizeof(float));

    //read in data from the file
    for(int i = 0; i < size; i++){
        fscanf(f, "%f", &A->data[i]);
    }

    fclose(f);
    return A;
}

/**
 * This function reads in a matrix struct and deletes the matrix. 
 * @param struct matrix *A
 * @returns nothing
*/
int deleteMatrix(struct matrix *A){
    free(A->data);
    free(A);
    return 0;
}

//addition of Matrices 
/**
 * This function takes in two input matrices, A and B, It expects them to have the same size (i.e., the same number of elements), 
 * so it can perform element-wise addition of the two matrices.
 * @param Matrix *A
 * @param Matrix *B
 * @returns pointer to new array which is the result of adding the two matrices
*/
Matrix* addition(Matrix *A, Matrix *B){
    if(A->size != B->size){
        printf("This math cannot be performed.\n");
        exit(1);
    }

    Matrix *result = malloc(sizeof(Matrix));
    result->size = A->size;
    result->data = malloc(A->size * sizeof(float));

    for(int i = 0; i < A->size; i++){
        result->data[i] = A->data[i] + B->data[i];// loops thorough the data elements and stores in result the addition of matrices A and B. 
    }
    return result;
}

//subtraction of matrices
/**
 * This function takes in two input matrices, A and B, It expects them to have the same size (i.e., the same number of elements), 
 * so it can perform element-wise subtraction of the two matrices.
 * @param Matrix *A
 * @param Matrix *B
 * @returns pointer to new array which is the result of subtracting the two matrices
*/
Matrix* subtraction(Matrix *A, Matrix *B){
    if(A->size != B->size){
        printf("This math cannot be performed.\n");
        exit(1);
    }

    Matrix *result = malloc(sizeof(Matrix));
    result->size = A->size;
    result->data = malloc(A->size * sizeof(float));

    for(int i = 0; i < A->size; i++){ // loops thorough the data elements and stores in result the subtraction of matrices A and B. 
        result->data[i] = A->data[i] - B->data[i];
    }
    return result;
}