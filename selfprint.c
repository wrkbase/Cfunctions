#include <stdio.h>

/* compile with mingw or any other C compiler: */
/* gcc.exe -o a.exe selfprint.c */

void* functioncall(const char *file, int line, const char *func)
{
    FILE *fp;
    fp = fopen(__FILE__,"r");

    int c;
    do {
	    c = getc(fp);
         putchar(c);

    } while(c != EOF);

    fclose(fp);

    printf ("\nFilename: %s \nCode Line: %i \nCalled Function: %s \n", file, line, func);
    return 0;

}

int main() {

    printf("\nPrinting out the content of this file: \n\n");

    functioncall(__FILE__, __LINE__, __FUNCTION__);
}
