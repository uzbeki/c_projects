//working with strigns in c
/* 
strlen - gives the lengh of a given string
strcnt - concatenates two strings
strcmp - compares two strings
 */


#include <stdio.h>

int main()
{
    // 2ways to create strings
    // char * name = "Bekhruz Otaev";  //only readable *pointer
    char name[] = "Bekhruz Otaev";  //can be manipulated
    
    // strlen(string_name) calculates the length of a string
    printf("%d", strlen(name));

    
    return 0;
}