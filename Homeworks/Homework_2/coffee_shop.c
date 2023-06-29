#include <stdio.h>
#include "calculations.h"

int main() {
    int option, item;
    char input_file_name[100]; 
    char output_file_name[100];
    char append_or_overwrite;

    printf("Which program would you like to run: (1) Calculate overall revenue, (2) Calculate register balance, or (3) Calculate sales for an item.\n");
    scanf("%d", &option);

    printf("Please enter an input file:\n");
    scanf("%s", input_file_name);
    
    FILE *f = fopen(input_file_name, "r");
    if (f == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    /*Switches between all the options the user can choose from, if the user choose a number other than 1, 2 or 3,
      we will print that the option is not valid.
    */
    switch (option) {
        case 1: // Overall revenue
            float revenue = overall_revenue(f);
            printf("%2.2f\n", revenue);
            break;
        case 2: // register balance
            float reg_balance = balance(f);
            printf("%2.2f\n", reg_balance);
            break;
        case 3: // tally
            printf("Which item to analyze?\n");
            scanf("%d", &item);
            int item_sales = tally(f, item);

            //printf("%d\n",item_sales);
            printf("What is the output file?\n");
            scanf("%s", output_file_name);

            printf("Enter A for Append or O for over-write.\n");
            scanf(" %c", &append_or_overwrite);

            FILE *output = fopen(output_file_name, (append_or_overwrite == 'A') ? "a" : "w");
            fprintf(output, "  %d   %d\n", item, item_sales);

            fclose(output);
            break;

        default:
            printf("This option is not valid.\n");
    }

    fclose(f);
    return 0;
}