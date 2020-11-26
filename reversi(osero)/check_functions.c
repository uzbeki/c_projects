/* 
functions that check for 
1. whether baord pieces can be outflanked
2. available spots for the current_player
 */

#include "reversi.c"



/* ################################
    Functions that check 
    whether pieces can be outflanked
    
    left -       board[a][b-1]
    right -      board[a][b+1]
    up -         board[a-1][b]
    down -       board[a+1][b]
    left_up -    board[a-1][b-1]
    right_up -   board[a-1][b+1]
    left_down -  board[a+1][b-1]
    right_down - board[a+1][b+1]
    
    for the current_player
################################ */
// left == board[a][b-1]
void check_left(int a, int b)
{
  bool flag = false;
  printf("\nleft ");
  for (int i=b-1; i>=0; i--)
  {
    printf(" ==> %d(%d,%d)", board[a][i], a,i);
    if (board[a][i] == opposite_player)
    {
      printf("\nopposite[%d] found. checking again...\n", opposite_player);
      flag=true;
      continue;
    }
    else if (board[a][i] == current_player)
    {
      if (flag==true)
      {
        for (size_t q = init_b-1; q > i; q--)
        {
          printf("\n(%d,%d)changed into %d)", a,q, current_player);
          board[a][q] = current_player;
        }
      }
      return;
    }
    else if (board[a][i] == BLANK || board[a][i] == OK)
    {
      return;
    }
  }
}

// right == board(a,b+1)
void check_right(int a, int b){
  // printf("right\n");
  bool flag = false;
  for (size_t i = b+1; i < 8; i++)
  {
    // printf("right foor loop (%d,%d)\n", a,i);
    if (board[a][i]==opposite_player)
    {
      // printf("opposite found\n");
      flag = true;
      continue;
    }
    else if (board[a][i]==current_player)
    {
      // printf("current p found\n");
      if ( flag == true ) {
        //ok
        for (size_t j = init_b+1; j < i; j++) {
          board[a][j] = current_player;  
          // printf("(%d,%d) changed\n", a,j);
        }
      }
      return;
    }
    else if(board[a][i]==BLANK || board[a][i]==OK)
    {
      return;
    }
    
  }
  
}


void check_up(int a, int b)
{
  bool flag=false;
  printf("\nup ");
  for (int i=a-1; i >=0; i--)
  {
    printf("  ==> %d(%d,%d)", board[i][b], i, b);
    if (board[i][b] == opposite_player)
    {
      printf("\nopposite[%d] found. checking again...\n", opposite_player);
      flag=true;
      continue;
    }
    else if (board[i][b] == current_player)
    {
      if (flag==true)
      {
        for (size_t q = init_a-1; q > i; q--)
        {
          printf("\n(%d,%d)changed into %d)", q-1, b, current_player);
          board[q][b] = current_player;
        }
      }
      return;
    }
    else if (board[i][b] == BLANK || board[i][b] == OK)
    {
      return;
    }
  }
}

// down == board(v+1,h)
void check_down(int a, int b)
{
  bool flag=false;
  printf("\ndown ");
  for (int i=a+1; i < 8; i++)
  {
    printf("  ==> %d(%d,%d)", board[i][b],i,b);
    if (board[i][b] == opposite_player)
    {
      printf("\nopposite[%d] found. checking again...\n", opposite_player);
       flag=true;
       continue;
    }
    else if (board[i][b] == current_player)
    {
      if (flag==true)
      {
        for (size_t q = init_a+1; q < i; q++)
        {
          printf("\n(%d,%d)changed into %d)", q-1, b, current_player);
          board[q][b] = current_player;
        }
      }
      return;
    }
    else if (board[i][b] == BLANK || board[i][b]==OK)
    {
      return;
    }

  }
}

