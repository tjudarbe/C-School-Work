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

// This source file needs to "know about" the SYSTEM string library functions.
// HINT: The library name is string.h.
//       #include the string.h header file on the next line:

#include <string.h>

// ----------------------------------------------------------
// Include your contactHelpers header file on the next line:
#include "contactHelpers.h"


//------------------------------------------------------
// Function Definitions
//------------------------------------------------------

// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-2 |
// |        function definitions below...            |
// +-------------------------------------------------+

// clearKeyboard:
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
// | ====== Assignment 2 | Milestone 3 =======       |
// +-------------------------------------------------+
// | Put empty function definitions below...         |
// +-------------------------------------------------+

// Generic function to get a ten-digit phone number (ensures 10 chars entered)
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

// findContactIndex:
int findContactIndex(const struct Contact contacts[], int size, const char cellNum[])
{

    return -1;
}


// displayContactHeader
// Put empty function definition below:



// displayContactFooter
// Put empty function definition below:



// displayContact:
// Put empty function definition below:



// displayContacts:
// Put empty function definition below:



// searchContacts:
// Put empty function definition below:



// addContact:
// Put empty function definition below:



// updateContact:
// Put empty function definition below:



// deleteContact:
// Put empty function definition below:



// sortContacts:
// Put empty function definition below:
