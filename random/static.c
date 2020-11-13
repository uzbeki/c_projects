// static variables


#include <stdio.h>
int runner()
{
    static int count = 0;
    count++;
    return count;
}

static void fun(void) {
   printf("I am a static function.");
}

int main()
{
    printf("%d ", runner());
    printf("%d ", runner());

    fun();
    return 0;
}