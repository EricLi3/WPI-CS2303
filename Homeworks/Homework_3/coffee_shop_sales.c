#include <stdio.h>
#include "calculations.h"

#define ITEMS 51

void get_totals(int[][7], int, int);
void get_profits(int[][7], int, int, float[][2]);
void top_earner(int[][7], int, int, float[][2]);

int main(void){
    // allocate arrays to store 6 months of data
    int month_data[ITEMS][7];
    float money[ITEMS][2];
    // initialize month_data to zeros
    for (int i = 0; i < 7; i ++){
        for (int j = 0; j < ITEMS; j++){
            month_data[j][i] = 0;
        }
    }
    int new_item;
    float cost;
    //loop over all months
    for (int i = 0; i < 6; i++){
        FILE* f1;
        // open sales file
        switch (i) {
            case 0:
                f1 = fopen("Jan_data.txt", "r");
                break;
            case 1:
                f1 = fopen("Feb_data.txt", "r");
                break;
            case 2:
                f1 = fopen("Mar_data.txt", "r");
                break;
            case 3:
                f1 = fopen("Apr_data.txt", "r");
                break;
            case 4:
                f1 = fopen("May_data.txt", "r");
                break;
            case 5:
                f1 = fopen("Jun_data.txt", "r");
                break;
        } // end switch
        // load sales data
        while(fscanf(f1, "%d %f", &new_item, &cost) > 0){
            month_data[new_item][i+1] = month_data[new_item][i+1] + 1;
            month_data[new_item][0] = new_item;
        }
        fclose(f1);
    } // end loop over months
    // load sales data


    FILE* f2 = fopen("Costs.txt", "r");
    float purchase;
    //int new_item;
    //float cost;
    while(fscanf(f2, "%i %f %f", &new_item, &purchase, &cost) > 0){
            money[new_item][0] = purchase;
            money[new_item][1] = cost;
        }
    fclose(f2);
    // call all 3 functions here
    
    get_totals(month_data, ITEMS, 7);
    get_profits(month_data, ITEMS, 7, money);
    top_earner(month_data, ITEMS, 7, money);
}