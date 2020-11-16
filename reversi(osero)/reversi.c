//creating a game REVERSI
// rules at rules.txt

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>  //for using bool

// majors
#define BLANK 0
#define BLACK 1
#define WHITE 2

// declarations
// void choose_side();
void show_help();
void draw_board(char p, int a , int b);
void initial_board();
void game_start();
void get_input();
char board[8][8];
char board_view[8][8];
int v, h;



// checks if a,b pos is blank
bool is_blank(int a, int b) 
{
    if (board[a][b]==BLANK)
    {
        return true;
        /* code */
    }else
    {
        return false;
        /* code */
    }
    
};



void draw_board(char p, int a, int b){
    printf("\n");
    for (v = 0; v < 8; v++)
    {
        for (h = 0; h < 8; h++)
        {
            if (board[v][h] == BLACK)
            {
                board_view[v][h] == 1;
                printf(" x ");
            }
            else if (board[v][h] == WHITE)
            {
                board_view[v][h] == 2;
                printf(" o ");

            }
            else if (a == v && b==h)
            {
                // board_view[a][b] == 1;
                printf(" %c ", p);

            }
            else
            {
                board_view[v][h] == 0;
                printf(" - ");
            }
        };

        printf("\n");
    };
    get_input();
    
};

void get_input(){
    int ver, hor;
    printf("\nWhere do you want to put your piece?\nex.if vertical 4 and horizontal 5, please input 4 and 5\n");
    printf("vertical position==> ");
    scanf("%d", &ver);
    printf("horizontal position==> ");
    scanf("%d", &hor);
    is_blank(ver, hor);

    if (is_blank(ver, hor))
    {
        // draw_board("o", ver, hor);
        printf("\ndrawing on (%d, %d)....\n", ver, hor);
        draw_board('x', ver, hor);
    }
    else
    {
        printf("\nSorry, (%d,%d) is not empty. Please choose an empty spot\n", ver, hor);
        get_input();
    }
    
}




//board starts from 0
char board[8][8] = { 
    BLANK,BLANK,BLANK,BLANK,BLANK,BLANK,BLANK,BLANK,
    BLANK,BLANK,BLANK,BLANK,BLANK,BLANK,BLANK,BLANK,
    BLANK,BLANK,BLANK,BLANK,BLANK,BLANK,BLANK,BLANK,
    BLANK,BLANK,BLANK,BLACK,WHITE,BLANK,BLANK,BLANK,
    BLANK,BLANK,BLANK,WHITE,BLACK,BLANK,BLANK,BLANK,
    BLANK,BLANK,BLANK,BLANK,BLANK,BLANK,BLANK,BLANK,
    BLANK,BLANK,BLANK,BLANK,BLANK,BLANK,BLANK,BLANK,
    BLANK,BLANK,BLANK,BLANK,BLANK,BLANK,BLANK,BLANK,
};






void initial_board()
{
    printf("\n");
    for (v = 0; v < 8; v++)
    {

        for (h = 0; h < 8; h++)
        {
            if (board[v][h] == BLACK)
            {
                board_view[v][h] == 1;
                printf(" x ");
            }
            else if (board[v][h] == WHITE)
            {
                board_view[v][h] == 2;
                printf(" o ");

            }
            else
            {
                board_view[v][h] == 0;
                printf(" - ");
            }
        };

        printf("\n");
    };
    get_input();
};

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
        game_start();
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
void game_start()
{
    printf("\nRemember: Blacks start first.\n");
    initial_board();

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

    system("pause");
    return 0;
};