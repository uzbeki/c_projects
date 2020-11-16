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
void choose_side();
void show_help();
void game_start(char player1[1], char player2[1]);
void initial_board();
char board[8][8];
char updated_board[8][8];
int p, v, h;

struct Player
{
    int side;
    char sign;
};
struct Player whites;
struct Player blacks;



void draw_board(char a, int a, int b)
{
    printf("\n");
    for (v = 0; v < 8; v++)
    {

        for (h = 0; h < 8; h++)
        {
            if (board[v][h] == BLACK)
            {
                updated_board[v][h] == 1;
                printf(" x ");
            }
            else if (board[v][h] == WHITE)
            {
                updated_board[v][h] == 2;
                printf(" o ");

            }
            else
            {
                updated_board[v][h] == 0;
                printf(" - ");
            }
        };

        printf("\n");
    };
};


int main()
{
    // assign black annd white side signs
    whites.side = 2;
    whites.sign = 'o';

    blacks.side = 1;
    blacks.sign ='x';

    draw_board(whites.sign, 4,6);
    getchar(); //just to make sure the program does not auto quit
};
