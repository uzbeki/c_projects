// practicing nested loops and arrays(dimentional arrays[][])
#include <stdio.h>
int main()
{
    // structureー構造
    // 
    // 共用体　ー　union
    int nums[3][4] = {
        {1, 2, 3, 4},
        {4, 5, 6, 7},
        {2, 7, 8, 8}};
    int i, j;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 4; j++)
        {
            printf("%d ", nums[i][j]);
        }
        printf("\n");
    }

    return 0;
}