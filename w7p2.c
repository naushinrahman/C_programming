/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #7 (P2)
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

#define LIVES_MIN 1
#define LIVES_MAX 10
#define PATH_MIN 10
#define PATH_MAX 70
#define MULTIPLE 5
#define MAJOR_RULER 10


struct PlayerInfo
{
    char tag;
    int lives;
    int treasures;
    int history[PATH_MAX];
};

struct GameInfo
{
    int pathLength;
    int moves;
    int bombPlacement[PATH_MAX];
    int treasurePlacement[PATH_MAX];
    int boardPath[PATH_MAX];
};

int main(void)
{
    struct PlayerInfo player;
    struct GameInfo game;

    int i = 0, j, k, nextMove;
    player.treasures = 0;

    printf("================================\n");
    printf("         Treasure Hunt!\n");
    printf("================================\n\n");
    printf("PLAYER Configuration\n");
    printf("--------------------\n");
    printf("Enter a single character to represent the player: ");
    scanf(" %c", &player.tag);

    while (i == 0)
    {
        printf("Set the number of lives: ");
        scanf("%d", &player.lives);
        if (player.lives < LIVES_MIN || player.lives > LIVES_MAX)
        {
            printf("     Must be between %d and %d!\n", LIVES_MIN, LIVES_MAX);
        }
        else
        {
            printf("Player configuration set-up is complete\n\n");
            i = 1;
        }

    }
    printf("GAME Configuration\n");
    printf("------------------\n");

    while (i == 1)
    {
        printf("Set the path length (a multiple of 5 between 10-70): ");
        scanf("%d", &game.pathLength);
        if ((game.pathLength < PATH_MIN || game.pathLength) && game.pathLength % MULTIPLE)
        {
            printf("     Must be a multiple of %d and between %d-%d!!!\n", MULTIPLE, PATH_MIN, PATH_MAX);
        }
        else
        {
            i = 0;
        }
    }

    while (i == 0)
    {
        printf("Set the limit for number of moves allowed: ");
        scanf("%d", &game.moves);
        if (game.moves < player.lives || game.moves >(75 * game.pathLength / 100))
        {
            printf("    Value must be between %d and %d\n", player.lives, (75 * game.pathLength / 100));
        }
        else
        {
            i = 1;
        }
    }

    printf("\nBOMB Placement\n");
    printf("--------------\n");
    printf("Enter the bomb positions in sets of %d where a value\n", MULTIPLE);
    printf("of 1=BOMB, and 0=NO BOMB. Space-delimit your input.\n");
    printf("(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", game.pathLength);

    for (i = 0; i < game.pathLength; i += MULTIPLE)
    {
        printf("   Positions [%2d-%2d]: ", i + 1, MULTIPLE + i);

        for (j = 0; j < MULTIPLE; j++)
        {
            scanf("%d", &game.bombPlacement[i + j]);
        }
    }
    printf("BOMB placement set\n\n");
    printf("TREASURE Placement\n");
    printf("------------------\n");
    printf("Enter the treasure placements in sets of %d where a value\n", MULTIPLE);
    printf("of 1=TREASURE, and 0=NO TREASURE. Space-delimit your input.\n");
    printf("(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", game.pathLength);

    for (i = 0; i < game.pathLength; i += MULTIPLE)
    {
        printf("   Positions [%2d-%2d]: ", i + 1, MULTIPLE + i);

        for (j = 0; j < MULTIPLE; j++)
        {
            scanf("%d", &game.treasurePlacement[i + j]);
        }
    }

    printf("TREASURE placement set\n\n");
    printf("GAME configuration set-up is complete...\n\n");
    printf("------------------------------------\n");
    printf("TREASURE HUNT Configuration Settings\n");
    printf("------------------------------------\n");
    printf("Player:\n");
    printf("   Symbol     : %c\n", player.tag);
    printf("   Lives      : %d\n", player.lives);
    printf("   Treasure   : [ready for gameplay]\n");
    printf("   History    : [ready for gameplay]\n\n");
    printf("Game:\n");
    printf("   Path Length: %d\n", game.pathLength);
    printf("   Bombs      : ");

    for (i = 0; i < game.pathLength; i++)
    {
        printf("%d", game.bombPlacement[i]);
    }
    printf("\n   Treasure   : ");
    for (i = 0; i < game.pathLength; i++)
    {
        printf("%d", game.treasurePlacement[i]);
    }
    for (i = 0; i < game.pathLength; i++)
    {
        game.boardPath[i] = '-';
    }
     
    printf("\n\n====================================\n");
    printf("~ Get ready to play TREASURE HUNT! ~\n");
    printf("====================================\n");

    while (player.lives > 0 && game.moves > 0)
    {
        printf("\n  ");
        for (i = 0; i < game.pathLength; i++)
        {
            
            printf("%c", game.boardPath[i]);
        }
        printf("\n  ");
        for (i = 1; i <= game.pathLength; i++)
        {
            if (i % 10 == 0)
            {
                printf("%d", i / 10);
            }
            else
            {
                printf("|");
            }

        }
        printf("\n  ");
        for (i = 1; i <= game.pathLength; i++)
        {

            printf("%d", i % 10);
        }
    
        printf("\n+---------------------------------------------------+\n");
        printf("  Lives: %2d  |  Treasures: %2d  | Moves remaining: %2d\n", player.lives, player.treasures, game.moves);
        printf("+---------------------------------------------------+\n");
        j = 0;
        while (j == 0) 
        {
            printf("Next Move [1-%d]: ", game.pathLength);
            scanf("%d", &nextMove);
            if (nextMove < 1 || nextMove > game.pathLength)
            {
                printf("   Out of Range!!!\n");
                j = 0;
            }
            else 
            {
                j = 1;
            }
        } 

        printf("\n");
        if (game.boardPath[nextMove - 1] != '-')
        {
            printf("=================> Dope! You've been here before!\n\n");
        }
        else if (game.bombPlacement[nextMove - 1] == 0 && game.treasurePlacement[nextMove - 1] == 0)
        {
            printf("=================> [.] ...Nothing found here... [.]\n\n");
            game.moves-=1;
            game.boardPath[nextMove - 1] = '.';
        }
        else if (game.bombPlacement[nextMove - 1] == 1 && game.treasurePlacement[nextMove - 1] == 1)
        {
            printf("=================> [&] !!! BOOO00M !!! [&]\n");
            printf("=================> [&] $$$ Life Insurance Payout !!! [&]\n\n");
            game.moves-=1;
            player.lives-=1;
            player.treasures+=1;
            game.boardPath[nextMove - 1] = '&';
        }
        else if(game.bombPlacement[nextMove - 1] == 1)
        {
            printf("=================> [!] !!! BOOO00M !!! [!]\n\n");
            game.moves-=1;
            player.lives-=1;
            game.boardPath[nextMove - 1] = '!';
        }
        else
        {
            printf("=================> [$] $$$ Found Treasure! $$$ [$]\n\n");
            game.moves-=1;
            player.treasures+=1;
            game.boardPath[nextMove - 1] = '$';
        }
        if (i > 0 && player.lives > 0 && game.moves > 0)
        {
            printf("  ");
            for (k = 0; k < nextMove; k++)
            {
                if (k == (nextMove - 1))
                {
                    printf("%c", player.tag);
                }
                else
                {
                    printf(" ");
                }
            }
        }
    }

    if (player.lives == 0)
    {
        printf("No more LIVES remaining!\n");
    }
    else
    {
        printf("No more MOVES remaining!\n");
    }
    printf("  ");
    for (k = 0; k < nextMove; k++)
    {
        if (k == (nextMove - 1))
        {
            printf("%c", player.tag);
        }
        else
        {
            printf(" ");
        }
    }
    printf("\n  ");
    for (i = 0; i < game.pathLength; i++)
    {

        printf("%c", game.boardPath[i]);
    }
    printf("\n  ");
    for (i = 1; i <= game.pathLength; i++)
    {
        if (i % 10 == 0)
        {
            printf("%d", i / 10);
        }
        else
        {
            printf("|");
        }
    }
    printf("\n  ");
    for (i = 1; i <= game.pathLength; i++)
    {

        printf("%d", i % 10);
    }
    printf("\n+---------------------------------------------------+\n");
    printf("  Lives: %2d  |  Treasures: %2d  | Moves remaining: %2d\n", player.lives, player.treasures, game.moves);
    printf("+---------------------------------------------------+\n");
    printf("\n##################\n");
    printf("#   Game over!   #\n");
    printf("##################\n");
    printf("\nYou should play again and try to beat your score!\n");
   
    return 0;
}