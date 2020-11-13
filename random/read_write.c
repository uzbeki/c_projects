// working with files

#include <stdlib.h>
#include <stdio.h>

int main() {
    char line[255];
    
    FILE*f_pointer = fopen("employees.txt", "a");
    
    // fgets reads the file. fgets(storage, size, 255, file pointer)
    fgets(line, 255, f_pointer); 


    // printf("%s", line);
    // fprintf writes info to file(overrides a file)
    // fprintf(f_pointer, "Jim, Salesman\nPan, Receptionist\nBeki, Businessman");
    
    // append just change the fopen from "w" to "a"
    // fprintf(f_pointer, "\nKelly, Customer Service");

    fclose(f_pointer);
    /* file modes
    r - read
    w - write
    ? - read and write
    a - append */
    return 0;
}