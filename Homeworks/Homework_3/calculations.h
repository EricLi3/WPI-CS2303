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
void get_totals(int[][7], int, int); 


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
void get_profits(int[][7], int, int, float[][2]); 


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
void top_earner(int[][7], int, int, float[][2]);