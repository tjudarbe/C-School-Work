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
#include <string.h>
#include "contacts.h"


// ----------------------------------------------------------
// define MAXCONTACTS for sizing contacts array (5):
#define MAXCONTACTS 5


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
	struct Contact contacts[MAXCONTACTS] = { { { "Rick", { "\0" }, "Grimes" },
	{ 11, "Trailer Park", 0, "A7A 2J2", "King City" },
	{ "4161112222", "4162223333", "4163334444" } },
	{
		{ "Maggie", "R.", "Greene" },
		{ 55, "Hightop House", 0, "A9A 3K3", "Bolton" },
		{ "9051112222", "9052223333", "9053334444" } },
		{
			{ "Morgan", "A.", "Jones" },
			{ 77, "Cottage Lane", 0, "C7C 9Q9", "Peterborough" },
			{ "7051112222", "7052223333", "7053334444" } },
			{
				{ "Sasha",{ "\0" }, "Williams" },
				{ 55, "Hightop House", 0, "A9A 3K3", "Bolton" },
				{ "9052223333", "9052223333", "9054445555" } },
	};
	while (!done) {
		option = menu();
		printf("\n");
		switch (option) {
		case 1:

			displayContacts(contacts, MAXCONTACTS);
			printf("\n");
			pause();
			printf("\n");
			break;
		case 2:
			addContact(contacts, MAXCONTACTS);
			printf("\n");
			pause();
			printf("\n");
			break;
		case 3:
			updateContact(&contacts, MAXCONTACTS);
			printf("\n");
			pause();
			printf("\n");
			break;
		case 4:
			deleteContact(&contacts, MAXCONTACTS);
			printf("\n");
			pause();
			printf("\n");
			break;
		case 5:
			searchContacts(contacts, MAXCONTACTS);
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
int findContactIndex(const struct Contact contact[], int size, const char cellNum[]){

	int i;
	
	for (i = 0; i < size; i++) {
		if (strcmp(contact->numbers.cell, cellNum) == 0) {
			return i;

		}
		else {
			contact++;
		}
	}
	return -1;
}

// displayContactHeader
void displayContactHeader(void) {
	printf("+-----------------------------------------------------------------------------+\n");
	printf("|                              Contacts Listing                               |\n");
	printf("+-----------------------------------------------------------------------------+\n");
}

// displayContactFooter
void displayContactFooter(int numContacts) {
	printf("+-----------------------------------------------------------------------------+\n");
	printf("Total Contacts: %d", numContacts);
	printf("\n");
	printf("\n");
}


// displayContact:
void displayContact(const struct Contact*contact) {

	printf(" %s", contact->name.firstName);
	printf(" %s", contact->name.middleInitial);
	printf(" %s", contact->name.lastName);
	printf("\n");
	printf("    C: %-10s    H: %-10s    B: %-10s\n", contact->numbers.cell, contact->numbers.home,
													contact->numbers.business);
	printf("       %d %s,", contact->address.streetNumber, contact->address.street);
	if (contact->address.apartmentNumber) {
		printf("Apt# %d, ", contact->address.apartmentNumber);
													

	}

		printf("       %s %s\n", contact->address.city, contact->address.postalCode);

	
}



// displayContacts:

void displayContacts(const struct Contact contacts[], int size) {
	
	int i;
	int numContacts = 0;
	displayContactHeader();
	for (i = 0; i < size; i++) {
		if (strlen(&contacts[i]) != 0) {
			displayContact(&contacts[i]);
			numContacts ++;
		}

	}
	displayContactFooter(numContacts);
}

// searchContacts:
void searchContacts(const struct Contact search[], int size) {
	int find;
	char number[11];
	
	printf("Enter the cell number for the contact: ");
	getTenDigitPhone(number);
	find = findContactIndex(search, size, number);
	if (find != -1) {
		displayContact(&search[find]);
	}
	else {
		printf("*** CONTACT NOT FOUND ***");
	}
}

// addContact:
void addContact(struct Contact contact[], int size) {
	int i;
	for (i = 0; i <= size; i++) {
		if (strlen(contact[i].numbers.cell) == 0) {
			getContact(&contact[i]);
			printf("--- New Contact added! ---\n");
			break;
		}
		 else if (i == size) {
			printf("*** ERROR: The contact list is full! ***");
			
		}
		 
	}
}

// updateContact:
void updateContact(struct Contact contact[], int size) {
	int search;
	char number[11];
	char option;
	printf("Enter the cell number for the contact: ");
	getTenDigitPhone(number);
	search = findContactIndex(contact, size, number);
	if (search != -1) {
		printf("\n");
		printf("Contact found:");
		printf("\n");
		displayContact(&contact[search]);
		printf("\n"); 
		printf("Do you want to update the name? (y or n): ");
		scanf(" %c", &option);
		option = yes();
		if (option == 1) {
			getName(&contact[search]);
		}
		printf("Do you want to update the address? (y or n): ");
		scanf(" %c", &option);
		option = yes();
		if (option == 1) {
			getAddress(&contact[search]);
		}
		printf("Do you want to update the numbers? (y or n): ");
		scanf(" %c", &option);
		option = yes();
		if (option == 1) {
			getNumbers(&contact[search]);
		}
		printf("--- Contact Updated! ---\n");
	}
	else {
		printf("*** Contact NOT FOUND ***\n");
	}
}

// deleteContact:
void deleteContact(struct Contact contact[], int size) {
	char number[11];
	int delete;
	char option; 
	
	printf("Enter the cell number for the contact: ");
	getTenDigitPhone(number);
	delete = findContactIndex(contact, size, number);
	if (delete != -1) {
		printf("\n");
		printf("Contact found:");
		printf("\n");
		displayContact(&contact[delete]);
		printf("\n");
		printf("CONFIRM: Delete this contact? (y or n): ");
		option = yes();
		if (option == 1) {
			strcpy((&contact[delete]), "\0");
		}
		printf("--- Contact deleted! ---");
	}
		else {
			printf("*** Contact NOT FOUND ***");
		}
	}


// sortContacts: