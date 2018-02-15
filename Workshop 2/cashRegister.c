/*
Name:      <Troy Udarbe>
Student#:  <041024142>
Section:   <Q>
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
// Start your code below:
int main(void) {
   int loonies, quarters, dimes, nickles, pennies;
   float amount, balance, gstAmount;
   
   printf("Please enter the amount to be paid: $");
   scanf("%f", &amount); //prompts the user to enter an amount 
   gstAmount = amount * .13 + 0.005 + amount; //applies GST to the amount entered
   printf("GST: 1.13\n");
   printf("Balance owing: $%1.2f\n", gstAmount);
   
   loonies = gstAmount; 
   balance = gstAmount - loonies; 
   printf("Loonies required: %d, balance owing $%.2f\n", loonies, balance);
   
   quarters = (100 * balance) / 25; // Calculates the amount of quarters needed 
   balance = (int)(balance*100) % 25; /* Calculates the remaining balance. Since it is module
                                      division we need to cast the variable balance as an 
                                      integer or it would not run*/ 
   printf("Quarters required: %d, balance owing $%1.2f\n", quarters, balance/100); /* Displays. Divides by 100
                                                                                   so that it can convert the balance into cents*/

   dimes = (balance /100) / 0.1; //Calculates the amount of dimes needed 
   balance = (int)(balance) % 10; //Calculates remaining balance 
   printf("Dimes required: %d, balance owing $%1.2f\n", dimes, balance/100);

   nickles = (balance / 100) / 0.05; //Calculates the amount of nickles needed
   balance = (int)(balance) % 5; 
   printf("Nickels required: %d, balance owing $%1.2f\n", nickles, balance/100);

   pennies = balance / 1; //Calculates the amount of pennies needed 
   balance = (int)(balance) % 1; //Calculates remaining balance 
   printf("Pennies required: %d, balance owing $%1.2f\n", pennies, balance/10);
   
   
   
   return 0;
}