// left up == board(v-1,h-1)
void check_left_up(int a, int b)
{
  bool flag=false;
  int i,j;
  printf("\nleft-up ");

  for ( i = a-1, j = b-1; i>=0 && j>=0; i--, j--) {
  printf(" %d(%d,%d) ==> ",board[i][j], i,j);
    if (board[i][j]==opposite_player)
    {
      flag=true;
      continue;
    }
    else if (board[i][j]==current_player)
    {
      if (flag==true)
      {
        int q,w;
        for (q = init_a-1, w = init_b-1; q>i && w>j; q--, w--)
        {
          board[q][w]=current_player;
        }
      }
      return;
    }
    else if(board[i][j] == BLANK || board[i][j] == OK)
    {
      return;
    }
  }
}


// right up  == board(v-1,h+1)
void check_right_up(int a, int b)
{
  bool flag=false;
  int i,j;
  printf("\nright-up ");
  for ( i = a-1, j = b+1; i>=0 && j<8; i--, j++) {
    printf(" %d(%d,%d) ==> ",board[i][j], i,j);
    if (board[i][j]==opposite_player)
    {
      flag=true;
      continue;
    }
    else if (board[i][j]==current_player)
    {
      if (flag==true)
      {
        int q,w;
        for (q = init_a-1, w = init_b+1; q>i && w<j; q--, w++)
        {
          board[q][w]=current_player;
        }
      }
      return;
    }
    else if(board[i][j] == BLANK || board[i][j] == OK)
    {
      return;
    }
    
  }
}


// left down  == board(v+1,h-1)
void check_left_down(int a, int b)
{
  bool flag=false;
  int i,j;
  printf("\nleft-down ");
  for (i = a+1, j = b-1; i<8 && j>=0; i++, j--) {
    printf(" %d(%d,%d) ==> ",board[i][j], i,j);
    if (board[i][j]==opposite_player)
    {
      flag=true;
      continue;
    }
    else if (board[i][j]==current_player)
    {
      if (flag==true)
      {
        int q,w;
        for (q = init_a+1, w = init_b-1; q<i && w>j; q++, w--)
        {
          board[q][w]=current_player;
        }
      }
      return;
    }
    else if(board[i][j] == BLANK || board[i][j] == OK)
    {
      return;
    }
    
  }
}

// right down == board(v+1,h+1)
void check_right_down(int a, int b)
{
  bool flag=false;
  int i,j;
  printf("\nright-up ");
  for ( i = a+1, j = b+1; i<8 && j<8; i++, j++) {
    printf(" %d(%d,%d) ==> ",board[i][j], i,j);
    if (board[i][j]==opposite_player)
    {
      flag=true;
      continue;
    }
    else if (board[i][j]==current_player)
    {
      if (flag==true)
      {
        int q,w;
        for (q = init_a+1, w = init_b+1; q<i && w<j; q++, w++)
        {
          board[q][w]=current_player;
        }
      }
      return;
    }
    else if(board[i][j] == BLANK || board[i][j] == OK)
    {
      return;
    }
    
  }
}










/* ################################
    Functions that look for
    possible moving spots
    for current_player
    
1. possible_left()
2. possible_right()
3. possible_up()
4. possible_down()
5. possible_left_up()
6. possible_right_up()
7. possible_left_down()
8. possible_right_down()
################################ */
void possible_left(int a, int b)
{
  // printf("possible left (%d,%d)\n", a+1, b+1);
  bool flag=false;
  for (int i=b-1; i>=0; i--)
  {
    if (board[a][i] == opposite_player)
    {
      // printf("\nleft opposite[%d](%d, %d) found. checking again...\n", opposite_player, a, b);
      flag=true;
      continue;
    }
    else if (board[a][i] == BLANK)
    {
      if (flag==true)
      {
        board[a][i]=OK;
        move_count++;
        return;
      }
      return;
    }
    return;
  }
}

void possible_right(int a, int b)
{
  bool flag=false;
  // printf("possible right (%d,%d)\n", a+1, b+1);
  for (int i=b+1; i<8; i++)
  {
    if (board[a][i] == opposite_player)
    {
      // printf("\nright opposite[%d](%d, %d) found. checking again...\n", board[a][i], a, i);
      flag=true;
      continue;
    }
    else if (board[a][i] == BLANK)
    {
      if (flag==true)
      {
        // printf("\n(%d,%d) changed into OK\n", a+1, i+1);
        board[a][i] = OK;
        move_count++;
        // printf("(%d,%d)changed into OK\n", a,i);
        return;
      }
      return;
    }
    return;
  }
}

