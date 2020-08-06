#include <stdio.h>
#include <string.h> // needed for strlen()

/* compile with mingw or any other C compiler: */
/* gcc.exe -o a.exe trimspace.c */

// Declaration and Definition of functions used
int TrimEndSpace(char *line, char *rline);
int TrimSpace(char *line, char *rline);

/* trim all unknown characters ending spaces turn them to ascii chr set*/
int TrimEndSpace(char *line, char *rline)
{
	int nlen = strlen(line);

	int gotasc = 0;
	int mcnt = 0;
	int tcnt = 0;

	for(int k = 0; k < nlen; k++)
	{
		if(line[k] == 0x09) // Tab character \t
		{
			 // putchar('<');
			 // putchar('0');
			 // putchar('9');
			 // putchar('>');
			 // printf("%d: 09->%#x : %d : %c : %s, \n", cnt, line[k], line[k], line[k], line);
			 if( gotasc )
			 {
				 rline[tcnt] = line[k];
				 tcnt++;
			 }
			 mcnt++;
		}
		else if(line[k] == 0x20) // space character
		{
			 // putchar('<');
			 // putchar('2');
			 // putchar('0');
			 // putchar('>');
			 // printf("%d 20->%#x : %d : %s, \n", cnt, line[k], line[k], line);
			 if( gotasc )
			 {
				 rline[tcnt] = line[k];
				 tcnt++;
			 }
			 mcnt++;
		}
		else if( (line[k] >= 0x00) && (line[k] <= 0x1F))
		{
			 // putchar('<');
			 // putchar('0');
			 // putchar('0');
			 // putchar('x');
			 // putchar('1');
			 // putchar('F');
			 // putchar('>');
			 // printf("%d: 00x1F->%#x : %d : %c : %s, \n", cnt, line[k], line[k], line[k], line);
		}
		else if( (line[k] >= 0x7F) && (line[k] <= 0xFF))
		{
			 // putchar('<');
			 // putchar('7');
			 // putchar('F');
			 // putchar('x');
			 // putchar('F');
			 // putchar('F');
			 // putchar('>');
			 // printf("%d: 7FxFF->%#x : %d : %c : %s, \n", cnt, line[k], line[k], line[k], line);
			 rline[tcnt] = line[k];
			 tcnt++;
		}
		else if(line[k] == 0xFFFFFFEF ) // Special Symbol
		{
			 // putchar('<');
			 // putchar('E');
			 // putchar('F');
			 // putchar('>');
			 // printf("%d: EF->%#x : %d : %c : %s, \n", cnt, line[k], line[k], line[k], line);
		}
		else if(line[k] == 0xFFFFFFBB) // Special Symbol
		{
			 // putchar('<');
			 // putchar('B');
			 // putchar('B');
			 // putchar('>');
			 // printf("%d: BB->%#x : %d : %c : %s, \n", cnt, line[k], line[k], line[k], line);
		}
		else if(line[k] == 0xFFFFFFBF) // Special Symbol
		{
			 // putchar('<');
			 // putchar('B');
			 // putchar('F');
			 // putchar('>');
			 // printf("%d: BF->%#x : %d : %c : %s, \n", cnt, line[k], line[k], line[k], line);
		}
		else if(line[k] == 0xFFFFFFE4) // Special Symbol
		{
			 // putchar('<');
			 // putchar('E');
			 // putchar('4');
			 // putchar('>');
			 // printf("%d: E4->%#x : %d : %c : %s, \n", cnt, line[k], line[k], line[k], line);
		}
		else if(line[k] == 0x00) // NULL character 
		{
			 // putchar('<');
			 // putchar('0');
			 // putchar('0');
			 // putchar('>');
			 // printf("%d: 00->%#x : %d : %c : %s, \n", cnt, line[k], line[k], line[k], line);
			mcnt++;
		}
		else if(line[k] == 0x0A) // New line character \n
		{
			 // putchar('<');
			 // putchar('0');
			 // putchar('A');
			 // putchar('>');
			 // printf("%d: 0A->%#x : %d : %c : %s, \n", cnt, line[k], line[k], line[k], line);
		}
		else if(line[k] == 0x0D) // Carriage Return character \r
		{
			 // putchar('<');
			 // putchar('0');
			 // putchar('D');
			 // putchar('>');
			 // printf("%d: 0D->%#x : %d : %c : %s, \n", cnt, line[k], line[k], line[k], linline);
		}
		else if( (line[k] >= 0x20) && (line[k] <= 0x7E)) // Valid ASCII Characters
		{
			 // putchar('<');
			 // putchar(line[k]);
			 // putchar('>');

			 mcnt = 0;
			 rline[tcnt] = line[k];
			 tcnt++;
			 gotasc = 1;
			
			 // printf("%d: 20x7E->%#x : %d : %c : %s, \n", cnt, line[k], line[k], line[k], line);
		}
	}
	rline[tcnt] = 0;
	if( mcnt > 0 )
	{
		for( int j=mcnt; j > 0; j--)
		{
			tcnt--;
			rline[tcnt] = 0;
		}
	}
	return 1;
} // End of TrimEndSpace()

