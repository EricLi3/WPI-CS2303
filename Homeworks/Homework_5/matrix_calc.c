#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "matrix_math.h"

struct matrix* readMatrix(char* filename); 
int deleteMatrix(struct matrix *A); 

int main(int argc, char *argv[]){

    //add line to handle the case where an incorrect number of inputs are entered
    if(argc != 4){
        printf("Incorrect amount of argunments. \n");
        return(1);
    }

    Matrix *A = readMatrix(argv[1]);
    Matrix *B = readMatrix(argv[2]);

    Matrix *result;

    if (strcmp(argv[3], "a") == 0){
        result = addition(A, B);
    }
    else if (strcmp(argv[3], "s") == 0){
        result = subtraction(A, B);
    }
    else{
        printf("Invalid Type.\n");
        return 1;
    }

    if (result == NULL) {
        printf("This math cannot be performed.\n");
        return 1;
    }

    for (int i = 0; i < result->size; i++) {
        printf("%.2f ", result->data[i]);
    }
    printf("\n");

    //freeing the memory on the heap since we are done with the work on the matrices. 
    deleteMatrix(A);
    deleteMatrix(B);
}