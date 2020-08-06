#include <stdio.h>
#include <string.h>

/* compile with mingw or any other C compiler: */
/* gcc.exe -o a.exe strngfunc.c */

int main () {
   int len;
   const char str1[] = "ABCDEF4960910";
   const char str2[] = "130";

   len = strcspn(str1, str2);

   printf("First matched character is at %d\n", len + 1);
   
   return(0);
}
