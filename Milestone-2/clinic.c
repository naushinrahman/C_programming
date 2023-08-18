/*/////////////////////////////////////////////////////////////////////////
						Assignment 1 - Milestone 2
Full Name  : Naushin Rahman
Student ID#: 144079225
Email      : nrahman30@myseneca.ca
Section    : NDD

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

// include the user library "core" so we can use those functions
#include "core.h"
// include the user library "clinic" where the function prototypes are declared
#include "clinic.h"
#include <string.h>


//////////////////////////////////////
// DISPLAY FUNCTIONS
//////////////////////////////////////

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Display's the patient table header (table format)
void displayPatientTableHeader(void)
{
	printf("Pat.# Name            Phone#\n"
		"----- --------------- --------------------\n");
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Displays a single patient record in FMT_FORM | FMT_TABLE format
void displayPatientData(const struct Patient* patient, int fmt)
{
	if (fmt == FMT_FORM)
	{
		printf("Name  : %s\n"
			"Number: %05d\n"
			"Phone : ", patient->name, patient->patientNumber);
		displayFormattedPhone(patient->phone.number);
		printf(" (%s)\n", patient->phone.description);
	}
	else
	{
		printf("%05d %-15s ", patient->patientNumber,
			patient->name);
		displayFormattedPhone(patient->phone.number);
		printf(" (%s)\n", patient->phone.description);
	}
}

//////////////////////////////////////
// MENU & ITEM SELECTION FUNCTIONS
//////////////////////////////////////

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// main menu
void menuMain(struct ClinicData* data)
{
	int selection;

	do {
		printf("Veterinary Clinic System\n"
			"=========================\n"
			"1) PATIENT     Management\n"
			"2) APPOINTMENT Management\n"
			"-------------------------\n"
			"0) Exit System\n"
			"-------------------------\n"
			"Selection: ");
		selection = inputIntRange(0, 2);
		putchar('\n');
		switch (selection)
		{
		case 0:
			printf("Are you sure you want to exit? (y|n): ");
			selection = !(inputCharOption("yn") == 'y');
			putchar('\n');
			if (!selection)
			{
				printf("Exiting system... Goodbye.\n\n");
			}
			break;
		case 1:
			menuPatient(data->patients, data->maxPatient);
			break;
		case 2:
			printf("<<< Feature not yet available >>>\n\n");
			break;
		}
	} while (selection);
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Menu: Patient Management
void menuPatient(struct Patient patient[], int max)
{
	int selection;

	do {
		printf("Patient Management\n"
			"=========================\n"
			"1) VIEW   Patient Data\n"
			"2) SEARCH Patients\n"
			"3) ADD    Patient\n"
			"4) EDIT   Patient\n"
			"5) REMOVE Patient\n"
			"-------------------------\n"
			"0) Previous menu\n"
			"-------------------------\n"
			"Selection: ");
		selection = inputIntRange(0, 5);
		putchar('\n');
		switch (selection)
		{
		case 1:
			displayAllPatients(patient, max, FMT_TABLE);
			suspend();
			break;
		case 2:
			searchPatientData(patient, max);
			break;
		case 3:
			addPatient(patient, max);
			suspend();
			break;
		case 4:
			editPatient(patient, max);
			break;
		case 5:
			removePatient(patient, max);
			suspend();
			break;
		}
	} while (selection);
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Menu: Patient edit
void menuPatientEdit(struct Patient* patient)
{
	int selection;

	do {
		printf("Edit Patient (%05d)\n"
			"=========================\n"
			"1) NAME : %s\n"
			"2) PHONE: ", patient->patientNumber, patient->name);

		displayFormattedPhone(patient->phone.number);

		printf("\n"
			"-------------------------\n"
			"0) Previous menu\n"
			"-------------------------\n"
			"Selection: ");
		selection = inputIntRange(0, 2);
		putchar('\n');

		if (selection == 1)
		{
			printf("Name  : ");
			inputCString(patient->name, 1, NAME_LEN);
			putchar('\n');
			printf("Patient record updated!\n\n");
		}
		else if (selection == 2)
		{
			inputPhoneData(&patient->phone);
			printf("Patient record updated!\n\n");
		}

	} while (selection);
}


// ---------------------------------------------------------------------------
// !!! Put all the remaining function definitions below !!!
// Note: Maintain the same order/sequence as it is listed in the header file
// ---------------------------------------------------------------------------

// Display's all patient data in the FMT_FORM | FMT_TABLE format
void displayAllPatients(const struct Patient patient[], int max, int fmt)
{
	int i = 0, j;
	for (i = 0; i < max; i++)
	{
		if (patient[i].patientNumber == 0 && i == max)
		{
			printf("*** No records found ***");
		}
	}
	if (i == max)
	{
		displayPatientTableHeader();
		for (j = 0; j < max; j++)
		{
			if (patient[j].patientNumber != 0)
			{
				displayPatientData(&patient[j], FMT_TABLE);
			}
		}
	}
	putchar('\n');
}


// Search for a patient record based on patient number or phone number
void searchPatientData(const struct Patient patient[], int max)
{
	int selection;
	do {
		printf("Search Options\n");
		printf("==========================\n");
		printf("1) By patient number\n");
		printf("2) By phone number\n");
		printf("..........................\n");
		printf("0) Previous menu\n");
		printf("..........................\n");
		printf("Selection: ");
		selection = inputIntRange(0, 2);
		putchar('\n');
		if (selection == 1)
		{
			searchPatientByPatientNumber(patient, max);
			clearInputBuffer();
			suspend();
		}
		else if (selection == 2)
		{
			searchPatientByPhoneNumber(patient, max);
			clearInputBuffer();
			suspend();
		}
	} while (selection == 1 || selection == 2);
}


// Add a new patient record to the patient array
void addPatient(struct Patient patient[], int max)
{
	int i, newPtNum;
	newPtNum = nextPatientNumber(patient, max);
	for (i = 0; (i < max && patient[i].patientNumber != 0); i++);
	if (i < max)
	{
		patient[i].patientNumber = newPtNum;
		inputPatient(&patient[i]);
		/*fix
		if (patient[6].patientNumber < 0) {
			patient[6].patientNumber = 0;
		}*/
		
		printf("\n*** New patient record added ***\n\n");
	}
	else
	{
		printf("ERROR: Patient listing is FULL!\n\n");
	}
}


