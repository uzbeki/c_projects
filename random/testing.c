#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../reversi(osero)/test.c"

int main(int argc, char const* argv[]) {
    int marks[5][3] = { { 98, 76, 89},
                        { 81, 96, 79},
                        { 88, 86, 89},
                        { 97, 94, 99},
                        { 92, 81, 59}
    };

    printf("&marks - %p\n", *marks);

    // printf("Address of whole 2-D array = %d\n", &marks);
    // printf("Addition of 1 results in %d\n", &marks +1);
    // printf("Address of 0th array = %d\n", marks);
    // printf("Addition of 1 results in %d\n", marks +1);
    // printf("Address of 0th array =%d\n", &marks[0]);
    // printf("Addition of 1 results in %d\n", &marks[0] + 1);
    
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            
        }
        
    }
    
}





/*     char * input;
    char que;
    char* que_p;
    printf("長い文字例をください： ");
    scanf("%s", &input);

    printf("%s 了解。\n\n探す文字をください： ", &input);
    scanf("%s", &que_p);
    // que_p = &que;
    printf("\n");
    printf("searching for %c inside %s \n", &que_p, &input);

    printf("\nlength of the word = %d \n", strlen(&input)); */