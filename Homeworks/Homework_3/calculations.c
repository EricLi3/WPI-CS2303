/*
void get_totals(int[][7], int, int); 
void get_profits(int[][7], int, int, float[][2]); 
void top_earner(int[][7], int, int, float[][2]);
*/
#include <stdio.h>

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
void get_totals(int month_data[][7], int rows, int cols){
    int item_count[51] = {0};

    for(int i = 0; i < rows; i++){
        for(int j = 1; j<cols; j++){
            item_count[i] += month_data[i][j];
        }
    }
    //write total sales to a file
    FILE *fp = fopen("Total_sales.txt", "w");
    if(fp == NULL){
        printf("Error opening file\n");
        return;
    }

    for(int i = 0; i < rows; i++){
        fprintf(fp, "%d     %d\n", i, item_count[i]);
    }
    fclose(fp);
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
void get_profits(int month_data[][7], int rows, int cols, float money[][2]){
    FILE *f = fopen("Profits.txt", "w"); // makes the file we are going to write to. 
    if(f == NULL){
        printf("Error opening file\n");
        return;
    }
        //print the header
        fprintf(f, "    Item       #   Sales    Cost Revenue\n");
         for (int i = 1; i < rows; i++) {
            int item = month_data[i][0];
            int total_quantity = 0;
            float total_sales = 0;
            float total_cost = 0;

        // Loop through each month
        for (int j = 1; j < cols; j++) {
            int quantity = month_data[i][j];
            total_quantity += quantity;
            total_sales += quantity * money[i][0];
            total_cost += quantity * money[i][1];
        }
        float total_revenue = total_sales - total_cost;
             //print the results
             fprintf(f, "    %4d       %d   %.2f    %.2f   %.2f\n", item, total_quantity, total_sales, total_cost, total_revenue);
        }
        fclose(f);
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
void top_earner(int month_data[][7], int rows, int cols, float money[][2]){

 FILE *f = fopen("Top_earners.txt", "w"); // makes the file we are going to write to. 
    if(f == NULL){
        printf("Error opening file\n");
        return;
    }
    //Calculate revenue for each item
    float total_revenue[rows];
    for (int i = 0; i < rows; i++) {
        int item = month_data[i][0];
        int total_quantity = 0;
        float total_sales = 0;
        float total_cost = 0;
        
        // Calculate the quantity, sales, and cost for each item
        for (int j = 1; j < cols; j++) {
            int quantity = month_data[i][j];
            total_quantity += quantity;
            total_sales += quantity * money[i][0];
            total_cost += quantity * money[i][1];
        }
        
        // Calculate the revenue for each item
        total_revenue[item] = total_sales - total_cost; // store the values of total_revenues in their respective spots.
    }

    //Sorting the items in decending order based on revenue

    int item_index[rows];

    //initialize values inside of the array 0 to rows - 1 so 0 to 50
    for(int i = 0; i < rows; i++){
        item_index[i] = i;
    }


    for(int i = 0; i < rows - 1; i++){
        for(int j = i + 1; j < rows; j++){
            if(total_revenue[j] > total_revenue[item_index[i]]){

                int temp = item_index[i];
                item_index[i] = item_index[j];
                item_index[j] = temp;
            }
        }
    }

    //Write the data

    //header
    fprintf(f,"Item   #  Revenue\n");

    //data
    int count = 0;
    for(int i = 0; i < rows && count < 10; i++){
        int item = item_index[i];

        int amount_total = 0;
        for(int j = 1; j < cols; j++){
            int amount_partial = month_data[item][j];
            amount_total += amount_partial;
        }
    fprintf(f, "%d   %d  %.2f\n", item, amount_total, total_revenue[item]);
    count++;
    }   
    fclose(f);
}   