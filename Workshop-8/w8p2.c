/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #8 (P2)
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


// System Libraries
#include <stdio.h>

// User Libraries
#include "w8p2.h"

// ----------------------------------------------------------------------------
// PART-1

// 1. Get user input of int type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
int getIntPositive(int* intaddress)
{
    int i = 0, posIntValue;

    while (i == 0)
    {
        scanf("%d", &posIntValue);
        if (posIntValue <= 0)
        {
            printf("ERROR: Enter a positive value: ");
        }
        else
        {
            i = 1;
        }
    }
    if (intaddress != NULL)
    {
        *intaddress = posIntValue;
    }
    return posIntValue;
}

// 2. Get user input of double type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
double getDoublePositive(double* doubaddress)
{
    int i = 0;
    double posDubValue;
    while (i == 0)
    {
        scanf("%lf", &posDubValue);
        if (posDubValue <= 0)
        {
            printf("ERROR: Enter a positive value: ");
        }
        else
        {
            i = 1;
        }
    }
    if (doubaddress != NULL)
    {
        *doubaddress = posDubValue;
    }
    return posDubValue;
}


// 3. Opening Message (include the number of products that need entering)
void openingMessage(const int numOfProd)
{
    printf("Cat Food Cost Analysis\n");
    printf("======================\n\n");
    printf("Enter the details for %d dry food bags of product data for analysis.\n", MAX_NUM_OF_PROD);
    printf("NOTE: A 'serving' is %dg\n", GRAMS_IN_SERVING);
}

// 4. Get user input for the details of cat food product
struct CatFoodInfo getCatFoodInfo(const int prodSequence)
{
    int SKU, calServing;
    double prodWeight, prodPrice;

    printf("\nCat Food Product #%d\n", prodSequence + 1);
    printf("--------------------\n");
    printf("SKU           : ");
    SKU = getIntPositive(&SKU);
    printf("PRICE         : $");
    prodPrice = getDoublePositive(&prodPrice);
    printf("WEIGHT (LBS)  : ");
    prodWeight = getDoublePositive(&prodWeight);
    printf("CALORIES/SERV.: ");
    calServing = getIntPositive(&calServing);

    struct CatFoodInfo Prod =
    {
        SKU, prodPrice, prodWeight, calServing,
    };

    return Prod;
}

// 5. Display the formatted table header
void displayCatFoodHeader(void)
{
    printf("SKU         $Price    Bag-lbs Cal/Serv\n");
    printf("------- ---------- ---------- --------\n");
}

// 6. Display a formatted record of cat food data
void displaysCatFoodData(const struct CatFoodInfo Prod[])
{
    int i;
    for (i = 0; i < MAX_NUM_OF_PROD; i++)
    {
        printf("%07d %10.2lf %10.1lf %8d\n", Prod[i].SKU, Prod[i].prodPrice, Prod[i].prodWeight, Prod[i].calServing);
    }
}

// ----------------------------------------------------------------------------
// PART-2

// 8. convert lbs: kg (divide by 2.20462)
double convertLbsKg(const double* lbs, double* kg)
{
    double kilos;

    kilos = (*lbs / CONVERSION_TO_KG);
    if (kg != NULL)
    {
        *kg = kilos;
    }

    return kilos;
}

// 9. convert lbs: g (call convertKG, then * 1000)
int convertLbsG(const double* lbs, int* g)
{
    int grams;
    double kG;
    grams = (convertLbsKg(lbs, &kG) * 1000);
    if (g != NULL)
    {
        *g = grams;
    }

    return grams;
}

// 10. convert lbs: kg and g
void convertLbs(const double* lbs, double* kg, int* g)
{
    convertLbsKg(lbs, kg);
    convertLbsG(lbs, g);
}

// 11. calculate: servings based on gPerServ
double calculateServings(const int servingG, const int totalG, double* numOfServing)
{
    double serving = 0;
    int totalGrams = totalG;
    serving = (double)totalGrams/(double)servingG;

    if (numOfServing != NULL)
    {
        *numOfServing = serving;
    }

    return serving;
}

