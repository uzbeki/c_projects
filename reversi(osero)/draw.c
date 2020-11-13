#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char board[8][8];
int v, h;



/* 

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
        // printf("\n");
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

int main()
{
    initial_board();
    getchar(); //just to make sure the program does not auto quit
};
