#include <stdlib.h>
#include <stdio.h>
#include <string.h>
// choose_side() ==> game_start(p1, p2)

void game_start(char player1[1], char player2[1]);

int main()
{

    game_start("x", "o");
    return 0;
};
void draw_board()
{
    // board head
    printf("\n    <-horizontal->\n    1 2 3 4 5 6 7 8\n  +-----------------\n");
    
    // board body
};

void game_start(char player1[1], char player2[1])
{
    printf("Remember: Player 2 starts first.");
    draw_board();
};
