/*
    REVERSI game also called OSERO in Japan.

    author: Bekhruz Otaev
    e-mail: beki@asterone.co.jp
    date:   November 20, 2020
*/

// header files
#include <ctype.h>   //for confirming user input
#include <stdbool.h> //for using bool
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* DECLARATIONS */
#define BLANK 2
#define BLACK 1
#define WHITE 0
#define OK 3

void show_help();
void draw_board(char p, int a, int b);
void initial_board();
void game_start();
void game_over();
void get_input(int p);
void hint_clear();
void check_all(int a, int b);

// variables
char board[8][8];
int v, h;
int current_player = BLACK;
int opposite_player = WHITE;
int black_count = 0;
int white_count = 0;
int empty_count = 0;
int empty_list[8][2];
int init_left;
int init_a;
int init_b;

/* ################################
    Functions that look for
    possible moving spots
    for current_player
################################ */
void possible_left(int a, int b)
{
  for (b < 0; b--;)
  {
    if (board[a][b] == opposite_player)
    {
      // printf("\nleft opposite[%d](%d, %d) found. checking again...\n",
      // opposite_player, a, b);
      possible_left(a, b);
    }
    else if (board[a][b] == BLANK)
    {
      if (board[a][b + 1] == opposite_player)
      {
        board[a][b] = OK;
      }
    }
    else if (board[a][b] == current_player)
    {
      break;
    }
  }
}

void possible_right(int a, int b)
{
  int i = b + 1;
  for (; i < 8; i++)
  {
    if (board[a][i] == opposite_player)
    {
      // printf("\nright opposite[%d](%d, %d) found. checking again...\n",
      // opposite_player, a, i);
      possible_right(a, i);
    }
    else if (board[a][i] == BLANK)
    {
      if (board[a][i - 1] == opposite_player)
      {
        board[a][i] = OK;
      }
    }
    else if (board[a][i] == current_player)
    {
      break;
    }
  }
}

void possible_up(int a, int b)
{
  int i = a - 1;
  for (i; i > -1; i--)
  {
    if (board[i][b] == opposite_player)
    {
      // printf("\nup opposite[%d](%d, %d) found. checking again...\n",
      // opposite_player, i, b);
      possible_up(i, b);
    }
    else if (board[i][b] == BLANK)
    {
      if (board[i + 1][b] == opposite_player)
      {
        board[i][b] = OK;
      }
    }
    else if (board[i][b] == current_player)
    {
      break;
    }
  }
}

void possible_down(int a, int b)
{
  int i = a + 1;
  for (i; i < 8; i++)
  {
    if (board[i][b] == opposite_player)
    {
      // printf("\ndown opposite[%d] (%d, %d)found. checking again...\n",
      // opposite_player, i, b);
      possible_down(i, b);
    }
    else if (board[i][b] == BLANK)
    {
      if (board[i - 1][b] == opposite_player)
      {
        board[i][b] = OK;
      }
    }
    else if (board[i][b] == current_player)
    {
      break;
    }
  }
}

void possible_left_up(int a, int b)
{
  int initial_A = a;
  int initial_B = b;
  int i = a - 1;
  int j = b - 1;
  while (i > -1 && j > -1)
  {
    if (board[i][j] == opposite_player)
    {
      // printf("\nleft up opposite[%d] (%d, %d)found. checking again...\n",
      // opposite_player, i, j);
      possible_left_up(i, j);
    }
    else if (board[i][j] == BLANK)
    {
      if (board[i + 1][j + 1] == opposite_player)
      {
        board[i][j] = OK;
      }
    }
    else if (board[i][j] == current_player)
    {
      break;
    }
    i--;
    j--;
  }
}

void possible_right_up(int a, int b)
{
  int initial_A = a;
  int initial_B = b;

  int i = a - 1;
  int j = b + 1;
  while (i > -1 && j > -1 && i < 8 && j < 8)
  {
    if (board[i][j] == opposite_player)
    {
      // printf("\nright up opposite[%d](%d, %d) found. checking again...\n",
      // opposite_player, i, j);
      possible_right_up(i, j);
    }
    else if (board[i][j] == BLANK)
    {
      if (board[i + 1][j - 1] == opposite_player)
      {
        board[i][j] = OK;
      }
    }
    else if (board[i][j] == current_player)
    {
      break;
    }
    i--;
    j++;
  }
}

void possible_left_down(int a, int b)
{
  int initial_A = a;
  int initial_B = b;

  int i = a + 1;
  int j = b - 1;
  while (i < 8 && j < 8 && i >= 0 && j >= 0)
  {
    if (board[i][j] == opposite_player)
    {
      // printf("\nleft down opposite[%d] (%d, %d)found. checking again...\n",
      // opposite_player, i, j);
      possible_left_down(i, j);
    }
    else if (board[i][j] == BLANK)
    {
      if (board[i - 1][j + 1] == opposite_player)
      {
        board[i][j] = OK;
      }
    }
    else if (board[i][j] == current_player)
    {
      break;
    }
    i++;
    j--;
  }
}

void possible_right_down(int a, int b)
{
  int initial_A = a;
  int initial_B = b;
  int i = a + 1;
  int j = b + 1;
  while (i < 8 && j < 8 && i > -1 && j > -1)
  {
    if (board[i][j] == opposite_player)
    {
      // printf("\nright down opposite(%d, %d) found. checking again...\n", i,
      // j);
      possible_right_down(i, j);
    }
    else if (board[i][j] == BLANK)
    {
      if (board[i - 1][j - 1] == opposite_player)
      {
        board[i][j] = OK;
      }
    }
    else if (board[i][j] == current_player)
    {
      break;
    }
    i++;
    j++;
  }
}

void possible_all(int a, int b)
{
  possible_left(a, b);
  possible_right(a, b);
  possible_up(a, b);
  possible_down(a, b);
  possible_left_up(a, b);
  possible_right_up(a, b);
  possible_left_down(a, b);
  possible_right_down(a, b);
}

void possible_moves()
{
  // printf("\n\tcalculating POSSIBLE MOVES\n");
  for (size_t v = 0; v < 8; v++)
  {
    for (size_t h = 0; h < 8; h++)
    {
      if (board[v][h] == current_player)
      {
        possible_all(v, h);
      }
    }
  }
}

// resets possible moves
void possible_move_reset()
{
  // printf("\n\tERASING POSSIBLE MOVES\n");
  for (v = 0; v < 8; v++)
  {
    for (h = 0; h < 8; h++)
    {
      if (board[v][h] == OK)
      {
        board[v][h] = BLANK;
        //    printf("\n\tCHanging (%d,%d) into blanks",v,h);
      }
    }
  }
}

// changes player turns from white to black and vice versa
void change_player()
{
  possible_move_reset();
  current_player = (current_player + 1) % 2;
  opposite_player = (current_player + 1) % 2;
  // printf("\n\n......PLayer changed....\n");
  possible_moves();
}

/* ################################
    Functions that check
    left, right, up, down,
    left_up, right_up, left_down,
    right_down for the
    current_player
################################ */
void check_left(int a, int b)
{
  // int initial_location = b;
  // printf("initial_location: %d", init_b);
  // printf("\n");
  // printf("left ");
  for (b < 0; b--;)
  {
    // printf(" ==> %d(%d,%d)", board[a][b], a,b);
    if (board[a][b] == opposite_player)
    {
      // printf("\nopposite[%d] found. checking again...\n", opposite_player);

      check_left(a, b);
    }
    else if (board[a][b] == current_player)
    {
      if (board[a][b + 1] == opposite_player)
      {
        // turn every piece till initial locaiton to current
        // printf("initial_location: %d", init_b);
        for (size_t q = b; q < init_b; q++)
        {
          // printf("\n(%d,%d)changed into %d)", a,q+1, current_player);
          board[a][q + 1] = current_player;
        }
        check_left(a, b + 1); // change applied her. it was b+1
      }
    }
    else if (board[a][b] == BLANK)
    {
      break;
    }
    break;
  }
}

