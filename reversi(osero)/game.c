/*  REVERSI game.
      author: Bekhruz Otaev
      e-mail: beki@asterone.co.jp
      date:   November 27, 2020
    The game runs smoothly on Windows with Japanese Lanaguage Support.*/
#include "declarations.h" // all declared variables, functions, etc 

/* ################################
        Board template
################################ */
char board[BOARD_SIZE][BOARD_SIZE] = {
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
        Welcome Message
################################ */
void welcome() {
  void exit(int status);
  char choice[1];
  printf(
    "\n***********************************\nWelcome to the Reversi(Osero) "
    "game!\n***********************************\n\nPress S to start the game\nPress H to see the help page\nPress Q to "
    "quit the game\n==> ");
  scanf("%s", &choice);

  if (strcmp(choice, "s") == 0 || strcmp(choice, "S") == 0) {
    return;
  } else if (strcmp(choice, "h") == 0 || strcmp(choice, "H") == 0) {
    show_help();
  } else if (strcmp(choice, "q") == 0 || strcmp(choice, "Q") == 0) {
    exit(0);
  } else {
    system("@cls||clear");
    printf(COLOR_RED "Invalid input.\nPlease choose one from 's','h' or 'q'." COLOR_RESET);
    welcome();
  }
};

/* ################################
    possible moving spots
    for current_player
################################ */
void possible(int a, int b, int direction) {
  int a_changed = direction_point[direction][0];
  int b_changed = direction_point[direction][1];
  bool flag = false;
  int i, j;
  for (i = a + a_changed, j = b + b_changed; i >= 0 && j >= 0 && i < BOARD_SIZE && j < BOARD_SIZE; i += a_changed, j += b_changed) {
    if (board[i][j] == opposite_player) {
      flag = true;
      continue;
    } else if (board[i][j] == BLANK) {
      if (flag == true) {
        board[i][j] = OK;
        ok_count++;
      }
      return;
    }
    return;
  }
}

void possible_moves() {
  for (size_t v = 0; v < BOARD_SIZE; v++) {
    for (size_t h = 0; h < BOARD_SIZE; h++) {
      if (board[v][h] == current_player) {
        for (int direction = 0; direction < DIRECTION_MAX; direction++) {
          possible(v, h, direction);
        }
      }
    }
  }
  if (ok_count <= 0) {
    game_over = true;
  }
}

// resets possible moves
void possible_move_reset() {
  for (v = 0; v < BOARD_SIZE; v++) {
    for (h = 0; h < BOARD_SIZE; h++) {
      if (board[v][h] == OK) {
        board[v][h] = BLANK;
      }
    }
  }
  ok_count = 0;
}

// changes player turns from white to black and vice versa
void change_player() {
  possible_move_reset();
  current_player = (current_player + 1) % 2;
  opposite_player = (current_player + 1) % 2;
  possible_moves();
}

/* ################################
  check whether pieces can be
  outflanked for the current_player
################################ */
void check(int a, int b, int direction) {
  int a_changed = direction_point[direction][0];
  int b_changed = direction_point[direction][1];
  bool flag = false;
  int i, j, q, w;
  for (i = a + a_changed, j = b + b_changed; i >= 0 && j >= 0 && i < BOARD_SIZE && j < BOARD_SIZE; i += a_changed, j += b_changed) {
    if (board[i][j] == opposite_player) {
      flag = true;
      continue;
    } else if (board[i][j] == current_player) {
      if (flag) {
        for (q = ver + a_changed, w = hor + b_changed; q != i || w != j; q += a_changed, w += b_changed) {
          board[q][w] = current_player;
        }
      }
      return;
    }
    return;
  }
}

void check_all(int a, int b) {
  for (int direction = 0; direction < DIRECTION_MAX; direction++) {
    check(a, b, direction);
  }
}

// checks if input position is ok
bool is_ok(int a, int b) {
  if (board[a][b] == OK) {
    return true;
  } else {
    return false;
  }
};

/* Function that checks if the game is over */
void is_over() {
  if (black_count == 0 || white_count == 0) {
    game_over = true;
  } else if (black_count + white_count >= (BOARD_SIZE * BOARD_SIZE) - 1) {
    game_over = true;
  }
}

/* ################################
    draw the board on the console
################################### */
void draw_board() {
  black_count = 0;
  white_count = 0;
  blank_count = 0;
  printf("\n     1   2   3   4   5   6   7   8");
  printf("\n");
  for (v = 0; v < 8; v++) {
    printf("\n %d ", v + 1);
    for (h = 0; h < 8; h++) {
      if (board[v][h] == BLACK) {
        black_count++;
        printf("  x ");
      } else if (board[v][h] == WHITE) {
        white_count++;
        printf("  ○ ");
      } else if (board[v][h] == OK) {
        printf(COLOR_RED "  · " COLOR_RESET);
      } else {
        blank_count++;
        printf(COLOR_CYAN "  - " COLOR_RESET);
      }
    };
    printf("\n");
  };

  if (black_count > white_count) {
    winning = BLACK;
    printf(COLOR_GREEN "\nScores: BLACK(%d) > WHITE(%d)" COLOR_RESET, black_count, white_count);
  } else if (black_count < white_count) {
    winning = WHITE;
    printf(COLOR_GREEN "\nScores: BLACK(%d) < WHITE(%d)" COLOR_RESET, black_count, white_count);
  } else {
    winning = BLANK;
    printf(COLOR_GREEN "\nScores: BLACK(%d) = WHITE(%d)" COLOR_RESET, black_count, white_count);
  }
};

/* #################################
    getting vertical and horizontal
    location input from the user
################################### */
void get_input() {
  char str[30];
  char* ptr;
  if (current_player == BLACK) {
    printf("\n\n\tBLACK [x] moves\n");
  } else {
    printf("\n\n\tWHITE [o] moves\n");
  }
  printf("vertical position ==> ");
  scanf("%s", str);
  ver = strtol(str, &ptr, 0);
  printf("horizontal position ==> ");
  scanf("%s", str);
  hor = strtol(str, &ptr, 0);
  if (ver <= 0 || hor <= 0 || hor > BOARD_SIZE || ver > BOARD_SIZE) {
    printf(COLOR_RED "\nPlease enter the baord numbers(1-8) only" COLOR_RESET, ver, hor);
    get_input();
  } else {
    ver--;
    hor--;
    if (!is_ok(ver, hor)) {
      printf(COLOR_RED "\nSorry, (%d,%d) is not available. \nPlease choose one of the red spots" COLOR_RESET,
        ver + 1, hor + 1);
      get_input();
    }
    board[ver][hor] = current_player; //put the piece on the board
  }
}

/* ########################################
        Game over function
############################################# */
void finish() {
  printf("\n#######################################");
  if (winning == WHITE) {
    printf("\nThe black side lost.\nBlack - %d, White - %d", black_count, white_count);
    printf("\n\nWinner:\t****WHITE****\n");
  } else if (winning == BLACK) {
    printf("\nThe white side lost.\nWhite - %d, Black - %d", white_count, black_count);
    printf("\n\nWinner:\t****BLACK****\n");
  } else {
    printf("\nIt is a draw!!! Black - %d, White - %d\n", black_count, white_count);
  }
  printf("#######################################\n");
  system("pause");
}

/* ################################
    the help page that explains
    game basics, moves, and end.
################################ */
void show_help() {
  char back[1];
  printf("\n:::::OBJECTIVE:::::\nThe objective for each of the players is to "
    "finish the game \nwith more pieces on the board in his own colour "
    "than the opponent.\n""\n\t\t ::::How the game goes on::::\n\n::::START OF THE "
    "GAME::::\nThe player with black pieces \nmoves "
    "first; one only move is made every turn.\n""\n::::MOVES::::\nA move consists in placing from outside one piece "
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
    "move, turn is forfeited \nand the opponent repeats another move.\n"
    "\n::::FINAL::::\nThe game is over when all the squares of the board are "
    "taken or none of \nthe players can move. In any case the winner is the "
    "player who has more \npieces on the board. The game ends in a draw when "
    "both players have the \nsame number of pieces on the board.\n\n");
  printf("\tpress B to go back to the main menu \n\nwrite here ==> ");
  scanf("%s", back);
  if (strcmp(back, "b") == 0 || strcmp(back, "B") == 0) {
    system("@cls||clear");
    welcome();
  } else {
    system("@cls||clear");
    show_help();
  }
};

/* ################################
         main function
################################ */
int main() {
  system("COLOR F0"); /* This will change the bgcolor F - White and textcolor to 2- Green */
  welcome();
  system("@cls||clear");
  possible_moves();
  while (!game_over) {
    draw_board();
    get_input();
    check_all(ver, hor);
    change_player();
    is_over();
  }
  finish();
  return 0;
};