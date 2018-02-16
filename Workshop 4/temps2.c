// Name:Troy Udarbe
// Student Number: 041024142
// Email: tjudarbe@seneca.ca
// Section:Q
// Workshop:4

#define _CRT_SECURE_NO_WARNINGS

// Put your code below:
#include <stdio.h>
#define NUMS 10;

int main(void) {
   int highValue[10];
   int lowValue[10];
   int numberOfDays;
   int numDay;
   int highestValue;
   int lowestValue;
   int highDay;
   int lowDay;
   float average;
   int validNumber;
   int totalHigh = 0;
   int totalLow = 0;

   printf("---=== IPC Temperature Calculator V2.0 ===---");
   printf("\nPlease enter the number of days, between 3 and 10, inclusive: ");
   scanf("%d", &numberOfDays); //Get the number of days 

   while (numberOfDays < 3 || numberOfDays > 10) { //Checks for valid input from the user 
      printf("Invalid entry, please enter a number between 3 and 10, inclusive: ");
      scanf("%d", &numberOfDays);
   }

   printf("\n");

   for (numDay = 1; numDay <= numberOfDays; numDay++) { //Prompts the user for input until the numDay is equal to the number of days the user entered 

      printf("Day %d - High: ", numDay);
      scanf("%d", &highValue[numDay]);

      printf("Day %d - Low: ", numDay);
      scanf("%d", &lowValue[numDay]);

      lowestValue = lowValue[numDay];
      highestValue = highValue[numDay];
      highDay = numDay;
      lowDay = numDay;
   }

   for (numDay = 1; numDay <= numberOfDays; numDay++) {

      if (highValue[numDay] > highestValue) { //Calculates the highest value out of all the high values entered by the user 
         highestValue = highValue[numDay];
         highDay = numDay;
      }

      if (lowValue[numDay] < lowestValue) { //Calculates the lowest value out of all the low values entered by the user 
         lowestValue = lowValue[numDay];
         lowDay = numDay;
      }

   }

   printf("\n");
   printf("Day  Hi  Low\n");
   for (numDay = 1; numDay <= numberOfDays; numDay++) { // Prints the days and the high and low values for each day in a table 
      printf("%d    %d    %d\n", numDay, highValue[numDay], lowValue[numDay]);
   }



   printf("\nThe highest temperature was %d, on day %d\n", highestValue, highDay);
   printf("The lowest temperature was %d, on day %d\n", lowestValue, lowDay);


   do { //Loop runs until the while condition is false 
      printf("\nEnter a number between 1 and 4 to see the average temperature for the entered number of days, enter a negative number to exit: ");
      scanf("%d", &validNumber);

      while (validNumber > numberOfDays || validNumber == 0) { //Checks for valid input 
         printf("\nInvalid entry, please enter a number between 1 and 4, inclusive: ");
         scanf("%d", &validNumber);
      }

      if (validNumber > 0) {
         totalHigh = 0; /*Everytime the user enters a valid input, the totalHigh and totalLow is reset to 0 in order to calculate the average
                         properly*/
         totalLow = 0;
         for (numDay = 1; numDay <= validNumber; numDay++) {

            totalHigh += highValue[numDay];
            totalLow += lowValue[numDay];
            average = (float)(totalHigh + totalLow) / (validNumber * 2);
         }
         printf("\nThe average temperature up to day %d is: %.2f\n", validNumber, average);

      }
      else { //Happens if user enters a negative value
         printf("\nGoodbye!\n");
      }
   } while (validNumber <= numberOfDays && validNumber > 0);


   return 0;
}