// Edit a patient record from the patient array
void editPatient(struct Patient patient[], int max)
{
	int ptNum, locatedIndex;
	printf("Enter the patient number: ");
	scanf("%d", &ptNum);
	locatedIndex = findPatientIndexByPatientNum(ptNum, patient, max);
	if (locatedIndex != -1)
	{
		// need ampersand because menupatientedit() takes a ptr and is looking for an address
		//patient[locatedIndex] is just giving the value it is not an address
		menuPatientEdit(&patient[locatedIndex]);
	}
	else
	{
		printf("ERROR: Patient record not found!\n");
	}
}


// Remove a patient record from the patient array
void removePatient(struct Patient patient[], int max)
{
	int ptNum, locatedIndex;
	char confRemove;
	printf("Enter the patient number: ");
	scanf("%d", &ptNum);
	locatedIndex = findPatientIndexByPatientNum(ptNum, patient, max);
	if (locatedIndex != -1)
	{
		displayPatientData(&patient[locatedIndex], FMT_FORM);
		printf("\nAre you sure you want to remove this patient record? (y/n): ");
		scanf(" %c", &confRemove);
		clearInputBuffer();
		if (confRemove == 'y')
		{
			patient[locatedIndex].patientNumber = 0;
			printf("\nPatient record has been removed!\n\n");
		}
		else
		{
			printf("\nOperation aborted.\n\n");
		}
	}
	else
	{
		clearInputBuffer();
		printf("\nERROR: Patient record not found!\n\n");
	}
}



//////////////////////////////////////
// UTILITY FUNCTIONS
//////////////////////////////////////

