#include <iostream>

float get_average(float, float, float);

int main(void){
    float x, y, z;
    std::cout <<"Please enter 3 numbers\n";
    std::cin >> x >> y >> z; // says read from the standard input into the variables x, y and z
    float average = get_average(x, y, z);
    std::cout <<"The average is " << average << std::endl; // std::endl adds a newline character to the end. 
    int a = 3%2;
    std::cout << a << std::endl;
    return 0;
}


float get_average(float a, float b, float c){
    float total = a + b + c;
    return total/3.0;
}