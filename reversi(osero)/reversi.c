//creating a game REVERSI
// rules at rules.txt

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// declarations

void choose_side();
void show_help();
void game_start(char player1[1], char player2[1]);
void draw_board();
void initial_board();
char board[8][8];
int v, h;

/* 
################################ 
        1. Welcome Message
################################

Draws an initial board for players to start off.
board sample
    char board[8][8] =
    {
        {'-', '-', '-', '-', '-', '-', '-', '-'},
        {'-', '-', '-', '-', '-', '-', '-', '-'},
        {'-', '-', '-', '-', '-', '-', '-', '-'},
        {'-', '-', '-', '-', '-', '-', '-', '-'},
        {'-', '-', '-', '-', '-', '-', '-', '-'},
        {'-', '-', '-', '-', '-', '-', '-', '-'},
        {'-', '-', '-', '-', '-', '-', '-', '-'},
        {'-', '-', '-', '-', '-', '-', '-', '-'}}; 
*/

void initial_board()
{
    printf("\n");
    for (v = 1; v < 9; v++)
    {
        
        for (h = 1; h < 9; h++)
        {
            if (v == 4 && h == 4)
            {
                printf(" x ");
                continue;
            }
            else if (v == 4 && h == 5)
            {
                printf(" o ");
                continue;
            }
            else if (v == 5 && h == 4)
            {
                printf(" o ");
                continue;
            }
            else if (v == 5 && h == 5)
            {
                printf(" x ");
                continue;
            }

            printf(" - ");
        }

        printf("\n");
    };
}


















/* ################################ 
        1. Welcome Message
################################ */
void welcome()
{
    void exit(int status);
    char choice[1];
    printf("\n***********************************\nWelcome to the Reversi(Osero) game!\n***********************************\n");
    printf("\nPress S to start the game\nPress H to see the help page\nPress Q to quit the game\n==> ");
    scanf("%s", &choice);

    if (strcmp(choice, "s") == 0)
    {
        choose_side();
    }
    else if (strcmp(choice, "h") == 0)
    {
        show_help();
    }
    else if (strcmp(choice, "q") == 0)
    {
        exit(0);
    }
    else
    {
        printf("Invalid input.\nPlease choose one from 's','h' or 'q'.");
        welcome();
    }
};

/* ################################ 
            Game start
################################ */
void game_start(char player1[1], char player2[1])
{
    printf("\nRemember: Player 2 starts first.\n");
    initial_board();
};



/* ################################ 
Player 1 Choose side Message
################################ */
void choose_side()
{
    char side[1];
    printf("%s", "\nPlayer 1, please choose your side:\nx\n0\n");
    printf("\np1 ==> ");
    scanf("%s", &side);

    if (strcmp(side, "x") == 0 || strcmp(side, "X") == 0)
    {
        printf("Okay, Player 1 is x, Player 2 is 0.");
        game_start("x", "o");
    }
    else if (strcmp(side, "o") == 0 || strcmp(side, "O") == 0 || strcmp(side, "0") == 0)
    {
        printf("Okay, Player 1 is o, Player 2 is x.");
        game_start("o", "x");
    }
    else
    {

        printf("No, you have to choose either x or o. Please enter a corrent character. ");
        choose_side();
    };
};

/* ################################ 
         Help Message
################################ */
void show_help()
{

    struct Help
    {
        char origin[500];
        char description[500];
        char objective[500];
        char start[500];
        char moves[847];
        char final[600];
    };

    struct Help Help1;

    strcpy(Help1.description, "\n:::::description:::::\nReversi is an ancient game whose description is uncertain.\nThe oldest references about similar games go back to late \nin the 19th century; those games had different names and \ntheir boards had different size or shape. In 1870 appeared \na similar game using a cross shape board. Subsequently appeared \nanother game played on a 8x8 square shape board.\n");
    strcpy(Help1.origin, "\n:::::ORIGIN:::::\nReversi is an ancient game whose description is uncertain.\nThe oldest references about similar games go back to late \nin the 19th century; those games had different names and \ntheir boards had different size or shape. In 1870 appeared \na similar game using a cross shape board. Subsequently appeared \nanother game played on a 8x8 square shape board.\n");
    strcpy(Help1.description, "\n:::::DESCRIPTION:::::\nTwo players take part in this game; they need a board with 64 \nsquares distributed in 8 rows and 8 columns, and 64 similar \npieces of two colours (normally black and white): the obverse \nin one colour and the reversi in the other colour.\n");
    strcpy(Help1.objective, "\n:::::OBJECTIVE:::::\nThe objective for each of the players is to finish the game \nwith more pieces on the board in his own colour than the opponent.\n");
    strcpy(Help1.start, "\n\t\t ::::How the game goes on::::\n\n::::START OF THE GAME::::\nBefore starting players decide which colour will use each of \nthem. Next 4 pieces have to be placed in the central squares \nof the board, so that each pair of pieces of the same colour \nform a diagonal between them. The player with black pieces \nmoves first; one only move is made every turn.\n");
    strcpy(Help1.moves, "\n::::MOVES::::\nA move consists in placing from outside one piece on the board. \nPlaced pieces can never be moved to another square later in the \ngame. The incorporation of the pieces must be made according to \nthe following rules: \n - The incorported piece must outflank one or more of the \nopponent placed pieces.\n - To outflank means that a single piece or one straight row (vertical, \nhorizontal or diagonal) of pieces of the opponent is in both sides \nnext to own pieces, with no empty squares between all those pieces\n - The player who makes the move turns the outflanked pieces over, \nbecoming all of them in own pieces.\n - If there is more than one outflanked row, all the involved pieces \nin those rows have to be flipped.\n - If it's not possible to make this kind of move, turn is forfeited \nand the opponent repeats another move.\n");
    strcpy(Help1.final, "\n::::FINAL::::\nThe game is over when all the squares of the board are taken or none of \nthe players can move. In any case the winner is the player who has more \npieces on the board. The game ends in a draw when both players have the \nsame number of pieces on the board.\n");

    printf("%s", Help1.origin);
    printf("%s", Help1.description);
    printf("%s", Help1.objective);
    printf("%s", Help1.start);
    printf("%s", Help1.moves);
    printf("%s", Help1.final);
};

/* ################################ 
         main function
################################ */
int main()
{
    welcome();

    return 0;
};