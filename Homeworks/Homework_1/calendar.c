#include <stdio.h>

int givenYear; // the input year of the user
int year_start; // the first day of the week is stored here. (0: Sunday, 1: Monday, etc)
//Function protypoes
int isLeap(int);               // takes year, returns if year is a leap year or not
int get_year_start(int);            // takes year, returns day that year starts on
void printCalendar(int, int);       // takes year and start day, prints 12 months
int printMonth(int, int, int);      // takes year, month and start day of month, prints 1 month, returns start of next month
int printMonthName(int, int);       // takes year and month number, prints header for that month, returns number of days in month

/*******************************************************
* Prompts the user to enter a year, 
* Stores the entered value in givenYear variable.
* Calls printCalendar with argunments the givenYear and calls the get_year_start method to get the first day.
*/
int main(void){
    printf("Please enter year for this calendar:\n");
    scanf("%d", &givenYear);

    printf("***    CALENDAR for %d   ***\n\n", givenYear);
    printCalendar(givenYear,get_year_start(givenYear));
    return 0;
}

/********************************************************
 * isLeap(int year)
 * Determines if a year is a leap year
 * Input :
 *      year : the year being studied
 * Returns :
 *      Whether the year is a leap year or not
 *      1:true
 *      0:false
 * 
 * Source: "The C Programming Language second Edition K&R"
*/
int isLeap(int year)
{
    if((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
        return 1; // true
    else
        return 0; // false  
}

/********************************************************
*   get_year_start(int year)
*   Determines the day of the week that the specified
*   year starts on. Uses current calendar rules (ignores calendar changes)
*   Input:
*       year: the year being studied
*   Returns:
*       The day of the week the year starts on
*       0: Sunday, 1: Monday, etc
*   Source:
*       https://stackoverflow.com/questions/478694/what-is-the-easiest-algorithm-
to-find-the-day-of-week-of-day-zero-of-a-given-year
*********************************************************/
int get_year_start(int year){
    int year_start =  (((year-1) * 365) + ((year-1) / 4) - ((year-1) / 100) + 
((year-1) / 400) + 1) % 7;
    return year_start;
}

/********************************************************
*   printCalendar(int year, int day)
*   Prints 1 year of a calendar
*   
*   Input:
*       year: the year being studied
*       day: the day of the week that the year starts on (Between and including 0 and 6)
*   Returns:
*       Nothing
*   Calls: printMonth
*********************************************************/
void printCalendar(int year, int day){
    for(int i = 0; i < 12; i++){
        day = printMonth(year, i, day);
    }
}

/********************************************************
*   printMonth(int year, int month, int start_day)
*   Prints 1 month of a calendar, returns the start of the next month
*   
*   Input:
*       year: the year being studied
*       month: the month to be printed
*       start_day: the day of the week that the month starts on
*   Returns:
*       The start day of the next month
*   Calls: printMonthName
*********************************************************/
int printMonth(int year, int month, int start_day){

    int numDays = printMonthName(year, month);

    printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");
    //          0   1    2    3    4    5    6

    //Determine the start day of the next month
    int next_month_start_day = (start_day + numDays) % 7;

    for(int j=0; j<start_day; j++) { // loop prints 5 blank spaces (start_day) times. If j is not Sunday (0), it prints one extra blank space
		
        printf("     "); // 5 blank spaces because that is the width of the dates.   
}

	for(int k=1; k<=numDays; k++){ // loop puts a number or day of the month under the corresponding day for each month 
		printf("%5d", k);
		
		start_day++;   

		if(start_day == 7) { // tests whether start_day is one day after Saturday
			printf("\n");
			start_day = 0; // true
		}

	}
	
	printf("\n");
	printf("\n");

	return next_month_start_day;
	
 }

/********************************************************
*   printMonthName(int year, int month)
*   prints header for the month, returns number of days in month
*   
*   Input:
*       year: the year being studied
*       month: the month to be printed
*   Returns:
*       The number of days in the month
*********************************************************/
int printMonthName(int year, int month){
    int days; // stores the number of days in a month

    switch(month){ // using a switch case to account for the different months having a differnt amount of days.
        case 0 : 
            printf("January %d\n\n", year);
            days = 31; // days in January
            break;

        case 1 :
            printf("February %d\n\n", year); // Here, need to implement leap year for HW1
            days = isLeap(year) ? 29 : 28; // using the ternary operator here to account for the 
            break;                       //difference in days in Feb if the year is a leap year

        case 2 : 
            printf("March %d\n\n", year);
            days = 31;  // days in March
            break;

        case 3 :
            printf("April %d\n\n", year);
            days = 30;  // days in April
            break;
        
        case 4 :
            printf("May %d\n\n", year);
            days = 31;  // days in  May
            break;

        case 5 :
            printf("June %d\n\n", year);
            days = 30;  // days in June
            break;

        case 6 :
            printf("July %d\n\n", year);
            days = 31;  // days in July
            break;

        case 7 :
            printf("August %d\n\n", year);
            days = 31;  // days in August
            break;

        case 8 :
            printf("September %d\n\n", year);
            days = 30;  // days in September
            break;

        case 9 :
            printf("October %d\n\n", year);
            days = 31;  // days in October
            break;

        case 10:
             printf("November %d\n\n", year);
            days = 30;  // days in November
            break;

        case 11:
            printf("December %d\n\n", year);
            days = 31;  // days in December
            break; 
    }
    return days;
}