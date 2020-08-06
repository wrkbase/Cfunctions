#include <stdio.h>
#include <stdlib.h>

/* compile with mingw or any other C compiler: */
/* gcc.exe -o a.exe readfilegetline.c */

int main(void)
{
    FILE * fp;
    char * line = NULL;
    size_t len = 0;
    ssize_t read;

    fp = fopen("somedata.txt", "r");
    if (fp == NULL)
        exit(EXIT_FAILURE);

    while ((read = getline(&line, &len, fp)) != -1) {
        printf("\nRetrieved line of length %d:- ", read);
        printf("%s", line);
    }

    fclose(fp);
    if (line)
        free(line);
    exit(EXIT_SUCCESS);
}