/* trim all unknown characters and turn them to ascii chr set*/
int TrimSpace(char *line, char *rline)
{
	int nlen = strlen(line);

	int gotasc = 0;
	int mcnt = 0;
	int tcnt = 0;

	for(int k = 0; k < nlen; k++)
	{
		if(line[k] == 0x09) // Tab character \t
		{
			 // putchar('<');
			 // putchar('0');
			 // putchar('9');
			 // putchar('>');
			 // printf("%d: 09->%#x : %d : %c : %s, \n", cnt, line[k], line[k], line[k], line);
			 mcnt++;
		}
		else if(line[k] == 0x20) // space character
		{
			 // putchar('<');
			 // putchar('2');
			 // putchar('0');
			 // putchar('>');
			 // printf("%d 20->%#x : %d : %s, \n", cnt, line[k], line[k], line);
			 mcnt++;
		}
		else if( (line[k] >= 0x00) && (line[k] <= 0x1F))
		{
			 // putchar('<');
			 // putchar('0');
			 // putchar('0');
			 // putchar('x');
			 // putchar('1');
			 // putchar('F');
			 // putchar('>');
			 // printf("%d: 00x1F->%#x : %d : %c : %s, \n", cnt, line[k], line[k], line[k], line);
		}
		else if( (line[k] >= 0x7F) && (line[k] <= 0xFF))
		{
			 // putchar('<');
			 // putchar('7');
			 // putchar('F');
			 // putchar('x');
			 // putchar('F');
			 // putchar('F');
			 // putchar('>');
			 // printf("%d: 7FxFF->%#x : %d : %c : %s, \n", cnt, line[k], line[k], line[k], line);
		}
		else if(line[k] == 0xFFFFFFEF ) // Special Symbol
		{
			 // putchar('<');
			 // putchar('E');
			 // putchar('F');
			 // putchar('>');
			 // printf("%d: EF->%#x : %d : %c : %s, \n", cnt, line[k], line[k], line[k], line);
		}
		else if(line[k] == 0xFFFFFFBB) // Special Symbol
		{
			 // putchar('<');
			 // putchar('B');
			 // putchar('B');
			 // putchar('>');
			 // printf("%d: BB->%#x : %d : %c : %s, \n", cnt, line[k], line[k], line[k], line);
		}
		else if(line[k] == 0xFFFFFFBF) // Special Symbol
		{
			 // putchar('<');
			 // putchar('B');
			 // putchar('F');
			 // putchar('>');
			 // printf("%d: BF->%#x : %d : %c : %s, \n", cnt, line[k], line[k], line[k], line);
		}
		else if(line[k] == 0xFFFFFFE4) // Special Symbol
		{
			 // putchar('<');
			 // putchar('E');
			 // putchar('4');
			 // putchar('>');
			 // printf("%d: E4->%#x : %d : %c : %s, \n", cnt, line[k], line[k], line[k], line);
		}
		else if(line[k] == 0x00) // NULL character 
		{
			 // putchar('<');
			 // putchar('0');
			 // putchar('0');
			 // putchar('>');
			 // printf("%d: 00->%#x : %d : %c : %s, \n", cnt, line[k], line[k], line[k], line);
			mcnt++;
		}
		else if(line[k] == 0x0A) // New line character \n
		{
			 // putchar('<');
			 // putchar('0');
			 // putchar('A');
			 // putchar('>');
			 // printf("%d: 0A->%#x : %d : %c : %s, \n", cnt, line[k], line[k], line[k], line);
		}
		else if(line[k] == 0x0D) // Carriage Return character \r
		{
			 // putchar('<');
			 // putchar('0');
			 // putchar('D');
			 // putchar('>');
			 // printf("%d: 0D->%#x : %d : %c : %s, \n", cnt, line[k], line[k], line[k], linline);
		}
		else if( (line[k] >= 0x20) && (line[k] <= 0x7E)) // Valid ASCII Characters
		{
			 // putchar('<');
			 // putchar(line[k]);
			 // putchar('>');

			 if( gotasc ) 
			 {
				 if( mcnt > 0 )
				 {
					 mcnt = 0;
					 rline[tcnt] = 0x20;
					 tcnt++;
				 }
			 }
			 else 
			 {
				 mcnt = 0;
			 }
			 rline[tcnt] = line[k];
			 tcnt++;
			 gotasc = 1;
			
			 // printf("%d: 20x7E->%#x : %d : %c : %s, \n", cnt, line[k], line[k], line[k], line);
		}
	}
	rline[tcnt] = 0;
	return 1;
} // End of TrimSpace()

int main()
{
	char line[500] = "	 This is   the new passw2d 920201aj;adjf;q<) }  a		 ls 	";
	char nwline[500] = {0};

	// Trim all intermittent spaces to single space
	printf("\nOriginal Line:-%s-\n", line);
	TrimSpace(line, nwline);
	printf("\nTrimmed Line:-%s-\n", nwline);

	// Trim all starting and ending spaces
	for(int i=0; i < 500; i++) nwline[i] = 0;
	TrimEndSpace(line, nwline);
	printf("\nTrimmed Line Endings:-%s-\n", nwline);

}
