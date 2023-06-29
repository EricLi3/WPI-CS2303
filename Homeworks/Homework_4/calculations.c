/*
void get_totals(int[][7], int, int); 
void get_profits(int[][7], int, int, float[][2]); 
void top_earner(int[][7], int, int, float[][2]);
*/
#include <stdio.h>
#include <stdlib.h>
#include "calculations.h"

/**
 * This function takes and reads the Cost column of the Costs.txt file into an array. 
 * @param numItems
 * @returns costs which is a pointer to a float array in the heap
*/
float* readCosts(int numItems){
    float *costs = calloc(numItems, sizeof(float)); // allocates and intializes memory to the heap using calloc. 

    FILE* f1 = fopen("Costs.txt", "r"); // opens the file and reads it. 
    if (f1 == NULL){
        printf("Error opening file Costs.txt\n");
        exit(1);
    }

    int itemNum;
    float salesCost;
    float purchaseCost;
    while(fscanf(f1, "%d %f %f", &itemNum, &salesCost, &purchaseCost) > 0){ // loops through file until there are not 3 data values on a line
        costs[itemNum] = salesCost;  // sets the value stored in the costs array at index itemNum to be the tempory value of salesCost. 
    }

    fclose(f1); //closes the file. 
    return costs;
}

/**
 * This function takes and reads the Purchase column of the Costs.txt file into an array.
 * @param numItems
 * @returns purch which is a pointer to a float array in the heap
*/
float* readPurch(int numItems){
    float *purch = calloc(numItems, sizeof(float)); // allocates and intializes memory to the heap using calloc. 
    
    FILE* f2 = fopen("Costs.txt", "r"); // opens the file to be read
    if(f2 == NULL){ // error handling for if the file can't be opened. 
        printf("Error opening file Costs.txt\n");
        exit(1);
    }
    int itemNum;
    float salesCost;
    float purchaseCost;
    while(fscanf(f2, "%d %f %f", &itemNum, &salesCost, &purchaseCost) > 0){// loops through file until there are not 3 data values on a line
        purch[itemNum] = purchaseCost; // sets the value stored in the purch array at index itemNum to be the tempory value of purchaseCost. 
    }
    fclose(f2);
    return purch;
}

/**
 * This function should create Total_sales.txt that contains a list of each item 
    and the total number of sales for the item. 
    @param int month_data[][7]
    @param int rows
    @param int cols
    @return nothing
    Side effects : makes a file "Total_sales.txt " that contains a list of each item 
    and the total number of sales for the item. 
*/
void get_totals(int rows, int col, int month_data[][col]){
    // Open output file
    FILE* f1 = fopen("Total_sales.txt", "w");
    // loop over all rows
    for (int i = 1; i < rows; i++){
        int total = 0;
        // add together the columns
        for (int j = 1; j < col; j++){
            total = total + month_data[i][j];
        }
        // Print to file
        fprintf(f1, "%5d %5d\n", i, total);
    }
    // close file
    fclose(f1);
}

/**
 * This function should create Profits.txt that contains the total sales, total cost, 
    amount earned and profit for each item (cost – sales price)*items sold
    @param int month_data[][7]
    @param int rows
    @param int cols
    @param float money[][2]
    @return nothing
    Side effects : makes a file "Profits.txt" that contains the total sales, total cost, 
    amount earned and profit for each item  
*/
void get_profits(int rows, int col, int month_data[][col], float costs[], float purch[]){
    
    //  Open file and print header
    FILE* f2 = fopen("Profits.txt", "w");
    fprintf(f2, "    Item       #   Sales    Cost Revenue\n");
    
    // loop over all items
    for (int i = 1; i < rows; i++){
        int total = 0;
        // get total
        for (int j = 1; j < col; j++){
            total = total + month_data[i][j];
        }
        // Calculate the total sales and total purchase cost
        float Tsales = total * costs[i];
        float Tcost = total * purch[i];

        // print to file
        fprintf(f2, "%8d%8d", i, total);
        fprintf(f2, "%8.2f%8.2f%8.2f\n", Tsales, Tcost, Tsales-Tcost);
    }
    fclose(f2);
}



/**
 * This function should create Top_earners.txt which should list the 10 items 
    with the highest revenue.  
    @param int month_data[][7]
    @param int rows
    @param int cols
    @param float money[][2]
    @return nothing
    Side effects : makes a file "Top_earners.txt" that contains a list of the top 10
    items with the highest revenue.
*/
void top_earner(int rows, int cols, int month_data[][cols], float costs[], float purch[]){

 // get revenue data and store in array
    float rev[rows];
    float tots[rows];

    for (int i = 0; i < rows; i ++){
        int total = 0;
        for (int j = 1; j < cols; j++){
            total = total + month_data[i][j];
        }
        tots[i] = total;
        float Tsales = total *costs[i];
        float Tcost = total *purch[i];
        rev[i] = Tsales - Tcost;
    }
    
    // Open output file
    FILE* f2 = fopen("Top_earners.txt", "w");
    fprintf(f2, "Item   #  Revenue\n");
    // get top item 10 times by looping over the
    // data 10 times, finding the highest value each time
    for (int j = 0; j < 10; j++){
        float top_val = 0;
        int top_it = 0;
        int top_num = 0;
        // loop over all rows, see if larger than current largest value
        for (int i = 0; i < rows; i++){
            if (rev[i] > top_val){
                top_val = rev[i];
                top_it = i;
                top_num = tots[i];
            }
        }
        // print top item to file and change its data to 0
        fprintf(f2, "%4d %3d %8.2f\n", top_it, top_num, top_val);
        rev[top_it] = 0;
    }
}