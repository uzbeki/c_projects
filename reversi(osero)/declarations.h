
#include <ctype.h>   //for confirming user input
#include <stdbool.h> //for using bool
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WHITE 0
#define BLACK 1
#define BLANK 2
#define OK 3
#define BOARD_SIZE 8
#define COLOR_GREEN   "\x1b[32m"
#define COLOR_CYAN    "\x1b[37m"
#define COLOR_RED    "\x1b[31m"
#define COLOR_RESET   "\x1b[30m"

enum {
  LEFT = 0,
  RIGHT,
  UP,
  DOWN,
  LEFT_UP,
  LEFT_DOWN,
  RIGHT_UP,
  RIGHT_DOWN,
  DIRECTION_MAX,
};

char direction_point[DIRECTION_MAX][2] = {
  {0,-1},    // left (a,b-1)
  {0,+1},      // right (a,b+1)
  {-1,0},      // up (a-1,b)
  {+1,0},      // down (a+1,b)
  {-1,-1},      // left up (a-1,b-1)
  {+1,-1},      // left down (a+1,b-1)
  {-1,+1},      // right up (a-1,b+1)
  {+1,+1},      // right down (a+1,b+1)
};

void show_help();

int current_player = BLACK;
int opposite_player = WHITE;
int winning = BLANK;
int black_count, white_count, blank_count, ok_count, v, h, ver, hor, ver, hor;
bool game_over = false;
