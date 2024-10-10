#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

int randomgenerate(int a)
{
    srand(time(NULL));
    return (rand() % a) + 1;
}
int main()
{
    int p, c, countP = 0, countC = 0;
    char name[50];

    printf("Player, enter your full name:\n");
    fgets(name, sizeof(name), stdin);

    name[strcspn(name, "\n")] = 0; // Remove trailing newline character

    // Rules of the game
    printf("Rules of the game are \nRock vs Scissors -> Rock wins\n");
    printf("Paper vs Scissors - Scissors wins\n");
    printf("Paper vs Rock - Paper wins\n");
    printf("This game consist of 3 rounds.");

    for (int i = 1; i <= 3; i++)
    {

        printf("Player enter your choice number from the following option\n 1-> Rock,\t2->Paper,\t3->Scissors.\n Enter any other number to Exit the program\n");
        scanf("%d", &p);
        if (p != 1 && p != 2 && p != 3)
        {
            printf("Player entered wrong option *** Exiting the program ****\n");
            exit(0);
        }
        printf("Now computer will enter it's choice from the provided options\n");
        c = randomgenerate(3);
        printf(" player entered = %d \nand\n computer entered = %d\n", p, c);

        if ((p == 1 && c == 1) || (p == 2 && c == 2) || (p == 3 && c == 3))
        {
            if (p == 1 && c == 1)
            {
                printf("Player entered -Rock- and computer entered -Rock-.\n");
                printf("This round of the game is a draw because both players selected the same option.\n");
            }
            else if (p == 2 && c == 2)
            {
                printf("Player entered -Paper- and computer entered -Paper-.\n");
                printf("This round of the game is a draw because both players selected the same option.\n");
            }
            else if (p == 3 && c == 3)
            {
                printf("Player entered -Scissors- and computer entered -Scissors.\n");
                printf("This round of the game is a draw because both players selected the same option.\n");
            }
        }
        else if (p == 1 && c == 2)
        {
            printf("Player entered -Rock- and computer entered -Paper-.\n Winner of this round is Computer\n");
            countC += 1;
        }
        else if (p == 1 && c == 3)
        {
            printf("Player entered -Rock- and computer entered -Scissors-.\n Winner of this round is Player\n");
            countP += 1;
        }
        else if (p == 2 && c == 1)
        {
            printf("Player entered -Paper- and computer entered -Rock-.\n Winner of this round is Player\n");
            countP += 1;
        }
        else if (p == 2 && c == 3)
        {
            printf("Player entered -Paper- and computer entered -Scissors-.\n Winner of this round is Computer\n");
            countC += 1;
        }
        else if (p == 3 && c == 1)
        {
            printf("Player entered -Scissors- and computer entered -Rock-.\n Winner of this round is Computer\n");
            countC += 1;
        }
        else if (p == 3 && c == 2)
        {
            printf("Player entered -Scissors- and computer entered -Paper-.\n Winner of this round is Computer\n");
            countP += 1;
        }
        printf("player score is = %d and computer score is =%d\n ", countP, countC);
    }

    if (countP > countC)
    {
        printf("Final winner of the game is ******** PLAYER ******** %s ********", name);
    }
    else
    {
        printf("Final winner of the game is ******** COMPUTER ********");
    }

    return 0;
}