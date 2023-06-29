#include <stdio.h>
#include <fstream>
using std::string;
using std::cout;
using std::endl;
using std::ifstream;
using std::ostream;
class Matrix{
    public:
        Matrix(int);
        Matrix();
        ~Matrix();
        void readMatrix(string fileName);
        int getLength();
        float* getData();

        /**
         * Allows for A + B. 
        */
        Matrix operator+(Matrix &B);
        
        // needs to be implemented.

        /**
        *  Allows A + 2.2
        *  @param a
        *  @returns Matrix object which is the result of adding a float to a Matrix object
        */
        Matrix operator+(float a); 

        /**
        *  Allows 2.2 + A
        *  @param a
        *  @returns Matrix object which is the result of adding a Matrix object to a float
        */
        friend Matrix operator+(float, const Matrix& A);   

        /**
        * Allows cout << A
        * @param ostream& os
        * @param const Matrix& A
        * @returns nothing
        * side effect: allows us to print Matrix A to the console
        */
        friend ostream& operator<<(ostream& os, const Matrix& A); 
        
        void print();
    private:
        float *data;
        int length;
};

