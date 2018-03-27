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

// Structure type Name declaration
struct Name {
   char firstName[31];
   char middleInitial[7];
   char lastName[36];
};

struct Address {
   int streetNumber;
   char street[41];
   int apartmentNumber;
   char postalCode[8];
   char city[41];

};

struct Numbers {
   char cell[21];
   char home[21];
   char business[21];
};
