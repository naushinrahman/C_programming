/*/////////////////////////////////////////////////////////////////////////
						Assignment 1 - Milestone 2
Full Name  : Naushin Rahman
Student ID#: 144079225
Email      : nrahman30@myseneca.ca
Section    : NDD
9678
Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "core.h"
#include <string.h>

//
// Copy your work done from Milestone #1 (core.c) into this file
// - Organize your functions in the same order as they are listed in the core.h file
// - Also copy the commented "sections" to help with finding functions quickly!
//


int inputInt() {
	int enteredInt = 0;
	int i = 0;
	char entertedChar;
	while (i == 0) {
		scanf("%d%c", &enteredInt, &entertedChar);
		if (entertedChar != '\n') {
			printf("Error! Input a whole number: ");
			clearInputBuffer();
		}
		else {
			i = 1;
		}
	}
	return enteredInt;
}

int inputIntPositive() {
	int positiveInt = 0, i = 0;
	while (i == 0) {
		scanf("%d", &positiveInt);
		if (positiveInt <= 0) {
			printf("ERROR! Value must be > 0: ");
		}
		else {
			i = 1;
		}
	}
	return positiveInt;
}

int inputIntRange(int lowerBound, int upperBound) {
	int checkInt;
	do {
		checkInt = inputInt();
		if (checkInt < lowerBound || checkInt > upperBound) {
			printf("ERROR! Value must be between %d and %d inclusive: ", lowerBound,
				upperBound);
		}

	} while (checkInt < lowerBound || checkInt > upperBound);

	return checkInt;
}

char inputCharOption(const char strArr[]) {
	char validChar;
	int j, flag = 0;
	do {
		scanf(" %c", &validChar);
		for (j = 0; j < strlen(strArr) && flag == 0; j++) {
			if (validChar == strArr[j]) {
				flag = 1;
			}
		}
		if (flag == 0) {
			printf("ERROR: Character must be one of [%s]: ", strArr);
		}
		clearInputBuffer();
	} while (flag == 0);

	return validChar;
}

void inputCString(char* cString, int min, int max) {
	int i = 0, j;
	char scannedString[100];

	while (i == 0) {
		scanf("%[^\n]", scannedString);
		clearInputBuffer();
		j = strlen(scannedString);
		if (min == max && j != max)
		{
			printf("ERROR: String length must be exactly %d chars: ", max);
		}
		else if (j > max) {

			printf("ERROR: String length must be no more than %d chars: ", max);
		}
		else if (j < min) {
			printf("ERROR: String length must be between %d and %d chars: ", min,
				max);
		}
		else
		{
			strcpy(cString, scannedString);
			i = 1;
		}
	}
}

void displayFormattedPhone(const char* cString) {
	int j, k = 0;
	if (cString == NULL)
	{
		printf("(___)___-____");
	}
	else
	{
		for (j = 0; j < strlen(cString); j++)
		{
			if (cString[j] == '0' || cString[j] == '1' || cString[j] == '2' ||
				cString[j] == '3' || cString[j] == '4' || cString[j] == '5' ||
				cString[j] == '6' || cString[j] == '7' || cString[j] == '8' ||
				cString[j] == '9') {
				k++;
			}
		}
		if (k == 10 && j == 10)
		{
			printf("(%c%c%c)%c%c%c-%c%c%c%c", cString[0], cString[1], cString[2],
				cString[3], cString[4], cString[5], cString[6], cString[7],
				cString[8], cString[9]);
		}
		else
		{
			printf("(___)___-____");
		}
	}
}

// As demonstrated in the course notes:
// https://intro2c.sdds.ca/D-Modularity/input-functions#clearing-the-buffer
// Clear the standard input buffer
void clearInputBuffer(void)
{
	// Discard all remaining char's from the standard input buffer:
	while (getchar() != '\n')
	{
		; // do nothing!
	}
}
// Wait for user to input the "enter" key to continue
void suspend(void)
{
	printf("<ENTER> to continue...");
	clearInputBuffer();
	putchar('\n');
}