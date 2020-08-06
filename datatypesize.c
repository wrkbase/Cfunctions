#include <stdio.h>

/* compile with mingw or any other C compiler: */
/* gcc.exe -o a.exe datatypesize.c */

/*
Type			Size (bytes)			Format Specifier
int			at least 2, usually 4			%d, %i
char			1					%c
float			4					%f
double			8					%lf
short int		2 usually				%hd
unsigned int		at least 2, usually 4			%u
long int		at least 4, usually 8			%ld, %li
long long int		at least 8				%lld, %lli
unsigned long int	at least 4				%lu
unsigned long long int	at least 8				%llu
signed char		1					%c
unsigned char		1					%c
long double		at least 10, usually 12 or 16		%Lf
*/

int main()
{
	printf("\nsize of size_t : %d \n" , sizeof(size_t));
	printf("\nsize of wchar_t : %d \n" , sizeof(wchar_t));
	printf("\nsize of int : %d \n", sizeof(int));
	printf("\nsize of char : %d \n", sizeof(char));
	printf("\nsize of float : %d \n", sizeof(float));
	printf("\nsize of double : %d \n", sizeof(double));
	printf("\nsize of short int : %d \n", sizeof(short int));
	printf("\nsize of unsigned int : %d \n", sizeof(unsigned int));
	printf("\nsize of long int : %d \n", sizeof(long int));
	printf("\nsize of long long int : %d \n", sizeof(long long int));
	printf("\nsize of unsigned long int : %d \n", sizeof(unsigned long int));
	printf("\nsize of unsigned long long int : %d \n", sizeof(unsigned long long int));
	printf("\nsize of signed char : %d \n", sizeof(signed char));
	printf("\nsize of unsigned char : %d \n", sizeof(unsigned char));
	printf("\nsize of long double : %d \n", sizeof(long double));
	printf("\nsize of long double : %d \n", sizeof(long double));
}
