#ifndef CORE_H
#define CORE_H

//////////////////////////////////////
// USER INTERFACE FUNCTIONS
//////////////////////////////////////

// Clear the standard input buffer
void clearInputBuffer(void);

// Wait for user to input the "enter" key to continue
void suspend(void);

void displayFormattedPhone(const char* cString);

//////////////////////////////////////
// USER INPUT FUNCTIONS
//////////////////////////////////////

int inputInt();

int inputIntPositive();

int inputIntRange(int lowerBound, int upperBound);

char inputCharOption(const char strArr[]);

void inputCString(char* cString, int min, int max);


#endif // !CORE_H

