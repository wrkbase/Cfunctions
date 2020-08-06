#include<stdio.h>
#include<conio.h> // needed for getch()
#include<String.h>

/* compile with mingw or any other C compiler: */
/* gcc.exe -o a.exe readfilebuffer.c */

int main()
{
	FILE *fp = fopen("somedata.txt","r");
        char buff[1024];

	while( fgets(buff, 1024, (FILE*)(fp)) != NULL )
	{
	   printf(buff);
	   getch();
	}
}
