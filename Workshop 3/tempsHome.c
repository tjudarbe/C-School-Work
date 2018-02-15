// Name:Troy Udarbe
// Student Number: 041024142
// Email: tjudarbe@seneca.ca
// Section:Q
// Workshop:3

#define _CRT_SECURE_NO_WARNINGS

// Put your code below:
#include <stdio.h>
#define NUMS 4

int main(void) {
   int highValue;
   int lowValue;
   int numDay;
   float mean;
   int totalHigh = 0;
   int totalLow = 0;
   int highestValue =0;
   int lowestValue =0;
   int highDay, lowDay;

   printf("---=== IPC Temperature Analyzer ===---");

   for (numDay = 1; numDay <= NUMS; numDay++) { //Prompts the user for input until the numDay is equal to NUMS

      printf("\nEnter the high value for day %d: ", numDay);
      scanf("%d", &highValue);


      printf("\nEnter the low value for day %d: ", numDay);
      scanf("%d", &lowValue);

      while (lowValue > highValue || highValue > 40 || lowValue < -40) { //Loop occurs when input is invalid

         printf("\nIncorrect values, temperatures must be in the range -40 to 40,"
            " high must be greater than low.\n"); //Prints the error message 

         printf("\nEnter the high value for day %d: ", numDay); //Asks the user again for a high temperature
         scanf("%d", &highValue);

         printf("\nEnter the low value for day %d: ", numDay);// Asks the user again for a low temperatre
         scanf("%d", &lowValue);
      }
      if (highValue > highestValue) { /* An if statement to find the highest value. Since the highest value is intialized
                                  to 0 the first high value will be the first highest value and then compared to the next
                                  high values that are inputted by the user */
         highestValue = highValue;
         highDay = numDay;
      }

      if (lowValue < lowestValue) { //Same as finding the highest value but instead this if statement is used to find the lowest value
         lowestValue = lowValue;
         lowDay = numDay;
      }

      totalHigh += highValue;//Calculates the total for all valid high temperatures 
      totalLow += lowValue; //Calculates the total for all valid low temperatures
   }

   mean = (float)(totalHigh + (totalLow)) / (NUMS * 2); /* Calculates the mean. Casted a float since totalHigh and totalLow are integers
                                                        and if not casted the final answer would be rounded to an integer value and
                                                        not the correct float value.*/

   printf("\nThe average (mean) temperature was: %1.2f\n", mean);
   printf("The highest temperature was %d, on day %d\n", highestValue, highDay);
   printf("The lowest temperature was %d, on day %d\n", lowestValue, lowDay);
   return 0;
}
