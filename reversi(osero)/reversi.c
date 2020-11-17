//creating a game REVERSI
// rules at rules.txt

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>  //for using bool

// majors
#define BLANK 2
#define BLACK 1
#define WHITE 0
#define OK 3

// declarations
// void choose_side();
void show_help();
void draw_board(char p, int a , int b);
void initial_board();
void game_start();
void get_input(int p);
char board[8][8];
int v, h;
int current_player = BLACK;
int opposite_player = WHITE;
int black_count=0;
int white_count=0;
int empty_count=0;
int empty_list[8][2];
// void clear_empty_list();
void hint_show();
void hint_clear();
// void next_move();
void check_all(int a, int b);




void hint_show(){
    for (size_t i = 0; i < 8; i++)
    {
        int a = empty_list[i][0];
        int b = empty_list[i][1];
        board[a][b]=OK;
    }
}

void hint_clear(){
    for (size_t i = 0; i < 8; i++)
    {
        int a = empty_list[i][0];
        int b = empty_list[i][1];
        board[a][b]=BLANK;
    }
    memset(empty_list, 0, sizeof(empty_list[0][0]) * 8 * 2); //stackoverflow
}




// changes player turns from white to black and vice versa
void change_player(){
    current_player = (current_player +1) % 2;
    opposite_player = (current_player +1) % 2;
    // clear_empty_list();
}



// GOTTA WORK ON THIS*****************************************************
// left  == board(v, h-1) till h=0
void check_left(int a, int b){
    
    printf("\n");
    printf(" the left side ");
    // int left=board[a][b-1];
    for (b < 0; b--;)
    {
        printf(" ==> %d(%d,%d)", board[a][b], a,b);
        if (board[a][b]==opposite_player)
        {

            check_left(a,b);
            board[a][b]=current_player;
            printf("opposite changed into current player...");
            continue;
        }else if (board[a][b]==current_player)
        {
            break;
        }else if (board[a][b]==BLANK)
        {
            empty_list[0][0]=a;
            empty_list[0][1]=b;
            // board[a][b]==OK;
            break;
        }
    }
    

}


// right   == board(v,h+1) till h=7
void check_right(int a, int b){
    int i=b+1;
    printf("\nthe right side is ");
    // int left=board[a][b-1];
    while (i<8)
    {
        
        printf(" ==> %d(%d,%d)", board[a][i],a,i);
        if (board[a][i]==opposite_player)
        {
            check_right(a,i);
            board[a][i]=current_player;
            printf("opposite changed into current player...");
            i++;
            continue;
        }else if (board[a][i]==current_player)
        {
            break;
        }else if (board[a][i]==BLANK)
        {
            empty_list[1][0]=a;
            empty_list[1][1]=i;
            // board[a][i]==OK;
            break;
        }
        i++;
    }
}


// up == board(v-1,h) till v=0
void check_up(int a, int b){
    printf("\nthe up side is ");
    int i=a-1;
    while (i>-1)
    {
        printf("  ==> %d(%d,%d)", board[i][b], i, b);
        if (board[i][b]==opposite_player)
        {
            check_up(i,b);
            board[i][b]=current_player;
            printf("opposite changed into current player...");
            i--;
            continue;
        }else if (board[i][b]==current_player)
        {
            break;
        }else if (board[i][b]==BLANK)
        {
            empty_list[2][0]=i;
            empty_list[2][1]=b;
            // board[i][b]=OK;
            break;
        }
        i--;
    }
    

}


// down == board(v+1,h) till v=7
void check_down(int a, int b){
    int i=a+1;
    printf("\nthe down side is ");
    while (i<8)
    {
        printf("  ==> %d(%d,%d)", board[i][b],i,b);
        if (board[i][b]==opposite_player)
        {
            check_down(i,b);
            board[i][b]=current_player;
            printf("opposite changed into current player...");
            i++;
            continue;
        }else if (board[i][b]==current_player)
        {
            break;
        }else if (board[i][b]==BLANK)
        {
            empty_list[3][0]=i;
            empty_list[3][1]=b;
            // board[i][b]=OK;
            break;
        }
        i++;
    }
    
}


// left up == board(v-1,h-1) till either v=0 || h=0
void check_left_up(int a, int b){
    printf("\nthe left-up side is ");
    int i= a-1;
    int j = b-1;
    while (i>-1 && j>-1)
    {
        printf(" %d(%d,%d) ==> ",board[i][j], i,j);
        if (board[i][j]==opposite_player)
        {
            check_left_up(i,j);
            board[i][j]=current_player;
            printf("opposite changed into current player...");
            i--;
            j--;
            continue;
        }else if (board[i][j]==current_player)
        {
            break;
        }else if (board[i][j]==BLANK)
        {
            empty_list[4][0]=i;
            empty_list[4][1]=j;
            // board[i][j]=OK;
            break;
        }
        i--;
        j--;
    }
    

}


// right up  == board(v-1,h+1) till either v=0 || h=0
void check_right_up(int a, int b){
    printf("\nthe right-up side is ");
    int i= a-1;
    int j = b+1;
    while (i>-1 && j>-1 && i<8 && j<8)
    {
        printf(" %d(%d,%d) ==> ",board[i][j], i,j);
        if (board[i][j]==opposite_player)
        {
            check_right_up(i,j);
            board[i][j]=current_player;
            printf("opposite changed into current player...");
            i--;
            j++;
            continue;
        }else if (board[i][j]==current_player)
        {
            break;
        }else if (board[i][j]==BLANK)
        {
            empty_list[5][0]=i;
            empty_list[5][1]=j;
            // board[i][j]=OK;
            break;
        }
        i--;
        j++;
    }
    
}