// 12. calculate: cost per serving
double calculateCostPerServing(const double* prodPrice, const double* numOfServing, double* costPerServing)
{
    double costServing = 0;
    costServing = *prodPrice / *numOfServing;

    if (costPerServing != NULL)
    {
        *costPerServing = costServing;
    }

    return costServing;
}

// 13. calculate: cost per calorie
double calculateCostPerCal(const double* prodPrice, const double* totalCal, double* costPerCal)
{
    double costPerCalorie;
    costPerCalorie = *prodPrice / *totalCal;

    if (costPerCal != NULL)
    {
        *costPerCal = costPerCalorie;
    }
    return costPerCalorie;
}

// 14. Derive a reporting detail record based on the cat food product data
struct ReportData calculateReportData(const struct CatFoodInfo prod)
{
    struct ReportData report1;
    double totalCal;
   
    report1.SKU = prod.SKU;
    report1.prodPrice = prod.prodPrice;
    report1.weightLbs = prod.prodWeight;
    report1.calServing = prod.calServing;

    convertLbsKg(&report1.weightLbs, &report1.weightKg);
    convertLbsG(&report1.weightLbs, &report1.weightG);
    calculateServings(GRAMS_IN_SERVING, report1.weightG, &report1.totalServing);
    totalCal = report1.calServing * report1.totalServing;
    calculateCostPerServing(&report1.prodPrice, &report1.totalServing, &report1.costServing);
    calculateCostPerCal(&report1.prodPrice, &totalCal, &report1.costCalServing);

    return report1;
}

// 15. Display the formatted table header for the analysis results
void displayReportHeader(void)
{
    printf("\nAnalysis Report (Note: Serving = %dg)\n", GRAMS_IN_SERVING);
    printf("---------------\n");
    printf("SKU         $Price    Bag-lbs     Bag-kg     Bag-g Cal/Serv Servings  $/Serv   $/Cal\n");
    printf("------- ---------- ---------- ---------- --------- -------- -------- ------- -------\n");
}

// 16. Display the formatted data row in the analysis table
void displayReportData(const struct ReportData report, const int cheapest)
{
  printf("%07d %10.2lf %10.1lf %10.4lf %9d %8d %8.1lf %7.2lf %7.5lf", report.SKU, report.prodPrice, report.weightLbs, 
      report.weightKg, report.weightG, report.calServing, report.totalServing, report.costServing, report.costCalServing);

  if (cheapest == 1) 
  {
      printf(" ***");
  }
  putchar('\n');
}

// 17. Display the findings (cheapest)
void displayFinalAnalysis(const struct CatFoodInfo Prod)
{
    printf("\nFinal Analysis\n");
    printf("--------------\n");
    printf("Based on the comparison data, the PURRR-fect economical option is:\n");
    printf("SKU:%07d Price: $%5.2lf\n\n", Prod.SKU, Prod.prodPrice);

    printf("Happy shopping!\n\n");
}

// ----------------------------------------------------------------------------

// 7. Logic entry point
void start(void)
{
    struct CatFoodInfo Prod[MAX_NUM_OF_PROD] = { {0} };
    struct ReportData report[MAX_NUM_OF_PROD] = { { 0 } };

    int i, j, cheapest;
    double minimum;
    openingMessage(MAX_NUM_OF_PROD);

    for (i = 0; i < MAX_NUM_OF_PROD; i++)
    {
        Prod[i] = getCatFoodInfo(i);
        report[i] = calculateReportData(Prod[i]);
    }

    j = 0;
    minimum = report[0].costCalServing;
    for (i = 1; i < MAX_NUM_OF_PROD; i++) 
    {
        if (report[i].costCalServing < minimum) 
        {
            minimum = report[i].costCalServing;
            j = i;
        }
    }

    printf("\n");
    displayCatFoodHeader();
    displaysCatFoodData(Prod);

    displayReportHeader();

    for (i = 0; i < MAX_NUM_OF_PROD; i++)
    {
        if (report[i].costCalServing == minimum)
        {
            cheapest = 1;
        }
        else {
            cheapest = 0;
        }
        displayReportData(report[i], cheapest);
    }
   
    displayFinalAnalysis(Prod[j]);
}