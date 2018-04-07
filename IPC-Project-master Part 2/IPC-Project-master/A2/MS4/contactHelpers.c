/* -------------------------------------------
Name:           
Student number: 
Email:          
Section:        
Date:           
----------------------------------------------
Assignment: 2
Milestone:  4
---------------------------------------------- */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

// This source file needs to "know about" the SYSTEM string library functions.
// HINT: The library name is string.h.
//       #include the string.h header file on the next line:
#include <string.h>

// ----------------------------------------------------------
// Include your contactHelpers header file on the next line:
#include "contactHelpers.h"
#include "contacts.h"
#include <string.h>


// ----------------------------------------------------------
// define MAXCONTACTS for sizing contacts array (5):
#define MAXCONTACTS 5;


//------------------------------------------------------
// Function Definitions
//------------------------------------------------------

// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-3 |
// |        function definitions below...            |
// +-------------------------------------------------+

// clearKeyboard
void clearKeyboard(void)
{
   char getchar;
   do {
      scanf("%c", &getchar);
   } while (getchar != '\n'); // empty execution code block on purpose
}

// pause:
void pause(void) {
   printf("(Press Enter to Continue)");
   clearKeyboard();
}

// getInt:
int getInt(void) {
   int value;
   char newline = 'x';
   scanf("%d%c", &value, &newline);
   while (newline != '\n') {
      clearKeyboard();
      printf("*** INVALID INTEGER *** <Please enter an integer>: ");
      scanf("%d%c", &value, &newline);
   }
   return value;
}

// getIntInRange:
int getIntInRange(int min, int max) {
   int value;
   value = getInt();
   while (value > max || value < min) {
      printf("*** OUT OF RANGE *** <Enter a number between %d and %d>: ", min, max);
      value = getInt();
   }
   return value;
}


// yes:
int yes(void) {
   char ch;
   char newline = 'x';
   scanf(" %c%c", &ch, &newline);
   while ((ch != 'y' && ch != 'Y' && ch != 'n' && ch != 'N') || newline != '\n') {
      if (newline != '\n') {
         clearKeyboard();
      }
      printf("*** INVALID ENTRY *** <Only (Y)es or (N)o are acceptable>: ");
      scanf(" %c%c", &ch, &newline);
   }
   return (ch == 'y' || ch == 'Y');
}

// menu:
int menu(void) {
   int value;
   printf("Contact Management System\n");
   printf("-------------------------\n");
   printf("1. Display contacts\n");
   printf("2. Add a contact\n");
   printf("3. Update a contact\n");
   printf("4. Delete a contact\n");
   printf("5. Search contacts by cell phone number\n");
   printf("6. Sort contacts by cell phone number\n");
   printf("0. Exit\n");
   printf("\n");
   printf("Select an option:> ");
   value = getIntInRange(0, 6);
   return value;
}

// ContactManagerSystem:
void ContactManagerSystem(void) {
   int option;
   int done = 0;

   while (!done) {
      option = menu();
      printf("\n");
      switch (option) {
      case 1:
         printf("<<< Feature 1 is unavailable >>>\n");
         printf("\n");
         pause();
         printf("\n");
         break;
      case 2:
         printf("<<< Feature 2 is unavailable >>>\n");
         printf("\n");
         pause();
         printf("\n");
         break;
      case 3:
         printf("<<< Feature 3 is unavailable >>>\n");
         printf("\n");
         pause();
         printf("\n");
         break;
      case 4:
         printf("<<< Feature 4 is unavailable >>>\n");
         printf("\n");
         pause();
         printf("\n");
         break;
      case 5:
         printf("<<< Feature 5 is unavailable >>>\n");
         printf("\n");
         pause();
         printf("\n");
         break;

      case 6:
         printf("<<< Feature 6 is unavailable >>>\n");
         printf("\n");
         pause();
         printf("\n");
         break;
      default:
         printf("Exit the program? (Y)es/(N)o: ");
         if (yes() == 1) {
            printf("\nContact Management System: terminated");
            done = 1;

         }
         printf("\n");
      }
   }

}

// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-3 |
// |        empty function definitions below...      |
// +-------------------------------------------------+

// getTenDigitPhone:
void getTenDigitPhone(char telNum[])
{
   int needInput = 1; //flag 

   while (needInput == 1) {
      scanf("%10s", telNum);
      clearKeyboard();

      // (String Length Function: validate entry of 10 characters)
      if (strlen(telNum) == 10)
         needInput = 0;
      else
         printf("Enter a 10-digit phone number: ");
   }
}

// findContactIndex
int findContactIndex(const struct Contact contacts[], int size, const char cellNum[])
{
   int i;
   int foundIndex = -1;
   for (i = 0; foundIndex == -1 && i < size; i++) {
      if (strstr(contacts[i].numbers, cellNum[i])) {
         foundIndex = i;

      }
   }
   return foundIndex;
}


// displayContactHeader
void displayContactHeader(void) {
   printf("+-----------------------------------------------------------------------------+\n");
   printf("|                              Contacts Listing                              |\n");
}

// displayContactFooter
void displayContactFooter(int numContacts) {
   printf("+-----------------------------------------------------------------------------+\n");
   printf("Total Contacts: %d", numContacts);
   printf('\n');
   printf('\n');
}


// displayContact:
void displayContact(const struct Contact*contacts) {
   printf("%s", contacts->name);
   printf('\n');
   printf("    C: %-10s    H: %-10s    B: %-10s\n", contacts->numbers->cell, contacts->numbers->home, 
                                                    contacts->numbers->business);
   if (contacts->address.apartmentNumber > 0) {
      printf("       %d %s, Apt# %d, %s, %s\n", contacts->address.streetNumber, contacts->address.street,
         contacts->address.apartmentNumber, contacts->address.city, contacts->address.postalCode);
         
   }
   else {
      printf("       %d %s, %s, %s\n", contacts->address.streetNumber, contacts->address.street,
                                       contacts->address.city, contacts->address.postalCode);
                                            
      }
   }


// displayContacts:
void displayContacts(const struct Contact contacts[], int size) {
   displayContactHeader();
   int i = 0;
   for (i = 0; i < size; i++) {
      if(contacts->numbers->cell[i] > 0){
         displayContact();
      }
   }
}

// searchContacts:


// addContact:


// updateContact:


// deleteContact:


// sortContacts:
