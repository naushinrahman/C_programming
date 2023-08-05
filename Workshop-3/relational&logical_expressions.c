#include <stdio.h>

int main(void)
{
    // You must use this variable in #3 data analysis section!
    const double testValue = 330.99;
    const char prod1_tax = 'Y', prod2_tax = 'N', prod3_tax = 'N';
    const int prod1_id = 111, prod2_id = 222, prod3_id = 111;
    const float prod1_price = 111.49, prod2_price = 222.99, prod3_price = 334.49, avg_price = (prod1_price + prod2_price + prod3_price) / 3;
  
    printf("Product Information\n");
    printf("===================\n");

    printf("Product-1 (ID:%d)\n", prod1_id);
    printf("  Taxed: %c\n", prod1_tax);
    printf("  Price: $%8.4f\n\n", prod1_price);
    printf("Product-2 (ID:%d)\n", prod2_id);
    printf("  Taxed: %c\n", prod2_tax);
    printf("  Price: $%8.4f\n\n", prod2_price);
    printf("Product-3 (ID:%d)\n", prod3_id);
    printf("  Taxed: %c\n", prod3_tax);
    printf("  Price: $%8.4f\n\n", prod3_price);

    printf("The average of all prices is: $%8.4f\n\n", avg_price);

    printf("About Relational and Logical Expressions!\n");
    printf("========================================\n");
    printf("1. These expressions evaluate to TRUE or FALSE\n");
    printf("2. FALSE: is always represented by integer value 0\n");
    printf("3. TRUE : is represented by any integer value other than 0\n\n");

    printf("Some Data Analysis...\n");
    printf("=====================\n");
    printf("1. Is product 1 taxable? -> %d\n\n", prod1_tax == 'Y');
    printf("2. Are products 2 and 3 both NOT taxable (N)? -> %d\n\n", 
        prod2_tax == 'N' && prod3_tax == 'N');
    printf("3. Is product 3 less than testValue ($%.2lf)? -> %d\n\n", testValue, prod3_price < testValue);
    printf("4. Is the price of product 3 more than both product 1 and 2 combined? -> %d\n\n", 
        prod3_price > (prod1_price + prod1_price));
    printf("5. Is the price of product 1 equal to or more than the price difference\n");
    printf("   of product 3 LESS product 2? ->  %d (price difference: $%.2lf)\n\n",
        prod1_price >= (prod3_price - prod2_price), prod3_price - prod2_price);
    printf("6. Is the price of product 2 equal to or more than the average price? -> %d\n\n", 
        prod2_price >= avg_price);

    printf("7. Based on product ID, product 1 is unique -> %d\n\n", prod1_id != prod3_id && prod1_id != prod2_id);
    printf("8. Based on product ID, product 2 is unique -> %d\n\n", prod2_id != prod1_id && prod2_id != prod3_id);
    printf("9. Based on product ID, product 3 is unique -> %d\n\n", prod3_id != prod1_id && prod3_id != prod2_id);

    return 0;
}
