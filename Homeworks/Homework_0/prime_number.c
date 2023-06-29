#include<stdio.h>

int main() 
{
    int v; // initialize the variable v
    printf("Please enter a value: \n"); // prompts the user to enter a value.
    scanf("%d", &v); // stores the value entered by the user in variable v.

    /* Handles the edge cases for which a number less than 
       2 is entered, in which it's not prime.*/
    if (v < 2) {
        printf("This value is not a prime number."); // prints to the console that the value is not a prime number.
        return 0;
    }
    /*loops over all values after 2 and under the entered value, using the modulo operator to determine
    if the entered value is prime or not.*/
    for (int x = 2; x < v; x++) {
        if (v % x == 0) { // checks if after dividing number by x, if the remainder is 0, then the entered value is not prime.
            printf("This value is not a prime number.");// prints to the console that the value is not a prime number.
            return 0; // ends the program
        }
    }
    //If we got down here, the number v has to be prime
    printf("This value is a prime number"); // prints to the console that the value is a prime number.
}