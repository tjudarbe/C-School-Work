/* -------------------------------------------
Name:
Student number:
Email:
Section:
Date:
----------------------------------------------
Assignment: 2
Milestone:  2
---------------------------------------------- */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

// This source file needs to "know about" the structures you declared
// in the header file before referring to those new types:
// HINT: put the header file name in double quotes so the compiler knows
//       to look for it in the same directory/folder as this source file
// #include your contacts header file on the next line:
#include "contactHelpers.h"
#include "contacts.h"


// This source file needs to "know about" the functions you prototyped
//         in the contact helper header file too
// HINT-1: You will want to use the new yes() and getInt() functions to help
//         simplify the data input process and reduce redundant coding
//
// HINT-2: Put the header file name in double quotes so the compiler knows
//         to look for it in the same directory/folder as this source file
//         #include your contactHelpers header file on the next line:



// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-1 |
// |        function definitions below...            |
// +-------------------------------------------------+
//
// HINT:  Update these function to use the helper 
//        functions where applicable (ex: yes() and getInt() )

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
// NOTE:  Also modify this function so the cell number is
//        mandatory (don't ask to enter the cell number)
void getNumbers(struct Numbers* numbers) {
   char option;
     printf("Please enter the contact's cell phone number: ");
     scanf("%s", numbers->cell);
   

   printf("Do you want to enter a home phone number? (y or n): ");
   option = yes();
   if (option == 1) {
      printf("Please enter the contact's home phone number: ");
      scanf("%s", numbers->home);
   }

   printf("Do you want to enter a business phone number? (y or n): ");
   option = yes();
   if (option == 1) {
      printf("Please enter the contact's business phone number: ");
      scanf("%s", numbers->business);
   }
   

}



// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-1 |
// |        empty function definitions below and     |
// |        complete the definitions as per the      |
// |        Milestone-2 specifications               | 
// +-------------------------------------------------+

// getContact
void getContact(struct Contact* contact) {
   getName(&contact->name);
   getAddress(&contact->address);
   getNumbers(&contact->numbers);
}