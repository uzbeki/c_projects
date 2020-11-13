// learning about memory management in C
// %p (pointer) accesses an item's physical memory address
// pointer is a memory address
// pointer can be seen as a type of data

// referencing pointers[&] ("%p", &variable)
//dereferencing pointers[*] (going back to pointers value using its mem add)
// deref ("%d", *p_variable) - d changes depending on the var type

#include <stdlib.h>

int main()
{
    int age = 30;
    int *p_age = &age; //physical mem add of age

    double gpa = 3.5;
    double *p_gpa = &gpa;

    char grade = "A";
    char *p_grade = &grade;

    // creating a pointer variable here

    // printf("Age address: %p\nGPA address: %p\nGrade address: %p\n", p_age, p_gpa, p_grade);
    
    printf("%d\n", &age); //6422020 :10進数 base 10
    printf("%d\n", *&age); //30 :10進数 base 10
    printf("%p\n", &age); //000000000061FE04 :16進数 
    printf("%p\n", *&age); // 000000000000001E 

/* 32bit
00000000 - FFFFFFFF
64bit
0000000000000000 - FFFFFFFFFFFFFFFF */

    /* 6422020
30
000000000061FE04
000000000000001E */
    return 0;
}