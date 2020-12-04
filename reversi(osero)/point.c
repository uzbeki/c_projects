#include "pointer_declarations.h"

int main() {

    printf("%d\n", **board); //matrix
    printf("%d\n", *(*(board + 0)));
    printf("%d\n", *(*(board + 0) + 1)); //value at board[0][1]

    // row = *(board + i)
    // cell = *(*(board + 0) + 0)
    for (int i = 0; i < BOARD_SIZE; i++) {
        int *row = *(board+i);
        printf("%d\n", row);
        for (int j = 0; j < BOARD_SIZE; j++){
            int *cell = row+j;
            printf("\t%d\n", *cell);

            // if (*(*(board + i) + j) == BLACK)             {
            //     printf("black found at board[%d][%d]\n", i + 1, j + 1);
            // }

        }

    }


    return 0;
}