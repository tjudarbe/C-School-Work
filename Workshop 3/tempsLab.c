// Name:Troy Udarbe
// Student Number:
// Email:
// Section:Q
// Workshop:3

#define _CRT_SECURE_NO_WARNINGS

// Put your code below:
#include <stdio.h>
#define NUMS 3

int main(void) {
   int highTemp;
   int lowTemp;
   int numDay;
   float mean;
   int totalHigh = 0;
   int totalLow = 0;
   
   

   printf("---=== IPC Temperature Analyzer ===---");
   
   for (numDay = 1; numDay <= NUMS; numDay++) { //Prompts the user for input until the numDay is equal to NUMS
     
      printf("\nEnter the high value for day %d: ", numDay);
      scanf("%d", &highTemp);
      printf("\nEnter the low value for day %d: ", numDay);
      scanf("%d", &lowTemp);
      
      
     
      
     while (lowTemp > highTemp || highTemp > 40 || lowTemp < -40) { //Loop occurs when input is invalid
         
         printf("\nIncorrect values, temperatures must be in the range -40 to 40," 
            " high must be greater than low.\n"); //Prints the error message 
        
         printf("\nEnter the high value for day %d: ", numDay); //Asks the user again for a high temperature
         scanf("%d", &highTemp);
         
         printf("\nEnter the low value for day %d: ", numDay);// Asks the user again for a low temperatre
         scanf("%d", &lowTemp);
            }  
               totalHigh = highTemp + totalHigh;//Calculates the total for all valid high temperatures 
               totalLow = lowTemp + totalLow; //Calculates the total for all valid low temperatures
     }
 
   mean = (float)(totalHigh + (totalLow)) / (NUMS * 2); /* Calculates the mean. Casted a float since totalHigh and totalLow are integers
                                                        and if not casted the final answer would be rounded to an integer value and 
                                                        not the correct float value.*/
printf("\nThe average (mean) temperature was: %1.2f\n", mean);

return 0;
}


