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
/*******************************************************************************
* Matrix::~Matrix()
*
* Deconstructor for Matrix object
********************************************************************************/
Matrix::~Matrix(){
    delete data;
}
int Matrix::getLength(){
    return length;
 }
float* Matrix::getData(){
    return data;
}
Matrix Matrix::operator+(Matrix &B){
    Matrix C(length);
    for (int i = 0; i < length; i ++){
        C.data[i] = data[i] + B.data[i];
    }
    return C;
}

/**
 *  Allows A + 2.2
 *  @param a
 *  @returns Matrix object which is the result of adding a float to a Matrix object
*/
Matrix Matrix::operator+(float a){
    Matrix C(length);
    for(int i = 0; i< length; i++){
        C.data[i] = data[i] + a;
    }
    return C;
}

/**
 *  Allows 2.2 + A
 *  @param a
 *  @returns Matrix object which is the result of adding a Matrix object to a float
*/

Matrix operator+(float c, const Matrix& A){
    Matrix C(A.length);
    for(int i = 0; i < A.length; i++){
        C.data[i] = A.data[i] + c; 
    }
    return C;
}

/**
 * Allows cout << A
 * @param ostream& os
 * @param const Matrix& A
 * @returns nothing
 * side effect: allows us to print Matrix A to the console
*/
ostream& operator<<(ostream& os, const Matrix& A){
    for(int i = 0; i< A.length ; i++){
        os << std::setw(8) << A.data[i];
    }
    return os;
}