#include <stdio.h>
#include <stdlib.h>
#include "calculations.h"

#define ITEMS 51

void get_totals(int rows, int col, int array[][col]); 
void get_profits(int rows, int col, int array[][col], float costs[], float purch[]); 
void top_earner(int rows, int col, int array[][col], float costs[], float purch[]);

int main(int argc, char* argv[]){

    if (argc < 2){
        printf("Please specify at least one month file.\n");
        return 1;
    }

    // allocate arrays to store the data for the given number of months
    int num_months = argc - 1; // minus 1 because first is the executable name
    int month_data[ITEMS][num_months + 1]; // CHANGED the columns paramater. 

    float* costs = readCosts(ITEMS); 
    float* purch = readPurch(ITEMS);

    // initialize month_data to zeros
    for (int i = 0; i < num_months + 1; i ++){
        for (int j = 0; j < ITEMS; j++){
            month_data[j][i] = 0;
        }
    }
    int new_item;
    float cost;
    //loop over all months
    for (int i = 0; i < num_months; i++){
        FILE* f1;

        // open sales file
        f1 = fopen(argv[i + 1], "r");

        // load month data
        while(fscanf(f1, "%d %f", &new_item, &cost) > 0){
            month_data[new_item][i+1] = month_data[new_item][i+1] + 1; // adding 1 to count of product
            month_data[new_item][0] = new_item;
        }
        fclose(f1);
    } // end loop over months

    // call all 3 functions here
    
    get_totals(ITEMS, num_months + 1, month_data);
    get_profits(ITEMS, num_months + 1, month_data, costs, purch);
    top_earner(ITEMS, num_months + 1, month_data, costs, purch);

    //Deallocates the memory  taken by cost and purch 
    free(costs);
    free(purch);

    return 0;
}