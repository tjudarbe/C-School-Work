/* -------------------------------------------
Name:
Student number:
Email:
Section:
Date:
----------------------------------------------
Assignment: 2
Milestone:  3
---------------------------------------------- */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

// +-------------------------------------------------+
// | NOTE:  Include additional header files...       |
// +-------------------------------------------------+
#include "contactHelpers.h"
#include "contacts.h"
#include <string.h>



// +---------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-2   |
// |        function definitions below...              |
// |                                                   |
// | *** See hint regarding the getNumbers function    |
// +---------------------------------------------------+


// getName:
void getName(struct Name* name) {
   char option;

   printf("Please enter the contact's first name: ");
   scanf("%s", name->firstName);

   printf("Do you want to enter a middle initial(s)? (y or n): ");
   option = yes();
   if (option == 1) {
      printf("Please enter the contact's middle initial(s): ");
      scanf("%s", name->middleInitial);

   }

   printf("Please enter the contact's last name: ");
   scanf("%s", name->lastName);
}


// getAddress:
void getAddress(struct Address* address) {
   char option;
   printf("Please enter the contact's street number: ");
   address->streetNumber = getInt();
   printf("Please enter the contact's street name: ");
   scanf("%[^\n]s", address->street);
   printf("Do you want to enter an apartment number? (y or n): ");
   option = yes();

   if (option == 1) {
      printf("Please enter the contact's apartment number: ");
      address->apartmentNumber = getInt();
   }
   printf("Please enter the contact's postal code: ");
   scanf(" %[^\n]s", address->postalCode);

   printf("Please enter the contact's city: ");
   scanf("%s", address->city);
}


// getNumbers:
// HINT:  Update this function to use the new helper 
//        function "getTenDigitPhone" where applicable
void getNumbers(struct Numbers* numbers) {
   char option;
   printf("Please enter the contact's cell phone number: ");
   getTenDigitPhone(numbers->cell);
   //scanf("%s", numbers->cell);


   printf("Do you want to enter a home phone number? (y or n): ");
   option = yes();
   if (option == 1) {
      printf("Please enter the contact's home phone number: ");
      getTenDigitPhone(numbers->home);
      //scanf("%s", numbers->home);
   }

   printf("Do you want to enter a business phone number? (y or n): ");
   option = yes();
   if (option == 1) {
      printf("Please enter the contact's business phone number: ");
      getTenDigitPhone(numbers->business);
      //scanf("%s", numbers->business);
   }


}


// getContact
void getContact(struct Contact* contact) {
   getName(&contact->name);
   getAddress(&contact->address);
   getNumbers(&contact->numbers);
}
