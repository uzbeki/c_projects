#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// 

/* player1 chooses his side */
void choose_side()
{
    char side[1];
    printf("%s", "\nPlayer 1, please choose your side:\n1: x\n2: 0\n");
    printf("\np1 ==> ");
    scanf("%s", &side);

    if (strcmp(side, "x") == 0 || strcmp(side, "X") == 0)
    {
        printf("Okay, Player 1 is x, Player 2 is 0.");
        // game_start("x", "o");
    }
    else if (strcmp(side, "o") == 0 || strcmp(side, "O") == 0 || strcmp(side, "0") == 0)
    {
        printf("Okay, Player 1 is o, Player 2 is x.");
        // game_start("o", "x");
    }
    else
    {
        // printf();
        printf("No, you have to choose either x or o. Please enter a corrent character. ");
        choose_side();
        
    };

    printf("");
};

int main()
{
    choose_side();
};

void game_start(char player1, char player2)
{
    printf("\nGame has started!\n");
    printf("\nPlayer2, you move first. Remember, you are %s\n", player2);
};