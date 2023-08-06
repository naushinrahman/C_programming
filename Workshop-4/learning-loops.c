#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void) {
    char loop_type;
    int loop_num, iteration = 0;

    printf("+----------------------+\n");
    printf("Loop application STARTED\n");
    printf("+----------------------+\n\n");

    do {
        printf("D = do/while | W = while | F = for | Q = quit\n");
        printf("Enter loop type and the number of times to iterate (Quit=Q0): ");
        scanf(" %c%d", &loop_type, &loop_num);

        if (loop_type != 'Q' && loop_type != 'F' && loop_type != 'W' && loop_type != 'D' && (loop_num < 3 || loop_num > 20)) {
            printf("ERROR: Invalid entered value(s)!\n\n");
            iteration = 1;
        }
            else if (loop_type != 'Q' && loop_type != 'F' && loop_type != 'W' && loop_type != 'D' && (loop_num >= 3 || loop_num <= 20) {
                printf("ERROR: Invalid entered value(s)!\n\n");
                iteration = 1;
            }
  
        if ((loop_type == 'F' || loop_type == 'D' || loop_type == 'W') && (loop_num < 3 || loop_num > 20)) {
            printf("ERROR: The number of iterations must be between 3-20 inclusive!\n\n");
            iteration = 1;
        }

        if (loop_type == 'Q' && loop_num == 0) {
            iteration = 0;
            break;
        }
            else if (loop_type == 'Q' && loop_num != 0) {
                printf("ERROR: To quit, the number of iterations should be 0!\n\n");
                iteration = 1;
            }

        if (loop_type == 'D' && loop_num >= 3 && loop_num <= 20) {
            printf("DO-WHILE: ");
            for (iteration = 1; iteration <= loop_num; iteration++) {
                printf("%c", loop_type);
            }
            printf("\n\n");
        }
        if (loop_type == 'F' && loop_num >= 3 && loop_num <= 20) {
            printf("FOR     : ");
            for (iteration = 1; iteration <= loop_num; iteration++) {
                printf("%c", loop_type);
            }
            printf("\n\n");
        }
        if (loop_type == 'W' && loop_num >= 3 && loop_num <= 20) {
            printf("WHILE   : ");
            for (iteration = 1; iteration <= loop_num; iteration++) {
               printf("%c", loop_type);
            }
            printf("\n\n");
        }
              
    } while (iteration);

    printf("\n+--------------------+\n");
    printf("Loop application ENDED\n");
    printf("+--------------------+\n\n");

    return 0;
}
