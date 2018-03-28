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

// This source file needs to "know about" the functions you prototyped
// in the contact helper header file.
// HINT: Put the header file name in double quotes so the compiler knows
//       to look for it in the same directory/folder as this source file
//       #include your contactHelpers header file on the next line:
#include "contactHelpers.h"

//------------------------------------------------------
// Function Definitions
//------------------------------------------------------

// +-------------------------------------------------+
// | ====== Assignment 2 | Milestone 2 =======       |
// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-1 |
// |        empty function definitions below and     |
// |        complete the definitions as per the      |
// |        Milestone-2 specifications               | 
// |                                                 |
// | - The clearKeyboard function is done for you    |
// +-------------------------------------------------+


// Clear the standard input buffer
void clearKeyboard(void)
{
   char getchar;
   do {
      scanf("%c", &getchar);
   }
    while (getchar != '\n')   ; // empty execution code block on purpose
}

// pause function definition goes here:
void pause(void) {
   printf("(Press Enter to continue");
   clearKeyboard();
}


// getInt function definition goes here:
int getInt(void) {
   int value;
   char newline = 'x';
   scanf("%d%c", &value, &newline);
   while (newline != '\n') {
      clearKeyboard();
      printf("*** INVALID INTEGER *** <Please enter an integer>: ");

   }
}

// getIntInRange function definition goes here:
int getIntInRange(int min, int max) {
   int value;
   getInt();
   while (value > max || value < min) {
      printf("*** OUT OF RANGE *** <Enter a number between 0 and 6>:");
      getInt();
   }
}

// yes function definition goes here:
int yes(void) {
   char ch;
   char newline = 'x';
   scanf("%c%c", &ch, &newline);
   while ((ch != 'y' && ch != 'Y' && ch != 'n' && ch != 'N') || newline != '\n') {
      if (newline != '\n') {
         clearKeyboard();
      }
      printf("*** INVALID ENTRY *** <Only (Y)es or (N)o are acceptable: ");
      scanf("%c%c", &ch, &newline);
   }
   return (ch == 'y' || ch == 'Y');
}

// menu function definition goes here:
int menu(void) {
   printf("Contact Management System\n");
   printf("-------------------------\n");
   printf("1. Display contacts\n");
   printf("2. Add a contact\n");
   printf("3. Update a contact\n");
   printf("4. Delete a contact\n");
   printf("5. Search contacts by cell phone number\n");
   printf("6. Sort contacts by cell phone number\n");
   printf("0. Exit\n");
   printf("><\n");
   printf("Select an option:>");
   getIntInRange(0, 6);
   }
   



// ContactManagerSystem function definition goes here:
void ContactManagerSystem(void) {
   menu();

}