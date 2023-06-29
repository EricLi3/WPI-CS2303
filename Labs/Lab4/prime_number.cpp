#include <iostream>

int checkPrime(int);
int main(void){
    // Initialize variables
    int value;
    // Prompt user for value
    //printf("Please enter a value:\n");
    std::cout <<"Please enter a value:\n";
    // Get value from terminal and store in variable
    std::cin >> value;
    //scanf("%d", &value);
    int isPrime = checkPrime(value);
    if (isPrime == 1){
        printf("This value is a prime number\n");
    }
    else{
         printf("This value is not a prime number\n");
    }
    return 0;
}
int checkPrime(int value){
    // Loop over all numbers  (x) less than the specified value (v)
    int x = 2;
    int notPrime = 0;
    while (x < value && notPrime == 0){
        //if the v/x is a whole number (hint, use the % operator which returns the remainder of a/b)
        if (value % x == 0){
            //then the value is not prime
            notPrime = 1;
            //print "This value is not a prime number" to the terminal
            return 0;
        }
        x++;
    }
    // If v/x was never a whole number
    if (notPrime == 0){
        return 1;
    }
    return 0;
}