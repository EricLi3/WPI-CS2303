#include <stdio.h>
#include <stdlib.h>

float get_average(float total, int count);

int main(int argc, char *argv[]){

    if(argc != 3){
        printf("Wrong number of argunments");
        return 1;
    }

  
    //printf("How many values?\n");   // Prompt user for number of values
    //scanf(" %d", &numVals);         // Get number of values
    int numVals = atoi(argv[1]); // store the number of data values


    //float data[numVals];        // create array to store values
      //float data[numVals]; 
    int count = 0;
    float sum = 0;
    float data[numVals];

    //printf("Input values\n");
    FILE *in_file = fopen("data.txt", "r");
    while(numVals > 0 && fscanf(in_file, "%f", &data[count]) > 0){
        sum += data[count];
        count++;
        numVals --;
    }
    fclose(in_file);

    
    printf("Your values are: ");
    for (int i = 1; i < count; i++){
        printf("%7.2f ", data[i]);
    }
    printf("\n");

    float thisAv = get_average(sum, count);
    printf("Your average is %6.2f\n", thisAv);
}


float* readData(char* filename, int size){
    float *b = malloc(sizeof(float) * size);
    printf("%p", b);
    return 0;
}


float get_average(float total, int count){
   
    return total/count;
}