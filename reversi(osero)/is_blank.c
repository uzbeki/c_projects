#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>



int board_test[8][8];
int v, h;

// shirabemasu
#define BLACK 1
#define WHITE 2

int board_test[8][8] = { 
    0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,
    0,0,0,BLACK,WHITE,0,0,0,
    0,0,0,WHITE,BLACK,0,0,0,
    0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,
};

// [3][5]
// left [3][4] - [3][3] - [3][2]  == board(v, h-1) till h=0
// right [3][6] - [3][7]  == board(v,h+1) till h=7
// up [2][5] - [1][5] == board(v-1,h) till v=0
// down [4][5] - [5][5] == board(v+1,h) till v=7
// left up [2][4] - [1][3] == board(v-1,h-1) till either v=0 || h=0
// left down [4][4] - [5][3] == board(v+1,h-1) till either v=7 || h=7
// right up [2][6] - [1][7]  == board(v-1,h+1) till either v=0 || h=0
// right down [4][6] - [5][7] == board(v+1,h+1) till either v=7 || h=7


bool is_blank(int a, int b) 
{
    if (board_test[a][b]==0)
    {
        return true;
        /* code */
    }else
    {
        return false;
        /* code */
    }
    
};

int main() {
    
    if (is_blank(3,3))
    {
        printf("yes 3,3 is blank\n");    
        /* code */
    }
    else
    {
        printf("No 3,3 is NOT blank\n");    
        /* code */
    }
    
    system("pause");
    return 0;

}
