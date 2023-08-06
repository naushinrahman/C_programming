#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
    int applesNeeded, orangesNeeded, pearsNeeded, tomatoesNeeded, cabbagesNeeded, 
        applesPicked, orangesPicked, pears_picked, tomatoesPicked, cabbagesPicked, 
        n = 0, shopping = 0;

  do {

        printf("Grocery Shopping\n");
        printf("================\n");

        do {
            printf("How many APPLES do you need? : ");
            scanf("%d", &applesNeeded);

            if (applesNeeded < 0) {
                printf("ERROR: Value must be 0 or more.\n");
                n = 1;
            }
            else if (applesNeeded >= 0)
            {
                printf("\n");
                n = 0;
            }
        } while (n == 1);

        do {
            printf("How many ORANGES do you need? : ");
            scanf("%d", &orangesNeeded);

            if (orangesNeeded < 0)
            {
                printf("ERROR: Value must be 0 or more.\n");
                n = 1;
            }
            else if (orangesNeeded >= 0)
            {
                printf("\n");
                n = 0;
            }
        } while (n == 1);

        do {
            printf("How many PEARS do you need? : ");
            scanf("%d", &pearsNeeded);

            if (pearsNeeded < 0)
            {
                printf("ERROR: Value must be 0 or more.\n");
                n = 1;
            }
            else if (pearsNeeded >= 0)
            {
                printf("\n");
                n = 0;
            }
        } while (n == 1);

        do {
            printf("How many TOMATOES do you need? : ");
            scanf("%d", &tomatoesNeeded);

            if (tomatoesNeeded < 0)
            {
                printf("ERROR: Value must be 0 or more.\n");
                n = 1;
            }
            else if (tomatoesNeeded >= 0)
            {
                printf("\n");
                n = 0;
            }
        } while (n == 1);

        do {
            printf("How many CABBAGES do you need? : ");
            scanf("%d", &cabbagesNeeded);

            if (cabbagesNeeded < 0)
            {
                printf("ERROR: Value must be 0 or more.\n");
                n = 1;
            }
            else if (cabbagesNeeded >= 0)
            {
                printf("\n");
                n = 0;
            }
        } while (n == 1);

 
      printf("--------------------------\n");
      printf("Time to pick the products!\n");
      printf("--------------------------\n\n");

      while (applesNeeded > 0)
      {
          printf("Pick some APPLES... how many did you pick? : ");
          scanf("%d", &applesPicked);
          
          if (applesPicked <= 0)
          {
              printf("ERROR: You must pick at least 1!\n");
          }
          else if (applesPicked < applesNeeded)
          {
              applesNeeded = (applesNeeded - applesPicked);
              printf("Looks like we still need some APPLES...\n");
          }
          else if (applesPicked > applesNeeded)
          {
              printf("You picked too many... only %d more APPLE(S) are needed.\n", applesNeeded);
          }
          else
          {
              printf("Great, that's the apples done!\n\n");
              applesNeeded = 0;
          }
      }

      while (orangesNeeded > 0)
      {
          printf("Pick some ORANGES... how many did you pick? : ");
          scanf("%d", &orangesPicked);
          
          if (orangesPicked <= 0)
          {
              printf("ERROR: You must pick at least 1!\n");
          }
          else if (orangesPicked < orangesNeeded)
          {
              orangesNeeded = (orangesNeeded - orangesPicked);
              printf("Looks like we still need some ORANGES...\n");
          }
          else if (orangesPicked > orangesNeeded)
          {
              printf("You picked too many... only %d more ORANGE(S) are needed.\n", orangesNeeded);
          }
          else
          {
              printf("Great, that's the oranges done!\n\n");
              orangesNeeded = 0;
          }
      }

      while (pearsNeeded > 0)
      {
          printf("Pick some PEARS... how many did you pick? : ");
          scanf("%d", &pears_picked);
          
          if (pears_picked <= 0)
          {
              printf("ERROR: You must pick at least 1!\n");
          }
          else if (pears_picked < pearsNeeded)
          {
              pearsNeeded = (pearsNeeded - pears_picked);
              printf("Looks like we still need some PEARS...\n");
          }
          else if (pears_picked > pearsNeeded)
          {
              printf("You picked too many... only %d more PEAR(S) are needed.\n", pearsNeeded);
          }
          else
          {
              printf("Great, that's the pears done!\n\n");
              pearsNeeded = 0;
          }
      }

      while (tomatoesNeeded > 0)
      {
          printf("Pick some TOMATOES... how many did you pick? : ");
          scanf("%d", &tomatoesPicked);
          
          if (tomatoesPicked <= 0)
          {
              printf("ERROR: You must pick at least 1!\n");
          }
          else if (tomatoesPicked < tomatoesNeeded)
          {
              tomatoesNeeded = (tomatoesNeeded - tomatoesPicked);
              printf("Looks like we still need some TOMATOES...\n");
          }
          else if (tomatoesPicked > tomatoesNeeded)
          {
              printf("You picked too many... only %d more TOMATO(ES) are needed.\n", tomatoesNeeded);
          }
          else
          {
              printf("Great, that's the tomatoes done!\n\n");
              tomatoesNeeded = 0;
          }
      }

      while (cabbagesNeeded > 0)
      {
          printf("Pick some CABBAGES... how many did you pick? : ");
          scanf("%d", &cabbagesPicked);
          
          if (cabbagesPicked <= 0)
          {
              printf("ERROR: You must pick at least 1!\n");
          }
          else if (cabbagesPicked < cabbagesNeeded)
          {
              cabbagesNeeded = (cabbagesNeeded - cabbagesPicked);
              printf("Looks like we still need some CABBAGES...\n");
          }
          else if (cabbagesPicked > cabbagesNeeded)
          {
              printf("You picked too many... only %d more CABBAGE(S) are needed.\n", cabbagesNeeded);
          }
          else
          {
              printf("Great, that's the cabbages done!\n\n");
              cabbagesNeeded = 0;
          }
      }

      printf("All the items are picked!\n\n");
      printf("Do another shopping? (0=NO): ");
      scanf("%d", &shopping);
      printf("\n");
      
      if (shopping == 0)
      {
          printf("Your tasks are done for today - enjoy your free time!");
      }
  } while (shopping == 1);

 return 0;
}
