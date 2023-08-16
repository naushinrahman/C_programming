// ----------------------------------------------------------------------------
// structures
struct CatFoodInfo
{
    int SKU;
    double prodPrice;
    double prodWeight;
    int calServing;
};

struct ReportData
{
    int SKU;
    double prodPrice;
    double weightLbs;
    double calServing;

    int weightG;
    double weightKg;  
    double totalServing;
    double costServing;
    double costCalServing;
};

#define MAX_NUM_OF_PROD 3
#define GRAMS_IN_SERVING 64
#define CONVERSION_TO_KG 2.20462

// ----------------------------------------------------------------------------
// function prototypes

// PART-1

// 1. Get user input of int type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
int getIntPositive(int*);

// 2. Get user input of double type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
double getDoublePositive(double*);

// 3. Opening Message (include the number of products that need entering)
void openingMessage(const int);

// 4. Get user input for the details of cat food product
struct CatFoodInfo getCatFoodInfo(const int);

// 5. Display the formatted table header
void displayCatFoodHeader(void);

// 6. Display a formatted record of cat food data
void displaysCatFoodData(const struct CatFoodInfo[]);

// ----------------------------------------------------------------------------
// PART-2

// 8. convert lbs: kg
double convertLbsKg(const double* lbs, double* kg);

// 9. convert lbs: g
int convertLbsG(const double* lbs, int* g);

// 10. convert lbs: kg / g
void convertLbs(const double* lbs, double* kg, int* g);

// 11. calculate: servings based on gPerServ
double calculateServings(const int servingG, const int totalG, double* numOfServing);

// 12. calculate: cost per serving
double calculateCostPerServing(const double* prodPrice, const double* numOfServing, double* costPerServing);

// 13. calculate: cost per calorie
double calculateCostPerCal(const double* prodPrice, const double* totalCal, double* costPerCal);

// 14. Derive a reporting detail record based on the cat food product data
struct ReportData calculateReportData(const struct CatFoodInfo prod);

// 15. Display the formatted table header for the analysis results
void displayReportHeader(void);

// 16. Display the formatted data row in the analysis table
void displayReportData(const struct ReportData report, const int cheapest);

// 17. Display the findings (cheapest)
void displayFinalAnalysis(const struct CatFoodInfo cheapest);

// ----------------------------------------------------------------------------

// 7. Logic entry point 
void start(void);
