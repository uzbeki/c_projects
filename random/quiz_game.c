#include "stdio.h"

char start_input;

// game introduction message
void greet()
{
    printf("\nQUIZ GAME made in C\n");
    printf("...................\n");
    printf("Press S to start the game\n");
    printf("Press Q to quit the game\n");
    printf("\n");
    printf("\n");
}

// checks what the user input is
void confirm_user_input(start_input)
{
    if (start_input == "s")
    {
        game_start();
    }
    else if (start_input == "q")
    {
        game_over();
    }
    else
    {
        printf("\nPlease enter a correct input\n");
        greet();
    }
}

int main()
{

    greet();
    scanf("%c", start_input);
    return 0;
}

