#include "calculations.h"

//float overall_revenue(FILE *f); 
//float balance(FILE *f); 
//int tally(FILE *f, int item);

/**
 * Reads the file and calculate the overall revenue for the day. Returns a float. 
*/
float overall_revenue(FILE *f){
    float revenue = 0;
    int item_code;
    float item_cost;

    //Read the contents of the file
    while(fscanf(f, "%d %f", &item_code, &item_cost) == 2){ // since the return of fscanf is the number of input items successfully matched and assigned
        if(item_code != 0){//all items besides the first /     of input items successfully matched and assigned
            revenue += item_cost; // adds price of an item to the total revenue
        }
    }
    return revenue; // returns the overall reveue for the day
}
/**
 * Read the file and calculate the balance in the cash register at the end of the day. 
 * Returns a float. 
*/
float balance(FILE *f){
    int item_code;
    float item_cost;
    float final_balance = 0;
    while(fscanf(f, "%d %f", &item_code, &item_cost) == 2){ // since the return of fscanf is the number of input items successfully matched and assigned
        if(item_code == 0){//all items besides the first /     of input items successfully matched and assigned
            final_balance = item_cost; // initializes the final_balance to be the intital balance for the day
        }
        else if(item_code != 0){
            final_balance += item_cost; // adds the prices of the items to the final_balance variable.
        }
    }
    return final_balance; // returns the final_balance for the day
}

/**
 * Reads the file and tallies the number of times a particular item was sold and the total 
 * revenue from that item. Returns an int.
*/
int tally(FILE *f, int item){
    int item_code;
    float item_cost;
    int occurrences = 0;
    while(fscanf(f, "%d %f", &item_code, &item_cost) == 2){
        if(item_code == item){
            occurrences++;
        }
    }
    return occurrences;
}