// right   == board(v,h+1) till h=7
void check_right(int a, int b)
{
  const int initial_location = b;
  int i = b + 1;
  // printf("\nright ");
  for (; i < 8; i++)
  {
    // printf(" ==> %d(%d,%d)", board[a][i],a,i);
    if (board[a][i] == opposite_player)
    {
      // printf("\nopposite[%d] found. checking again...\n", opposite_player);
      check_right(a, i);
    }
    else if (board[a][i] == current_player)
    {
      if (board[a][i - 1] == opposite_player)
      {
        for (size_t q = i; q >= initial_location; q--)
        {
          // printf("\n(%d,%d)changed into %d)", a,q-1, current_player);
          board[a][q - 1] = current_player;
        }
        check_right(a, i - 1);
      }
    }
    else if (board[a][i] == BLANK)
    {
      break;
    }
  }
}

// up == board(v-1,h) till v=0
void check_up(int a, int b)
{
  const int initial_location = a;
  // printf("\nup ");
  int i = a - 1;
  for (i; i > -1; i--)
  {
    // printf("  ==> %d(%d,%d)", board[i][b], i, b);
    if (board[i][b] == opposite_player)
    {
      // printf("\nopposite[%d] found. checking again...\n", opposite_player);
      check_up(i, b);
    }
    else if (board[i][b] == current_player)
    {
      if (board[i + 1][b] == opposite_player)
      {
        for (size_t q = i; q <= initial_location; q++)
        {
          // printf("\n(%d,%d)changed into %d)", q+1, b, current_player);
          board[q + 1][b] = current_player;
        }
        // board[i+1][b]=current_player;
        check_up(i + 1, b); //[BUG] it could be check_up(i+1,b);
      }
    }
    else if (board[i][b] == BLANK)
    {
      break;
    }
  }
}

// down == board(v+1,h) till v=7
void check_down(int a, int b)
{
  int initial_location = a;
  int i = a + 1;
  // printf("\ndown ");
  for (i; i < 8; i++)
  {
    // printf("  ==> %d(%d,%d)", board[i][b],i,b);
    if (board[i][b] == opposite_player)
    {
      // printf("\nopposite[%d] found. checking again...\n", opposite_player);
      check_down(i, b);
    }
    else if (board[i][b] == current_player)
    {
      if (board[i - 1][b] == opposite_player)
      {
        for (size_t q = i; q > initial_location && q > 0; q--)
        {
          // printf("\n(%d,%d)changed into %d)", q-1, b, current_player);
          board[q - 1][b] = current_player;
        }

        // board[i-1][b]=current_player;
        check_down(i - 1, b);
      }
    }
    else if (board[i][b] == BLANK)
    {
      break;
    }
  }
}

// left up == board(v-1,h-1) till either v=0 || h=0
void check_left_up(int a, int b)
{
  int initial_A = a;
  int initial_B = b;

  // printf("\nleft-up ");
  int i = a - 1;
  int j = b - 1;
  while (i > -1 && j > -1)
  {
    // printf(" %d(%d,%d) ==> ",board[i][j], i,j);
    if (board[i][j] == opposite_player)
    {
      // board[i][j]=current_player;
      // printf("\nopposite[%d] found. checking again...\n", opposite_player);
      // i--;
      // j--;
      check_left_up(i, j);
    }
    else if (board[i][j] == current_player)
    {
      if (board[i + 1][j + 1] == opposite_player)
      {
        // printf("\nopposite found after current. should go into for loop\n");
        for (i, j; i < initial_A || j < initial_B; i++, j++)
        {
          // printf("i,j(%d,%d) changing intto %d \n",i, j, current_player);
          board[i + 1][j + 1] = current_player;
        }

        // board[i+1][j+1]=current_player;
        check_left_up(i, j);
      }
    }
    else if (board[i][j] == BLANK)
    {
      break;
    }
    i--;
    j--;
  }
}

