#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
    // You will need this when converting from grams to pounds (lbs)
    const double GRAMS_IN_LBS = 453.5924;
    char cof_type1, cof_type2, cof_type3, cream1, cream2, cream3, cofstr, cofwcream;
    int cof_weight1, cof_weight2, cof_weight3, daily_serving;

    printf("Take a Break - Coffee Shop\n");
    printf("==========================\n\n");
    printf("Enter the coffee product information being sold today...\n\n");
    printf("COFFEE-1...\n");
    printf("Type ([L]ight,[M]edium,[R]ich): ");
    scanf(" %c", &cof_type1);
    printf("Bag weight (g): ");
    scanf("%d", &cof_weight1);
    printf("Best served with cream ([Y]es,[N]o): ");
    scanf(" %c", &cream1);
    printf("\n");
    printf("COFFEE-2...\n");
    printf("Type ([L]ight,[M]edium,[R]ich): ");
    scanf(" %c", &cof_type2);
    printf("Bag weight (g): ");
    scanf("%d", &cof_weight2);
    printf("Best served with cream ([Y]es,[N]o): ");
    scanf(" %c", &cream2);
    printf("\n");
    printf("COFFEE-3...\n");
    printf("Type ([L]ight,[M]edium,[R]ich): ");
    scanf(" %c", &cof_type3);
    printf("Bag weight (g): ");
    scanf("%d", &cof_weight3);
    printf("Best served with cream ([Y]es,[N]o): ");
    scanf(" %c", &cream3);

    printf("\n");
    printf("---+------------------------+---------------+-------+\n");
    printf("   |    Coffee              |   Packaged    | Best  |\n");
    printf("   |     Type               |  Bag Weight   | Served|\n");
    printf("   +------------------------+---------------+ With  |\n");
    printf("ID | Light | Medium | Rich  |  (G) | Lbs    | Cream |\n");
    printf("---+------------------------+---------------+-------|\n");
    printf(" 1 |   %d   |   %d    |   %d   | %4d | %6.3lf |   %d   |\n", cof_type1 == 'l' || cof_type1 == 'L', cof_type1 == 'm' || cof_type1 == 'M', cof_type1 == 'r' || cof_type1 == 'R', cof_weight1, cof_weight1/GRAMS_IN_LBS, cream1 == 'Y' || cream1 == 'y');
    printf(" 2 |   %d   |   %d    |   %d   | %4d | %6.3lf |   %d   |\n", cof_type2 == 'l' || cof_type2 == 'L', cof_type2 == 'm' || cof_type2 == 'M', cof_type2 == 'r' || cof_type2 == 'R', cof_weight2, cof_weight2 / GRAMS_IN_LBS, cream2 == 'Y' || cream2 == 'y');
    printf(" 3 |   %d   |   %d    |   %d   | %4d | %6.3lf |   %d   |\n\n", cof_type3 == 'l' || cof_type3 == 'L', cof_type3 == 'm' || cof_type3 == 'M', cof_type3 == 'r' || cof_type3 == 'R', cof_weight3, cof_weight3 / GRAMS_IN_LBS, cream3 == 'Y' || cream3 == 'y');
    
    printf("Enter how you like your coffee...\n\n");

    printf("Coffee strength ([L]ight, [M]edium, [R]ich): ");
    scanf(" %c", &cofstr);
    printf("Do you like your coffee with cream ([Y]es,[N]o): ");
    scanf(" %c", &cofwcream); 
    printf("Typical number of daily servings: ");
    scanf("%d", &daily_serving);
    
    printf("\nThe below table shows how your preferences align to the available products:\n\n");
    printf("--------------------+-------------+-------+\n");
    printf("  |     Coffee      |  Packaged   | With  |\n");
    printf("ID|      Type       | Bag Weight  | Cream |\n");
    printf("--+-----------------+-------------+-------+\n");
    printf(" 1|       %d       |      %d       |   %d   |\n", 
        ((cof_type1 == 'l' || cof_type1 == 'L') && (cofstr == 'l' || cofstr == 'L')) 
        || ((cof_type1 == 'm' || cof_type1 == 'M') && (cofstr == 'm' || cofstr == 'M')) 
        || ((cof_type1 == 'r' || cof_type1 == 'R') && (cofstr == 'r' || cofstr == 'R')),
        ((daily_serving >= 1 && daily_serving <= 4) && (cof_weight1 == 250)) 
        || ((daily_serving >= 5 && daily_serving <= 9) && (cof_weight1 == 500))
        || ((daily_serving >= 10) && (cof_weight1 == 1000)),
        ((cofwcream == 'Y' || cofwcream == 'y') && (cream1 == 'Y' || cream1 == 'y'))
        || ((cofwcream == 'N' || cofwcream == 'n') && (cream1 == 'N' || cream1 == 'n')));

    printf(" 2|       %d        |      %d       |   %d   |\n",
        ((cof_type2 == 'l' || cof_type2 == 'L') && (cofstr == 'l' || cofstr == 'L'))
        || ((cof_type2 == 'm' || cof_type2 == 'M') && (cofstr == 'm' || cofstr == 'M'))
        || ((cof_type2 == 'r' || cof_type2 == 'R') && (cofstr == 'r' || cofstr == 'R')),
        ((daily_serving >= 1 && daily_serving <= 4) && (cof_weight2 == 250)) 
        || ((daily_serving >= 5 && daily_serving <= 9) && (cof_weight2 == 500))
        || ((daily_serving >= 10) && (cof_weight2 == 1000)),
        ((cofwcream == 'Y' || cofwcream == 'y') && (cream2 == 'Y' || cream2 == 'y'))
        || ((cofwcream == 'N' || cofwcream == 'n') && (cream2 == 'N' || cream2 == 'n'))); 
        
   
    printf(" 3|       %d        |      %d       |   %d   |\n\n", 
        ((cof_type3 == 'l' || cof_type3 == 'L') && (cofstr == 'l' || cofstr == 'L'))
        || ((cof_type3 == 'm' || cof_type3 == 'M') && (cofstr == 'm' || cofstr == 'M'))
        || ((cof_type3 == 'r' || cof_type3 == 'R') && (cofstr == 'r' || cofstr == 'R')),
        ((daily_serving >= 1 && daily_serving <= 4) && (cof_weight3 == 250)) 
        || ((daily_serving >= 5 && daily_serving <= 9) && (cof_weight3 == 500))
        || ((daily_serving >= 10) && (cof_weight3 == 1000)),
        ((cofwcream == 'Y' || cofwcream == 'y') && (cream3 == 'Y' || cream3 == 'y'))
        || ((cofwcream == 'N' || cofwcream == 'n') && (cream3 == 'N' || cream3 == 'n')));

  printf("Enter how you like your coffee...\n\n");

    printf("Coffee strength ([L]ight, [M]edium, [R]ich): ");
    scanf(" %c", &cofstr);
    printf("Do you like your coffee with cream ([Y]es, [N]o): ");
    scanf(" %c", &cofwcream); 
    printf("Typical number of daily servings: ");
    scanf("%d", &daily_serving);

    printf("\nThe below table shows how your preferences align to the available products:\n\n");
    printf("-------------------+--------------+-------+\n");
    printf("  |     Coffee     |   Packaged   | With  |\n");
    printf("ID|      Type      |  Bag Weight  | Cream |\n");
    printf("--+----------------+--------------+-------+\n");
    printf(" 1|       %d        |      %d       |   %d   |\n",
        ((cof_type1 == 'l' || cof_type1 == 'L') && (cofstr == 'l' || cofstr == 'L'))
        || ((cof_type1 == 'm' || cof_type1 == 'M') && (cofstr == 'm' || cofstr == 'M'))
        || ((cof_type1 == 'r' || cof_type1 == 'R') && (cofstr == 'r' || cofstr == 'R')),
        ((daily_serving >= 1 && daily_serving <= 4) && (cof_weight1 == 250))
        || ((daily_serving >= 5 && daily_serving <= 9) && (cof_weight1 == 500))
        || ((daily_serving >= 10) && (cof_weight1 == 1000)),
        ((cofwcream == 'Y' || cofwcream == 'y') && (cream1 == 'Y' || cream1 == 'y'))
        || ((cofwcream == 'N' || cofwcream == 'n') && (cream1 == 'N' || cream1 == 'n')));

    printf(" 2|       %d        |      %d       |   %d   |\n",
        ((cof_type2 == 'l' || cof_type2 == 'L') && (cofstr == 'l' || cofstr == 'L'))
        || ((cof_type2 == 'm' || cof_type2 == 'M') && (cofstr == 'm' || cofstr == 'M'))
        || ((cof_type2 == 'r' || cof_type2 == 'R') && (cofstr == 'r' || cofstr == 'R')),
        ((daily_serving >= 1 && daily_serving <= 4) && (cof_weight2 == 250))
        || ((daily_serving >= 5 && daily_serving <= 9) && (cof_weight2 == 500))
        || ((daily_serving >= 10) && (cof_weight2 == 1000)),
        ((cofwcream == 'Y' || cofwcream == 'y') && (cream2 == 'Y' || cream2 == 'y'))
        || ((cofwcream == 'N' || cofwcream == 'n') && (cream2 == 'N' || cream2 == 'n')));


    printf(" 3|       %d        |      %d       |   %d   |\n\n",
        ((cof_type3 == 'l' || cof_type3 == 'L') && (cofstr == 'l' || cofstr == 'L'))
        || ((cof_type3 == 'm' || cof_type3 == 'M') && (cofstr == 'm' || cofstr == 'M'))
        || ((cof_type3 == 'r' || cof_type3 == 'R') && (cofstr == 'r' || cofstr == 'R')),
        ((daily_serving >= 1 && daily_serving <= 4) && (cof_weight3 == 250))
        || ((daily_serving >= 5 && daily_serving <= 9) && (cof_weight3 == 500))
        || ((daily_serving >= 10) && (cof_weight3 == 1000)),
        ((cofwcream == 'Y' || cofwcream == 'y') && (cream3 == 'Y' || cream3 == 'y'))
        || ((cofwcream == 'N' || cofwcream == 'n') && (cream3 == 'N' || cream3 == 'n')));
   

    printf("Hope you found a produce that suits your likes!\n");

    return 0;
}
