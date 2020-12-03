#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// this function returns true if 'c' is inside 'str',
bool find_chr(const char *str, const char *c){
    for (int i = 0; i < strlen(str); i++)
    {
        if (*(str+i)==*c)
        {
            printf("%c found at %s[%d]\n", *c, str, i);
            return true;
        }   
    }
}


int main() {
    char input[100];
    char que;
    char* input_p;
    char* que_p;
    printf("Give me a big word: ");
    scanf("%s", input);
    input_p = input;
    printf("\nNow give me a que: ");
    scanf(" %c", &que);
    que_p = &que;
    printf("\nsearching for '%c' inside '%s' \n", *que_p, input_p);

    // printf("\nstrlen(input) = %d, sizeof(input_p)=%d \n", strlen(input), sizeof(input_p));  //WHY sizeof(p)=8???
    
    printf("\n");
    for (int i = 0; i < strlen(input); i++)
    {
        if (*(input+i)==*que_p)
        {
            printf("Search que found at %s[%d]\n", input_p, i); //show the index
        }

        // printf("%c",*(input_p+i));
        
    }
    printf("using the func\n");
    find_chr(input_p, que_p);

}