// right up  == board(v-1,h+1) till either v=0 || h=0
void check_right_up(int a, int b)
{
  int initial_A = a;
  int initial_B = b;

  // printf("\nright-up ");
  int i = a - 1;
  int j = b + 1;
  while (i > -1 && j > -1 && i < 8 && j < 8)
  {
    // printf(" %d(%d,%d) ==> ",board[i][j], i,j);
    if (board[i][j] == opposite_player)
    {
      // board[i][j]=current_player;
      // printf("\nopposite[%d] found. checking again...\n", opposite_player);
      check_right_up(i, j);
    }
    else if (board[i][j] == current_player)
    {
      if (board[i + 1][j - 1] == opposite_player)
      {
        // printf("\nopposite found after current. should go into for loop\n");
        for (i, j; i < initial_A || j < initial_B; i++, j--)
        {
          // printf("i,j(%d,%d) changing intto %d \n",i, j, current_player);
          board[i + 1][j - 1] = current_player;
        }
        // board[i+1][j-1]=current_player;
        check_right_up(i, j);
      }
    }
    else if (board[i][j] == BLANK)
    {
      break;
    }
    i--;
    j++;
  }
}

// left down  == board(v+1,h-1) till either v=7 || h=7
void check_left_down(int a, int b)
{
  int initial_A = a;
  int initial_B = b;

  // printf("\nleft-down ");
  int i = a + 1;
  int j = b - 1;
  while (i < 8 && j < 8 && i >= 0 && j >= 0)
  {
    // printf(" %d(%d,%d) ==> ",board[i][j], i,j);
    if (board[i][j] == opposite_player)
    {
      // board[i][j]=current_player;
      // printf("\nopposite[%d] found. checking again...\n", opposite_player);
      check_left_down(i, j);
    }
    else if (board[i][j] == current_player)
    {
      if (board[i - 1][j + 1] == opposite_player)
      {
        // printf("\nopposite found after current. should go into for loop\n");
        for (i, j; i < initial_A || j < initial_B; i--, j++)
        {
          // printf("i,j(%d,%d) changing into %d \n",i, j, current_player);
          board[i - 1][j + 1] = current_player;
        }

        // board[i-1][j+1]=current_player;
        check_left_down(i, j);
      }
    }
    else if (board[i][j] == BLANK)
    {
      break;
    }
    i++;
    j--;
  }
}

// right down == board(v+1,h+1) till either v=7 || h=7
void check_right_down(int a, int b)
{
  int initial_A = a;
  int initial_B = b;
  // printf("\nright-down ");
  int i = a + 1;
  int j = b + 1;
  while (i < 8 && j < 8 && i > -1 && j > -1)
  {
    // printf(" %d(%d,%d) ==> ",board[i][j], i,j);
    if (board[i][j] == opposite_player)
    {
      // board[i][j]=current_player;
      // printf("\nopposite found. checking again...\n");
      check_right_down(i, j);
    }
    else if (board[i][j] == current_player)
    {
      if (board[i - 1][j - 1] == opposite_player)
      {
        // printf("\nopposite found after current. should go into for loop\n");
        for (i, j; i > initial_A || j > initial_B; i--, j--)
        {
          // printf("i,j(%d,%d) changing into %d \n",i, j, current_player);
          board[i - 1][j - 1] = current_player;
        }

        // board[i-1][j-1]=current_player;
        check_right_down(i, j);
      }
    }
    else if (board[i][j] == BLANK)
    {
      break;
    }
    i++;
    j++;
  }
}

void check_all(int a, int b)
{
  // printf("\n");

  check_left(a, b);
  check_right(a, b);
  check_up(a, b);
  check_down(a, b);
  check_left_up(a, b);
  check_right_up(a, b);
  check_left_down(a, b);
  check_right_down(a, b);
}

// checks if input position is blank
bool is_blank(int a, int b)
{
  possible_moves();
  if (board[a][b] == OK)
  {
    // board[a][b]=BLANK;
    return true;
  }
  else
  {
    return false;
    /* code */
  }
};

