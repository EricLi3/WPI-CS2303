/**
 * This function takes and reads the Cost column of the Costs.txt file into an array. 
 * @param numItems
 * @returns costs which is a pointer to a float array in the heap
*/
float* readCosts(int numItems);

/**
 * This function takes and reads the Purchase column of the Costs.txt file into an array.
 * @param numItems
 * @returns purch which is a pointer to a float array in the heap
*/
float* readPurch(int numItems);

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
void get_totals(int rows, int col, int month_data[][col]); 


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
void get_profits(int rows, int col, int month_data[][col], float costs[], float purch[]);


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
void top_earner(int rows, int cols, int month_data[][cols], float costs[], float purch[]);