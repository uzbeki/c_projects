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
void draw_board();
void initial_board();
char board[8][8];
char updated_board[8][8];
int v, h;


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
        // draw_board();
    }
    else
    {
        printf("\nSorry, (%d,%d) is not empty. Please choose an empty spot\n", ver, hor);
        get_input();
    }
    
}


int main() {
    get_input();
    system("pause");
    return 0;
}


/* white=o(2) black=x(1)*/
/* 
 -  -  -  -  -  -  -  -
 -  -  -  -  -  -  -  -
 -  -  -  -  -  -  -  -
 -  -  -  x  o  -  -  -
 -  -  -  o  x  -  -  -
 -  -  -  -  -  -  -  -
 -  -  -  -  -  -  -  -
 -  -  -  -  -  -  -  -
 
  */