/* ################################
    draw_board function to draw
    the board on the console
    after get_input
################################ */
void draw_board(char player, int a, int b)
{
  // possible_moves();
  change_player();
  black_count = 0;
  white_count = 0;
  empty_count = 0;
  printf("\n     1   2   3   4   5   6   7   8");
  printf("\n");
  for (v = 0; v < 8; v++)
  {
    printf("\n");
    printf(" %d ", v + 1);
    for (h = 0; h < 8; h++)
    {
      if (board[v][h] == BLACK)
      {
        black_count++;
        printf("  ● ");
      }
      else if (board[v][h] == WHITE)
      {
        white_count++;
        printf("  ○ ");
      }
      else if (a == v && b == h)
      {
        if (player == BLACK)
        {
          board[a][b] = BLACK;
          black_count++;
          printf("  ● ", board[a][b]);
        }
        else
        {
          white_count++;
          printf("  ○ ", board[a][b]);
          board[a][b] = WHITE;
        }

        // board_view[a][b] == 1;
      }
      else if (board[v][h] == OK)
      {
        printf("  · ");
      }
      else
      {
        // board_view[v][h] == 0;
        empty_count++;
        printf("  - ");
      }
    };
    printf("\n");
  };

  possible_move_reset();
  // count(&black_count, &white_count, &empty_count);
  // UNFINISHED
  if (black_count == 0)
  {
    // printf("\nBlacks lost");
    // printf("\n\twinner - ****WHITE****");
    game_over();
  }
  else if (white_count == 0)
  {
    // printf("\nBlacks lost");
    // printf("\n\twinner - ****WHITE****");
    game_over();
  }
  else if (empty_count == 0 || black_count + white_count >= 64)
  {
    // printf("\nBlacks lost");
    // printf("\n\twinner - ****WHITE****");
    game_over();
  }
  printf("Scores: x=%d, o=%d\n", black_count, white_count);

  get_input(current_player);
};

/* ################################
    get_input function to get
    vertical and horizontal
    location input from the user
################################ */
void get_input(int player)
{
  // hint_clear();
  int ver, hor;
  if (current_player == BLACK)
  {
    printf("\tBLACK [x] moves\n");
  }
  else
  {
    printf("\tWHITE [o] moves\n");
  }

  printf("vertical position ==> ");
  scanf("%d", &ver);
  printf("horizontal position ==> ");
  scanf("%d", &hor);
  ver--;
  hor--;
  // is_blank(ver, hor);

  if (is_blank(ver, hor))
  {
    // possible_move_reset();
    init_a = ver;
    init_b = hor;

    // next_move();
    check_all(ver, hor);

    // hint_show();
    // printf("\ndrawing on (%d, %d)....\n", ver, hor);
    // possible_moves();
    draw_board(player, ver, hor);
  }
  else
  {
    printf("\nSorry, (%d,%d) is not permitted. Please choose another spot\n",
           ver + 1, hor + 1);
    get_input(current_player);
  }
}

/* ################################
        Board template
################################ */
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

/* ################################
    very first board the user
    sees when he/she starts
    the game (used only once)
################################ */
void initial_board()
{
  printf("\n     1   2   3   4   5   6   7   8");
  printf("\n");
  for (v = 0; v < 8; v++)
  {
    printf("\n");
    printf(" %d ", v + 1);
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
        printf("  · ");
      }
      else
      {
        // board_view[v][h] == 0;
        printf("  - ");
      }
    };

    printf("\n");
  };
  possible_move_reset();
  printf(
      "\nWhere do you want to put your piece?\nex.if vertical 4 and horizontal "
      "5, please input 4 and 5\n");
  get_input(current_player);
};

