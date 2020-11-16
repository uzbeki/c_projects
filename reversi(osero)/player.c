//creating a game REVERSI
// rules at rules.txt

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h> //for using bool

// majors
#define BLANK 0
#define BLACK 1
#define WHITE 2

// declarations
void choose_side();
void show_help();
void game_start(char Player1[1], char Player2[1]);
void draw_board();
void initial_board();
char board[8][8];
char updated_board[8][8];
int v, h;

struct Player
{
    int side;
    char sign;
};
struct Player whites;
struct Player blacks;





int main()
{
    whites.side = 2;
    whites.sign = 'o';

    blacks.side = 1;
    blacks.sign ='x';
    printf("whites : side %d, sign - %s\n", whites.side, &whites.sign);
    printf("blacks : side %d, sign - %s\n", blacks.side, &blacks.sign);
    // printf();
    system("pause");
    return 0;
}