// Search and display patient record by patient number (form)
void searchPatientByPatientNumber(const struct Patient patient[], int max)
{
	int patientNum, returnedIndex;
	printf("Search by patient number: ");
	scanf("%d", &patientNum);
	returnedIndex = findPatientIndexByPatientNum(patientNum, patient, max);
	if (patient[returnedIndex].patientNumber == patientNum)
	{
		displayPatientData(&patient[returnedIndex], FMT_FORM);
	}
	else
	{
		printf("\n*** No records found ***\n");
	}
	putchar('\n');

}


// Search and display patient records by phone number (tabular)
void searchPatientByPhoneNumber(const struct Patient patient[], int max)
{
	int i, j = 0, result;
	char phoneNum[PHONE_LEN + 1];
	printf("Search by phone number: ");
	scanf("%s", phoneNum);
	putchar('\n');
	displayPatientTableHeader();
	for (i = 0; i < max; i++)
	{
		result = strcmp(patient[i].phone.number, phoneNum);
		if (result == 0)
		{
			displayPatientData(&patient[i], FMT_TABLE);
			j++;
		}
	}
	putchar('\n');
	if (j == 0)
	{
		printf("*** No records found ***\n\n");
	}
}


// Get the next highest patient number
int nextPatientNumber(const struct Patient patient[], int max)
{
	int i, nextNum;
	nextNum = 0;
	for (i = 0; i < max; i++)
	{
		if (patient[i].patientNumber > nextNum)
		{
			nextNum = patient[i].patientNumber;
		}
	}
	nextNum += 1;
	return nextNum;
}


// Find the patient array index by patient number (returns -1 if not found)
int findPatientIndexByPatientNum(int patientNumber,
	const struct Patient patient[], int max)
{
	int i, flag = 0, index = 0;
	for (i = 0; i < max && flag == 0; i++)
	{
		if (patient[i].patientNumber == patientNumber)
		{
			flag = 1;
			index = i;
		}
	}
	if (flag == 0)
	{
		index = -1;
	}
	return index;
}



//////////////////////////////////////
// USER INPUT FUNCTIONS
//////////////////////////////////////

// Get user input for a new patient record
void inputPatient(struct Patient* patient)
{
	char ptName[NAME_LEN + 1];
	printf("Patient Data Input\n");
	printf("------------------\n");
	printf("Number: %05d\n", patient->patientNumber);
	printf("Name  : ");
	scanf("%[^\n]", ptName);
	strcpy(patient->name, ptName);
	putchar('\n');
	inputPhoneData(&patient->phone);
}


// Get user input for phone contact information
void inputPhoneData(struct Phone* phone)
{
	int selection;
	char phoneDesc[PHONE_DESC_LEN + 1] = { '\0' };
	char phoneNum[PHONE_LEN + 1];

	printf("Phone Information\n");
	printf("-----------------\n");
	printf("How will the patient like to be contacted?\n");
	printf("1. Cell\n");
	printf("2. Home\n");
	printf("3. Work\n");
	printf("4. TBD\n");
	printf("Selection: ");
	selection = inputIntRange(1, 4);
	switch (selection)
	{
	case 1:
		strcpy(phoneDesc, "CELL");
		printf("\nContact: CELL\n");
		printf("Number : ");
		inputCString(phoneNum, PHONE_LEN, PHONE_LEN);
		break;
	case 2:
		strcpy(phoneDesc, "HOME");
		printf("\nContact: HOME\n");
		printf("Number : ");
		inputCString(phoneNum, PHONE_LEN, PHONE_LEN);
		break;
	case 3:
		strcpy(phoneDesc, "WORK");
		printf("\nContact: WORK\n");
		printf("Number : ");
		inputCString(phoneNum, PHONE_LEN, PHONE_LEN);
		break;
	case 4:
		strcpy(phoneDesc, "TBD");
		break;
	}
	//
	strcpy(phone->description, phoneDesc);
	if (strcmp(phoneDesc, "TBD") != 0)
    {
		strcpy(phone->number, phoneNum);
	}
}
