/* -------------------------------------------
Name:
Student number:
Email:
Section:
Date:
----------------------------------------------
Assignment: 1
Milestone:  2
---------------------------------------------- */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

// This source file needs to "know about" the structures you declared
// in the header file before referring to those new types:
// HINT: put the header file name in double quotes so the compiler knows
//       to look for it in the same directory/folder as this source file
// #include your contacts header file on the next line:

#include "contacts.h"
int main (void)
{
    // Declare variables here:
   struct Name fullName = {" ", {" "}, {" "}};
   struct Address houseAddress = {0, {" "}, { 0 }, {" " " " " "}, {" "}};
   struct Numbers contactNumbers = {" ",{ " " },{ " " }};
   char option;


    // Display the title
   printf("Contact Management System\n");
   printf("-------------------------\n");


    // Contact Name Input:
   printf("Please enter the contact's first name: ");
   scanf("%s", &fullName.firstName);
   printf("\nDo you want to enter a middle initial(s)? (y or n): ");
   scanf(" %c", &option);
   if (option == 'y' || option == 'Y') {
      printf("Please enter the contact's middle intial(s): ");
      scanf("\n%s", &fullName.middleInitial);
   }
   
   printf("\nPlease enter the contact's last name: ");
   scanf("%s", fullName.lastName);
   printf("\nPlease enter the contact's street number: ");
   scanf("%d", &houseAddress.streetNumber);
   printf("\nPlease enter the contact's street name: ");
   scanf("%s", houseAddress.street);
   printf("\nDo you want to enter an apartment number? (y or n): ");
   scanf(" %c", &option);
   if (option == 'y' || option == 'Y') {
      printf("Please enter the contact's apartment number: ");
      scanf("\n%d", &houseAddress.apartmentNumber);
   }
   printf("\nPlease enter the contact's postal code: ");
   scanf(" %[^\n]s", &houseAddress.postalCode);
   
   printf("Please enter the contact's city: ");
   scanf("%s", houseAddress.city);

   printf("Do you want to enter a cell number? (y or n): ");
   scanf(" %c", &option);
   if (option == 'y' || option == 'Y') {
      printf("Please enter the contact's cell phone number: ");
      scanf("%s", &contactNumbers.cell);
   }

   printf("Do you want to enter a home number? (y or n): ");
   scanf(" %c", &option);
   if (option == 'y' || option == 'Y') {
      printf("Please enter the contact's home phone number: ");
      scanf("%s", &contactNumbers.home);
   }

   printf("Do you want to enter a business phone number? (y or n): ");
   scanf(" %c", &option);
   if (option == 'y' || option == 'Y') {
      printf("Please enter the contact's business phone number: ");
      scanf("%s", &contactNumbers.business);
   }

   printf("\n");



    // Display Contact Summary Details

   printf("Contact Details\n");
   printf("---------------");
   printf("\nName Details");
   printf("First name: %s\n", fullName.firstName);
   printf("Middle initial(s): %s\n", fullName.middleInitial);
   printf("Last name: %s\n", fullName.lastName);
   printf("\n");

   printf("Address Details\n");
   printf("Street number: %d\n", houseAddress.streetNumber);
   printf("Street name: %s\n", houseAddress.street);
   printf("Apartment: %d\n", houseAddress.apartmentNumber);
   printf("Postal code: %s\n", houseAddress.postalCode);
   printf("City: %s\n", houseAddress.city);
   printf("\n");

   printf("Phone numbers:\n");
   printf("Cell phone number: %s\n", contactNumbers.cell);
   printf("Home phone number: %s\n", contactNumbers.home);
   printf("Business phone number %s\n", contactNumbers.business);
   printf("\n");
   



    // Display Completion Message



    return 0;
}

/*  SAMPLE OUTPUT:
    
Contact Management System
-------------------------
Please enter the contact's first name: Tom
Do you want to enter a middle initial(s)? (y or n): y
Please enter the contact's middle initial(s): Wong
Please enter the contact's last name: Song
Please enter the contact's street number: 20
Please enter the contact's street name: Keele
Do you want to enter an appartment number? (y or n): y
Please enter the contact's appartment number: 40
Please enter the contact's postal code: A8A 4J4
Please enter the contact's city: Toronto
Do you want to enter a cell phone number? (y or n): Y
Please enter the contact's cell phone number: 905-111-6666
Do you want to enter a home phone number? (y or n): Y
Please enter the contact's home phone number: 705-222-7777
Do you want to enter a business phone number? (y or n): Y
Please enter the contact's business phone number: 416-333-8888

Contact Details
---------------
Name Details
First name: Tom
Middle initial(s): Wong
Last name: Song

Address Details
Street number: 20
Street name: Keele
Apartment: 40
Postal code: A8A 4J4
City: Toronto

Phone Numbers:
Cell phone number: 905-111-6666
Home phone number: 705-222-7777
Business phone number: 416-333-8888

Structure test for Name, Address, and Numbers Done!
*/