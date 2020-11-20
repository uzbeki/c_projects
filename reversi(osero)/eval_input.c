// header files
#include <ctype.h>    //for confirming user input
#include <stdbool.h>  //for using bool
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



#define BLANK 2
#define BLACK 1
#define WHITE 0
#define OK 3
/* DECLARATIONS */
// functions


// variables

int v,h;

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

// board shown to the user
// I might delete this alltogether...
void initial_board()
{
    printf("\n     1   2   3   4   5   6   7   8");
    printf("\n");
    for (v = 0; v < 8; v++)
    {
        printf("\n");
        printf(" %d ", v+1);
        for (h = 0; h < 8; h++)
        {
            
            if (board[v][h] == BLACK)
            {
                // board_view[v][h] == 1;
                printf("  ● ");
            }
            else if (board[v][h] == WHITE)
            {
                // board_view[v][h] == 2;
                printf("  ○ ");

            }
            else if (board[v][h] == OK)
            {
                // board_view[v][h] == 2;
                printf("  ⋆ ");

            }
            else
            {
                // board_view[v][h] == 0;
                printf("  - ");
            }
        };

        printf("\n");
    };

};


int main() {
    
    initial_board();
    
    return 0;
}