// left down  == board(v+1,h-1) till either v=7 || h=7
void check_left_down(int a, int b){
    printf("\nthe left-down side is ");
    int i= a+1;
    int j = b-1;
    while (i<8 && j<8 && i>-1 && j>-1)
    {
        printf(" %d(%d,%d) ==> ",board[i][j], i,j);
        if (board[i][j]==opposite_player)
        {
            check_left_down(i,j);
            board[i][j]=current_player;
            printf("opposite changed into current player...");
            i++;
            j--;
            continue;
        }else if (board[i][j]==current_player)
        {
            break;
        }else if (board[i][j]==BLANK)
        {
            empty_list[6][0]=i;
            empty_list[6][1]=j;
            // board[i][j]=OK;
            break;
        }
        i++;
        j--;
    }
}


// right down == board(v+1,h+1) till either v=7 || h=7
void check_right_down(int a, int b){
    printf("\nthe right-down side is ");
    int i= a+1;
    int j = b+1;
    while (i<8 && j<8 && i>-1 && j>-1)
    {
        printf(" %d(%d,%d) ==> ",board[i][j], i,j);
        if (board[i][j]==opposite_player)
        {
            check_right_down(i,j);
            board[i][j]=current_player;
            printf("opposite changed into current player...");
            i++;
            j++;
            continue;
        }else if (board[i][j]==current_player)
        {
            break;
        }else if (board[i][j]==BLANK)
        {
            empty_list[7][0]=i;
            empty_list[7][1]=j;
            // board[i][j]=OK;
            break;
        }
        i++;
        j++;
    }
}

void check_all(int a, int b){
        
        printf("\n");
        
        check_left(a,b);
        check_right(a,b);
        check_up(a,b);
        check_down(a,b);
        check_left_up(a,b);
        check_right_up(a,b);
        check_left_down(a,b);
        check_right_down(a,b);
    }




// checks if input position is blank
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



// here I figured out how to return more than one value in one function
/* void count(int *black_count, int *white_count, int*empty_count){
    // black_count = 0;
    // white_count = 0;
    // empty_count = 0;

    for (v = 0; v < 8; v++)
    {
        for (h = 0; h < 8; h++)
        {
            if (board[v][h]==BLACK)
            {
                black_count++;
            }
            else if (board[v][h]==WHITE)
            {
                white_count++;
            }
            else
            {
                empty_count++;   
            }
        
        }
        
    }
    *black_count;
    *white_count;
    *empty_count;
}


 */



// draws the board based on the input and current player
void draw_board(char player, int a, int b){
    black_count=0;
    white_count=0;
    empty_count=0;
    printf("\n");
    for (v = 0; v < 8; v++)
    {
        for (h = 0; h < 8; h++)
        {
            if (board[v][h] == BLACK)
            {
                black_count++;
                printf(" x ");
            }
            else if (board[v][h] == WHITE)
            {
                white_count++;
                printf(" o ");

            }
            else if (board[v][h] == OK)
            {
                printf(" . ");

            }
            else if (a == v && b==h)
            {
                if (player==BLACK)
                {
                    board[a][b] = BLACK;
                    black_count++;
                    printf(" x ", board[a][b]);
                }else
                {
                    white_count++;
                    printf(" o ", board[a][b]);
                    board[a][b] = WHITE;
                    
                }
                
                
                // board_view[a][b] == 1;

            }
            else
            {
                // board_view[v][h] == 0;
                empty_count++;
                printf(" - ");
            }
        };

        printf("\n");
    };
    // count(&black_count, &white_count, &empty_count);
    
    printf("Scores: x=%d, o=%d\n", black_count, white_count);
    change_player();
    get_input(current_player);
    
};


// gets the input from players
void get_input(int player){
    
    hint_clear();
    int ver, hor;
    if (current_player==BLACK)
    {
        printf("BLACK [x] moves\n");
        
    }else
    {
        printf("WHITE [o] moves\n");
        
    }
    
    
    
    printf("vertical position==> ");
    scanf("%d", &ver);
    printf("horizontal position==> ");
    scanf("%d", &hor);
    ver--;
    hor--;
    // is_blank(ver, hor);

    if (is_blank(ver, hor))
    {
        // next_move();
        check_all(ver, hor);
        
        hint_show();
        printf("\ndrawing on (%d, %d)....\n", ver, hor);
        draw_board(player, ver, hor);
        
    }
    else
    {
        printf("\nSorry, (%d,%d) is not empty. Please choose an empty spot\n", ver, hor);
        get_input(current_player);
    }
    
}




//board starts like this
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
    hint_show();
    printf("\n");
    for (v = 0; v < 8; v++)
    {

        for (h = 0; h < 8; h++)
        {
            if (board[v][h] == BLACK)
            {
                // board_view[v][h] == 1;
                printf(" x ");
            }
            else if (board[v][h] == WHITE)
            {
                // board_view[v][h] == 2;
                printf(" o ");

            }
            else if (board[v][h] == OK)
            {
                // board_view[v][h] == 2;
                printf(" . ");

            }
            else
            {
                // board_view[v][h] == 0;
                printf(" - ");
            }
        };

        printf("\n");
    };
    printf("\nWhere do you want to put your piece?\nex.if vertical 4 and horizontal 5, please input 4 and 5\n");
    get_input(current_player);
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
        // gotta have something here to show the first hints

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
    system("@cls||clear");
    printf("\nRemember: Blacks start first.\n");
    initial_board();

};





/* ################################ 
         Help Message
################################ */
void show_help()
{
    char back[1];
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
    printf("%s\n", Help1.final);

    printf("press B to go back to the main menu \n");
    printf("write here==> ");
    scanf("%c", &back);
    if(strcmp(back, "b")==0 ||strcmp(back, "B")==0)
    {
        welcome();
        /* code */
    }
    
    

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