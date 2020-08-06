#include <stdio.h>
#include <stdlib.h> // For exit() function

/* compile with mingw or any other C compiler: */
/* gcc.exe -o a.exe readfilestring.c */

int main() {

    char rdline[10000];

    FILE *fptr;

    if ((fptr = fopen("somedata.txt", "r")) == NULL) {
        printf("Error! opening file");
        // Program exits if file pointer returns NULL.
        exit(1);
    }

    // reads text until newline is encountered
    // fscanf(fptr, "%[^\n]", rdline);
    // reads text until end of file is encountered
    fscanf(fptr, "%[^\0]", rdline);
    printf("\nData from the file:-\n%s", rdline);
    fclose(fptr);

    return 0;
}
