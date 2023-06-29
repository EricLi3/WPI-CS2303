#include <stdio.h>
#include <fstream>
#include <iomanip>
using std::string;
using std::cout;
using std::endl;
using std::ifstream;

class Matrix{
    public:
        Matrix(int);
        Matrix();
        ~Matrix();
        int getLength();
        float* getData();
        void readMatrix(string fileName);
        
        void print();
        // overloading the + operator

        Matrix operator+(Matrix &m); // takes in a reference to a matrix.

       //Matrix operator+(Matrix); // takes in a matrix 
       
       //less efficient because needs to copy over the whole object.

    private:
        float *data;
        int length;
};
