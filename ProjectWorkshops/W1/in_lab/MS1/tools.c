#define _CRT_SECURE_NO_WARNINGS
#include "tools.h"  
#include <stdio.h>

void flushKeys(void) {
	char newline;// so the loop can start
	do {
		scanf("%c", &newline);
	} while (newline != '\n');
}
int yes(void) {
	char ch;
	char newline = 'x';
	scanf("%c%c", &ch, &newline);
	while ((ch != 'y' && ch != 'Y' && ch != 'n' && ch != 'N') || newline != '\n') {
		if (newline != '\n') {
			flushKeys();
		}
		printf("Only (y) or (n) is acceptable, redo: ");
		scanf("%c%c", &ch, &newline);
	}
	return (ch == 'y' || ch == 'Y');
}
int no(void) {
	return !yes();
}
void scanInt(int* ip) {
	int value;
	char newline = 'x';
	scanf("%d%c", &value, &newline);
	while (newline != '\n') {
		flushKeys();
		printf("Invalid integer try again: ");
		scanf("%d%c", &value, &newline);
	}
	*ip = value;

}
void scanDouble(double* dp) {
	double value;
	char newline = 'x';
	scanf("%lf%c", &value, &newline);
	while (newline != '\n') {
		flushKeys();
		printf("Invalid double try again: ");
		scanf("%lf%c", &value, &newline);
	}
	*dp = value;

}
int getInt(int min, int max, const char* prompt, const char errMes[], int showLimits) {
	int value  = 0; 
	return value; 
}
double getDouble(double min, double max, const char* prompt, const char errMes[], int showLimits, int precision) {
	double value = 0; 
	return value; 
}
