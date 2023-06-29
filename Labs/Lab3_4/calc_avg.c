#include <stdio.h>
#include <stdlib.h>

float get_average(float total, int count);

int main(int argc, char *argv[]){

    if(argc != 3){ // 3 argunments because the first is the execuable name 
        printf("Wrong number of argunments");
        return 1;
    }
  
    //printf("How many values?\n");   // Prompt user for number of values
    //scanf(" %d", &numVals);         // Get number of values
    int numVals = atoi(argv[1]); // store the number of data values

    int count = 0;
    float sum = 0;
    float data[numVals];// create array to store values

    //printf("Input values\n");
    FILE *in_file = fopen("data.txt", "r");
    while(numVals > 0 && fscanf(in_file, "%f", &data[count]) > 0){
        sum += data[count];
        count++; // changing count thus changing where the data is stored in the data array
        numVals --; // making sure that the loop terminates 
    }
    fclose(in_file);

    //Tells the user what values they entered in the file. 
    printf("Your values are: ");
    for (int i = 0; i < count; i++){
        printf("%7.2f ", data[i]);
    }
    printf("\n");

    float thisAv = get_average(sum, count); // calls the helper function get_average
    printf("Your average is %6.2f\n", thisAv); // prints the average value
}
//End of main
/**
 * Takes the file name and number of data points as the parameters and returns a pointer to the array containing the data
 * @param filename
 * @param size
 * @returns The pointer to the allocated data array
*/
float* readData(char* filename, int size){
    float *b = malloc(sizeof(float) * size); // making the space needed to store the data array
    /*Can then potentially open the file and add the data from it to the data array*/

    printf("%p", b); // prints to the console the pointer to the allocated data array 
    return 0;
}

/**
 * Computes the average
 * @param total
 * @param count
 * @returns Float value representing the average. 
*/
float get_average(float total, int count){
   
    return total/count;
}