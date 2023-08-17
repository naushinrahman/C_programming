#include "core.h"
#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

int inputInt() {
    int enteredInt = NULL;
    int i = 0;
    char entertedChar = { '/0' };
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
    int positiveInt = NULL, i = 0;
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
    int i = 0, j, flag = 0;
    do {
        scanf(" %c", &validChar);
        for (j = 0; j < strArr[j] != '\0' && flag == 0; j++) {
            if (validChar == strArr[j]) {
                flag = 1;
            }
        }
        if (flag == 0) {
            printf("ERROR: Character must be one of [%s]: ", strArr);
            clearInputBuffer();
        }

    } while (flag == 0);

    return validChar;
}

void inputCString(char* cString, int min, int max) {
    int i = 0, j, k;
    char scannedString[100];

    while (i == 0) {
        scanf("%[^\n]", scannedString);
        for (j = 0; scannedString[j] != '\0'; j++)
            ;
        if (min == max && j != max) {
            printf("ERROR: String length must be exact %d chars: ", max);
        }
        else if (j > max) {
            clearInputBuffer();
            printf("ERROR: String length must be no more than %d chars: ", max);
        }
        else if (j < min) {
            printf("ERROR: String length must be between %d and %d chars: ", min,
                max);
        }
        else {
            for (k = 0; k < j; k++) {
                cString[k] = scannedString[k];
            }
            i = 1;
        }
    }
}

void displayFormattedPhone(const char* cString) {
    int j, k = 0;

    if (cString == NULL) {
        printf("(___)___-____");
    }
    else {
        for (j = 0; cString[j] != '\0'; j++) {
            if (cString[j] == '0' || cString[j] == '1' || cString[j] == '2' ||
                cString[j] == '3' || cString[j] == '4' || cString[j] == '5' ||
                cString[j] == '6' || cString[j] == '7' || cString[j] == '8' ||
                cString[j] == '9') {
                k++;
            }
        }
        if (k == 10 && j == 10) {
            printf("(%c%c%c)%c%c%c-%c%c%c%c", cString[0], cString[1], cString[2],
                cString[3], cString[4], cString[5], cString[6], cString[7],
                cString[8], cString[9]);
        }
        else {
            printf("(___)___-____");
        }
    }
}


// Clear the standard input buffer
void clearInputBuffer(void) {
    // Discard all remaining char's from the standard input buffer:
    while (getchar() != '\n') {
        ; // do nothing!
    }
}
