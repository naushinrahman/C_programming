#define _CRT_SECURE_NO_WARNINGS
#define WISH_LIST 10

#include <stdio.h>
#include <string.h>

int main(void) {
    const double MaxIncome = 400000.00, MinIncome = 500.00, MinCost = 100.00;
    double monthlyIncome, total = 0.0;
    int WishListItems, n = 1, i = 0;
    char FinanceOptions[WISH_LIST + 1];
    double Cost[WISH_LIST];
    int Priority[WISH_LIST];

    printf("+--------------------------+\n");
    printf("+   Wish List Forecaster   |\n");
    printf("+--------------------------+\n");

    while (n == 1) {
        printf("\nEnter your monthly NET income: $");
        scanf("%lf", &monthlyIncome);
        if (monthlyIncome > MaxIncome) {
            printf("ERROR: Liar! I'll believe you if you enter a value no more than $%.2lf\n", MaxIncome);
        }
        else if (monthlyIncome < MinIncome) {
            printf("ERROR: You must have a consistent monthly income of at least $%.2lf\n", MinIncome);
        }
        else {
            n = 0;
        }
    }

    n = 1;
    while (n == 1) {
        printf("\nHow many wish list items do you want to forecast?: ");
        scanf("%d", &WishListItems);
        if (WishListItems < 1 || WishListItems > WISH_LIST) {
            printf("ERROR: List is restricted to between 1 and 10 items.\n");
        }
        else {
            n = 0;
        }
    }

    for (; n < WishListItems; n++) {   
        printf("\nItem-%d Details:\n", n+1);
        i = 0;
        while (i == 0) {
            printf("   Item cost: $");
            scanf("%lf", &Cost[n]);
            if (Cost[n] < MinCost) {
                printf("      ERROR: Cost must be at least $%.2lf\n", MinCost);
            }
            else {
                total += Cost[n];
                while (i == 0) {
                    printf("   How important is it to you? [1=must have, 2=important, 3=want]: ");
                    scanf("%d", &Priority[n]);
                    if (Priority[n] < 1 || Priority[n] > 3) {
                        printf("      ERROR: Value must be between 1 and 3\n");
                    }
                    else {
                        while (i == 0) {
                            printf("   Does this item have financing options? [y/n]: ");
                            scanf("%s", &FinanceOptions[n]);
                            if (FinanceOptions[n] == 'y' || FinanceOptions[n] == 'n') {
                                i = 1;
                            }
                            else {
                                printf("      ERROR: Must be a lowercase 'y' or 'n'\n");
                                i = 0;
                            }
                            
                        }
                    }

                }
            }
        }
       
    }
    
    printf("\nItem Priority Financed        Cost\n");
    printf("---- -------- -------- -----------\n");
    for (i = 0; i < WishListItems; i++) {
        printf("%3d  %5d    %5c    %11.2lf\n", i+1, Priority[i], FinanceOptions[i], Cost[i]);
    }
    printf("---- -------- -------- -----------\n");
    printf("                      $%11.2lf\n\n", total);
    printf("Best of luck in all your future endeavours!\n");

    return 0;
}
