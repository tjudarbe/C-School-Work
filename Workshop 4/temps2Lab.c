// Name:Troy Udarbe
// Student Number: 041024142
// Email: tjudarbe@seneca.ca
// Section:QQ
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

   printf("---=== IPC Temperature Calculator V2.0 ===---");
   printf("\nPlease enter the number of days, between 3 and 10, inclusive: ");
   scanf("%d", &numberOfDays);

   while (numberOfDays < 3 || numberOfDays > 10) {
      printf("\nInvalid entry, please enter a number between 3 and 10, inclusive: ");
      scanf("%d", &numberOfDays);
   }

   printf("\n");
   for (numDay = 1; numDay <= numberOfDays; numDay++) {

      printf("Day %d - High: ", numDay);
      scanf("%d", &highValue[numDay]);


      printf("Day %d - Low: ", numDay);
      scanf("%d", &lowValue[numDay]);
   }

   printf("\n");
   printf("Day  Hi  Low\n");
   for (numDay = 1; numDay <= numberOfDays; numDay++) {
      printf("%d    %d    %d\n", numDay, highValue[numDay], lowValue[numDay]);
   }

   return 0;
}