void possible_up(int a, int b)
{
  bool flag=false;
  // printf("possible up (%d,%d)\n", a+1, b+1);
  for (int i = a-1; i >=0; i--)
  {
    if (board[i][b] == opposite_player)
    {
      flag=true;
      // printf("\nup opposite[%d](%d, %d) found. checking again...\n", opposite_player, i, b);
      continue;
    }
    else if (board[i][b] == BLANK)
    {
      if (flag==true)
      {
        // printf("\n(%d,%d) changed into OK\n", i+1, b+1);
        board[i][b] = OK;
        move_count++;
        return;
      }
      return;
    }
    return;
  }
}

void possible_down(int a, int b)
{
  // printf("possible down (%d,%d)\n", a+1, b+1);
  bool flag=false;
  for (int i=a+1; i < 8; i++)
  {
    if (board[i][b] == opposite_player)
    {
      flag=true;
      // printf("\ndown opposite[%d] (%d, %d)found. checking again...\n", opposite_player, i, b);
      continue;
    }
    else if (board[i][b] == BLANK)
    {
      if (flag==true)
      {
        // printf("\n(%d,%d) changed into OK\n", i+1, b+1);
        board[i][b] = OK;
        move_count++;
        return;
      }
      return;
    }
    return;
  }
}

void possible_left_up(int a, int b)
{
  // printf("possible left-up (%d,%d)\n", a+1, b+1);
  int i,j;
  bool flag=false;
  for (i = a-1, j=b-1; i >=0 && j>=0; i--, j--)
  {
    if (board[i][j]==opposite_player)
    {
      flag=true;
      // printf("left-up opposite found. continued\n");
      continue;
    }
    else if (board[i][j]==BLANK)
    {
      if (flag==true)
      {
        board[i][j]=OK;
        // printf("\n(%d,%d) left-up changed into OK\n", i+1,j+1);
        return;
      }
      return;
    }
    return; //didnt write if board[i][j]==current_p or OK
  }
}

void possible_right_up(int a, int b)
{
  int i,j;
  // printf("possible right-up (%d,%d)\n", a+1, b+1);
  bool flag=false;
  for (i = a-1, j=b+1; i >=0 && j<8; i--, j++)
  {
    if (board[i][j]==opposite_player)
    {
      flag=true;
      // printf("right-up opposite found. continued\n");
      continue;
    }
    else if (board[i][j]==BLANK)
    {
      if (flag==true)
      {
        board[i][j]=OK;
        // printf("\n(%d,%d) right-up changed into OK\n", i+1,j+1);
        return;
      }
      return;
    }
    return; //didnt write if board[i][j]==current_p or OK
  }
}

void possible_left_down(int a, int b)
{
  int i,j;
  // printf("\npossible left-down (%d,%d)\n", a+1, b+1);
  bool flag=false;
  for (i = a+1, j=b-1; i<8 && j>=0; i++, j--)
  {
    if (board[i][j]==opposite_player)
    {
      flag=true;
      // printf("left-down opposite found. continued\n");
      continue;
    }
    else if (board[i][j]==BLANK)
    {
      if (flag==true)
      {
        board[i][j]=OK;
        // printf("(%d,%d) left-down changed into OK\n", i+1,j+1);
        return;
      }
      return;
    }
    return; //didnt write if board[i][j]==current_p or OK
  }
}

void possible_right_down(int a, int b)
{
 int i,j;
  // printf("\npossible right-down (%d,%d)\n", a+1, b+1);
  bool flag=false;
  for (i = a+1, j=b+1; i<8 && j<8; i++, j++)
  {
    if (board[i][j]==opposite_player)
    {
      flag=true;
      // printf("right-down opposite found. continued\n");
      continue;
    }
    else if (board[i][j]==BLANK)
    {
      if (flag==true)
      {
        board[i][j]=OK;
        // printf("(%d,%d) right-down changed into OK\n", i+1,j+1);
        return;
      }
      return;
    }
    return; //didnt write if board[i][j]==current_p or OK
  }
}