/* ################################
        1. Welcome Message
################################ */
void welcome()
{
  void exit(int status);
  char choice[1];
  printf(
      "\n***********************************\nWelcome to the Reversi(Osero) "
      "game!\n***********************************\n");
  printf(
      "\nPress S to start the game\nPress H to see the help page\nPress Q to "
      "quit the game\n==> ");
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
        Game start function
    After user starts the game,
    this function
    1. clears the console
    2. prints out a statement
    3. calculates the possible
    moves
    4. draws the initial board
################################ */
void game_start()
{
  system("@cls||clear");
  printf("\nRemember: Blacks start first.\n");
  possible_moves();
  initial_board();
  // draw_board();
};

/* ################################
            Game over
################################ */
void game_over()
{
  if (black_count == 0 && white_count == 64)
  {
    printf("\nThe black side lost with %d to %d", black_count, white_count);
    printf("\n\twinner - ****WHITE****\n");
  }
  else if (white_count == 0 && black_count == 64)
  {
    printf("\nThe white side lost with %d to %d", white_count, black_count);
    printf("\n\twinner - ****BLACK****\n");
  }
  else if (black_count + white_count == 64)
  {
    if (black_count > white_count)
    {
      printf("\nThe white side lost with %d to %d", white_count, black_count);
      printf("\n\twinner - ****BLACK****\n");
    }
    else if (black_count < white_count)
    {
      printf("\nThe black side lost with %d to %d", black_count, white_count);
      printf("\n\twinner - ****WHITE****\n");
    }
  }
}

/* ################################
    show_help function shows
    the help page that explains
    game basics, moves, and end.

    I used struct to practice using
    structs in C.
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

  strcpy(Help1.description,
         "\n:::::description:::::\nReversi is an ancient game whose "
         "description is uncertain.\nThe oldest references about similar games "
         "go back to late \nin the 19th century; those games had different "
         "names and \ntheir boards had different size or shape. In 1870 "
         "appeared \na similar game using a cross shape board. Subsequently "
         "appeared \nanother game played on a 8x8 square shape board.\n");
  strcpy(Help1.origin,
         "\n:::::ORIGIN:::::\nReversi is an ancient game whose description is "
         "uncertain.\nThe oldest references about similar games go back to "
         "late \nin the 19th century; those games had different names and "
         "\ntheir boards had different size or shape. In 1870 appeared \na "
         "similar game using a cross shape board. Subsequently appeared "
         "\nanother game played on a 8x8 square shape board.\n");
  strcpy(Help1.description,
         "\n:::::DESCRIPTION:::::\nTwo players take part in this game; they "
         "need a board with 64 \nsquares distributed in 8 rows and 8 columns, "
         "and 64 similar \npieces of two colours (normally black and white): "
         "the obverse \nin one colour and the reversi in the other colour.\n");
  strcpy(Help1.objective,
         "\n:::::OBJECTIVE:::::\nThe objective for each of the players is to "
         "finish the game \nwith more pieces on the board in his own colour "
         "than the opponent.\n");
  strcpy(Help1.start,
         "\n\t\t ::::How the game goes on::::\n\n::::START OF THE "
         "GAME::::\nBefore starting players decide which colour will use each "
         "of \nthem. Next 4 pieces have to be placed in the central squares "
         "\nof the board, so that each pair of pieces of the same colour "
         "\nform a diagonal between them. The player with black pieces \nmoves "
         "first; one only move is made every turn.\n");
  strcpy(Help1.moves,
         "\n::::MOVES::::\nA move consists in placing from outside one piece "
         "on the board. \nPlaced pieces can never be moved to another square "
         "later in the \ngame. The incorporation of the pieces must be made "
         "according to \nthe following rules: \n - The incorported piece must "
         "outflank one or more of the \nopponent placed pieces.\n - To "
         "outflank means that a single piece or one straight row (vertical, "
         "\nhorizontal or diagonal) of pieces of the opponent is in both sides "
         "\nnext to own pieces, with no empty squares between all those "
         "pieces\n - The player who makes the move turns the outflanked pieces "
         "over, \nbecoming all of them in own pieces.\n - If there is more "
         "than one outflanked row, all the involved pieces \nin those rows "
         "have to be flipped.\n - If it's not possible to make this kind of "
         "move, turn is forfeited \nand the opponent repeats another move.\n");
  strcpy(
      Help1.final,
      "\n::::FINAL::::\nThe game is over when all the squares of the board are "
      "taken or none of \nthe players can move. In any case the winner is the "
      "player who has more \npieces on the board. The game ends in a draw when "
      "both players have the \nsame number of pieces on the board.\n");

  printf("%s", Help1.origin);
  printf("%s", Help1.description);
  printf("%s", Help1.objective);
  printf("%s", Help1.start);
  printf("%s", Help1.moves);
  printf("%s\n", Help1.final);

  printf("\tpress B to go back to the main menu \n");
  printf("\nwrite here ==> ");
  scanf("%s", back);
  if (strcmp(back, "b") == 0 || strcmp(back, "B") == 0)
  {
    system("@cls||clear");
    welcome();
  }
  else
  {
    system("@cls||clear");
    show_help();
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