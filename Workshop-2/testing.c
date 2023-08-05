#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
    const double TAX = 0.13;
    const char patSize = 'S';

    float small_size, medium_size, large_size, subtotal;
    int num_of_shirts;

    printf("Set Shirt Prices\n");
    printf("================\n\n");
    printf("Enter the price for a SMALL shirt: $");
    scanf("%f", &small_size);
    printf("Enter the price for a MEDIUM shirt: $");
    scanf("%f", &medium_size);
    printf("Enter the price for a LARGE shirt: $");
    scanf("%f", &large_size);

    printf("\nShirt Store Price List\n");
    printf("======================\n");

    printf("SMALL  : $%.2lf\n", small_size);
    printf("MEDIUM : $%.2lf\n", medium_size);
    printf("LARGE  : $%.2lf\n", large_size);

    printf("\nPatty's shirt size is 'S'\n");
    printf("Number of shirts Patty is buying:");
    scanf("%d", &num_of_shirts);

    printf("\nPatty's shopping cart...\n");
    printf("Contains : %d shirts\n", num_of_shirts);

    small_size* num_of_shirts = subtotal;

    //plus .005 to tax, price aftertax = (77.34578 + .005)*100

    return 0;
}
