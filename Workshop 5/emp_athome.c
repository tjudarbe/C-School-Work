/*
Name:
Student number :
Email:
Workshop:
Section:
Date:
*/

// Copy your source code from in_lab file to here
// Expand the option list to include option 3 & 4 after 
// option 2. as following
// "3. Update Employee Salary"
// "4. Remove Employee"

// Create two switch-cases for option 3 & 4 after case 2. 
// Implement "Update Salary" and "Remove Employee" 
// functionality as per instructions
// inside the relevant case statements
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

// Define Number of Employees "SIZE" to be 2
#define SIZE 4

// Declare Struct Employee 
struct Employee {
   int id;
   int age;
   double salary;
};

/* main program */
int main(void) {

   int option = 0;
   int empId;
   int numEmployees = 0;
   double newSalary;
   int flag; 
   int i;

   printf("---=== EMPLOYEE DATA ===---\n\n");

   // Declare a struct Employee array "emp" with SIZE elements 
   // and initialize all elements to zero

   struct Employee emp[SIZE] = { 0 };
   do {

      // Print the option list
      printf("1. Display Employee Information\n");
      printf("2. Add Employee\n");
      printf("3. Update Employee Salary\n");
      printf("4. Remove Employee\n");
      printf("0. Exit\n\n");
      printf("Please select from the above options: ");

      // Capture input to option variable
      scanf("%d", &option);
      printf("\n");

      switch (option) {
      case 0: // Exit the program

         break;
      case 1: // Display Employee Data
              // @IN-LAB

         printf("EMP ID  EMP AGE EMP SALARY\n");
         printf("======  ======= ==========\n");
         if (numEmployees > 0) {
            for (i = 0; i < SIZE; i++) {
               printf("%6d%9d%11.2lf\n", emp[i].id, emp[i].age, emp[i].salary);

            }
         }
         printf("\n");
         break;
      
      case 2: // Adding Employee
              // @IN-LAB

         printf("Adding Employee\n");
         printf("===============\n");
         if (numEmployees < SIZE) {
            printf("Enter Employee ID: ");
            scanf("%d", &emp[numEmployees].id);
            printf("Enter Employee Age: ");
            scanf("%d", &emp[numEmployees].age);
            printf("Enter Employee Salary: ");
            scanf("%lf", &emp[numEmployees].salary);
            numEmployees += 1;

         }
         else {
            printf("Maximum Number of Employees Reached\n");
         }
         printf("\n");

         break;
      case 3:

         printf("Update Information\n");
         printf("===================\n");
         do {
            printf("Enter Employee ID: ");
            scanf("%d", &empId);

            for (i = 0; i < SIZE; i++) {
               if (empId == emp[i].id) {
                  printf("The Current Salary is:%.2lf\n", emp[i].salary);
                  printf("Enter New Salary: ");
                  scanf("%lf ", &newSalary);
                  emp[i].salary = newSalary;
                  
               }
            }
            printf("\n");
         } while (empId == emp[i].id);
         break;
     
      
      case 4:
         printf("Remove Employee\n");
         printf("===============\n");
         do {
            printf("Enter Employee ID: ");
            scanf("%d", &empId);

            for (i = 0; i < SIZE; i++) {
               if (empId == emp[i].id) {
                  printf("Employee %d will be removed\n", emp[i].id);
                  emp[i].id = 0;
                  numEmployees -= 1;
                  
               }

            }
            printf("\n");

         } while (empId == emp[i].id);
        
         break;
        
   
      
      default:
         printf("ERROR: Incorrect Option: Try Again\n\n");
      }

   } while (option != 0);


   return 0;
}







