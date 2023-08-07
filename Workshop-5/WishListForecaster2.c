#define _CRT_SECURE_NO_WARNINGS
#define WISH_LIST_MAX 10
#define WISH_LIST_MIN 1

#include <stdio.h>

int main(void) {
    const double MaxIncome = 400000.00, MinIncome = 500.00, MinCost = 100.00;
    double monthlyIncome, total = 0.0, monthsDoub;
    int WishListItems, n = 1, i = 0, MenuSelection, months, years, flag = 0, filter;
    char FinanceOptions[WISH_LIST_MAX + WISH_LIST_MIN];
    double Cost[WISH_LIST_MAX];
    int Priority[WISH_LIST_MAX];

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
        if (WishListItems < WISH_LIST_MIN || WishListItems > WISH_LIST_MAX) {
            printf("ERROR: List is restricted to between 1 and 10 items.\n");
        }
        else {
            n = 0;
        }
    }
    for (; n < WishListItems; n++) {
        printf("\nItem-%d Details:\n", n + 1);
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
        printf("%3d  %5d    %5c    %11.2lf\n", i + 1, Priority[i], FinanceOptions[i], Cost[i]);
    }
    printf("---- -------- -------- -----------\n");
    printf("                      $%11.2lf\n", total);

    i = 0;
    while (i == 0) {
        printf("\nHow do you want to forecast your wish list?\n");
        printf(" 1. All items (no filter)\n");
        printf(" 2. By priority\n");
        printf(" 0. Quit/Exit\n");
        printf("Selection: ");
        scanf("%d", &MenuSelection);
        if (MenuSelection == 0) {
            printf("\nBest of luck in all your future endeavours!\n");
            i = 1;
        }
        else if (MenuSelection == 1) {
            printf("\n====================================================\n");
            printf("Filter:   All items\n");
            printf("Amount:   $%1.2lf\n", total);
            years = total / monthlyIncome / 12;
            monthsDoub = (total / monthlyIncome / 12 - years) * 12;
            months = (int)monthsDoub % 12;
            (((years * 12 + months) * monthlyIncome) < total) ? months += 1 : months;
            printf("Forecast: %d years, %d months\n", years, months);

            for (i = 0; i < WishListItems && flag == 0; i++) {
                if (FinanceOptions[i] == 'y') {
                    printf("NOTE: Financing options are available on some items.\n");
                    printf("      You can likely reduce the estimated months.\n");
                    printf("====================================================\n");
                    flag = 1;
                }
            }
            if (flag == 0) {
                printf("====================================================\n");
            }
            i = 0;
        }
        else if (MenuSelection == 2) {
            flag = 0;
            years = 0;
            months = 0;
            total = 0;
            printf("\nWhat priority do you want to filter by? [1-3]: ");
            scanf("%d", &filter);                         
        
            if (filter < 1 || filter > 3) {
                printf("      ERROR: Value must be between 1 and 3\n");
            }
            else {
                printf("\n====================================================\n");
                printf("Filter:   by priority (%d)\n", filter);
                for (i = 0; i < WishListItems; i++) {
                    if (Priority[i] == filter)
                    total += Cost[i];
                }
                printf("Amount:   $%1.2lf\n", total);
                years = total / monthlyIncome / 12;
                monthsDoub = (total / monthlyIncome / 12 - years) * 12;
                months = (int)monthsDoub % 12;
                (((years * 12 + months) * monthlyIncome) < total) ? months += 1 : months;
                printf("Forecast: %d years, %d months\n", years, months);
                for (i = 0; i < WishListItems && flag == 0; i++) {
                    if (FinanceOptions[i] == 'y' && Priority[i] == filter) {
                        printf("NOTE: Financing options are available on some items.\n");
                        printf("      You can likely reduce the estimated months.\n");
                        printf("====================================================\n");
                        flag = 1;
                    }
                }
                if (flag == 0) {
                    printf("====================================================\n");
                }
                i = 0;
            }
        }
        else {
            printf("\nERROR: Invalid menu selection.\n");
        }
    }
    return 0;
}
