#include <iostream>
#include <string>
#include <iomanip>

#include "Matrix.h"

Matrix::Matrix(int l1){
    length = l1;
    data = new float[length];
    
}


Matrix::Matrix(){
    length = 0;
    data = NULL;
    
}



void Matrix::readMatrix(string fileName) {
    ifstream input;
    input.open(fileName);
    
    for (int i = 0; i < length; i++){
        input >> data[i];
    }
    input.close();
}




/*******************************************************************************
* void print(Matrix& A){
*
* Output:
*   Prints A to the screen
********************************************************************************/

void Matrix::print(){

   // print values to screen
    for (int i = 0; i < length; i++){
       cout << std::setw(8) << data[i];  
    }
    printf("\n");

}

/**
 * Matrix + operator overload
 * Input: reference to matrix m so we can asccess members and its efficent
 * Output: returns a new matrix with the sum of the input matrix and the matrix that this function is being called on
 */

Matrix Matrix::operator+(Matrix &m) {
    Matrix out(this->length); // need to use the -> operator because we have a reference to a matrix object

    for (int i = 0; i < this->length; i++) {
        out.data[i] = this->data[i] + m.data[i]; // once again to use/asccess the data use -> operator.  
    }

    return out;
}
/*
//Another way to do this is to pass the whole object which is less efficient. 
Matrix Matrix::operator+(Matrix m) {
    Matrix out(length);

    for (int i = 0; i < length; i++) {
        out.data[i] = data[i] + m.data[i];
    }

    return out;
}
*/


/*******************************************************************************
* Matrix::~Matrix()
*
* Deconstructor for Matrix object
********************************************************************************/
Matrix::~Matrix(){
    delete data;
}

/*******************************************************************************
* int getLength(){
*
* Output:
*   Returns length
********************************************************************************/
 int Matrix::getLength(){
    return length;
 }

/*******************************************************************************
* int getData(){
*
* Output:
*   Returns a pointer to the data array
********************************************************************************/
float* Matrix::getData(){
    return data;
}
