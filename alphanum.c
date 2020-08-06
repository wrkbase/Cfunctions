#include <stdio.h>
#include <ctype.h>
/* ctype.h needed for isalnum(), isdigit(), isalpha(), isblank() */

/* compile with mingw or any other C compiler: */
/* gcc.exe -o a.exe alphanum.c */

/*
The below functions under ctype.h header file are applied on normal characters.

S.NO	FUNCTION	DESCRIPTION
		RETURN VALUES
1.	isalnum()	This function identifies the alphanumeric characters
		Returns 0 if the passed argument is non – alphanumeric character
		Returns non zero value if the passed argument is alphanumeric character
2.	isalpha()	This function identifies the alphabets from other characters
		Returns 0 if the passed argument is not an alphabet
		Returns non zero value if the passed argument is an alphabet
3.	isblank()	This function identifies the blank spaces from other characters
		Returns 0 if the passed argument is not a blank space
		Returns nonzero value if the passed argument is a blank space
4.	iscntrl()	This function identifies the control characters(\n, \b, \t, \r).
		Returns 0 if the passed argument is not a control character
		Returns nonzero value if the passed argument is a control character
5.	isdigit()	This function identifies numbers in character.
		Returns 0 if the passed argument is not a number
		Returns nonzero value if the passed argument is a number
6.	islower()	This function identifies the lowercase alphabets.
		Returns 0 if the passed argument is not a lowercase alphabet
		Returns nonzero value if the passed argument is a lowercase alphabet
7.	isprint()	This function identifies the printable characters.
		Returns 0 if the passed argument is a non printable character
		Returns nonzero value if the passed argument is a printable character
8.	ispunct()	This function identifies punctuation characters (characters that are neither alphanumeric nor space).
		Returns 0 if the passed argument is not a punctuation character
		Returns nonzero value if the passed argument is a punctuation character
9.	isspace()	This function identifies white-space characters.
		Returns 0 if the passed argument is not a white-space character
		Returns nonzero value if the passed argument is a white-space character
10.	isupper()	This function identifies the uppercase alphabets.
		Returns 0 if the passed argument is not an uppercase alphabet
		Returns nonzero value if the passed argument is an uppercase alphabet
11.	isxdigit()	This function identifies the hexadecimal digit.
		Returns 0 if the passed argument is not a hexadecimal digit
		Returns nonzero value if the passed argument is an hexadecimal digit
12.	tolower()	This function converts uppercase alphabet to lowercase alphabet.
		Returns lowercase alphabet of the corresponding uppercase alphabet
13.	toupper()	This function convert lowercase alphabet to uppercase alphabet.
		Returns uppercase alphabet of the corresponding lowercase alphabet
*/

void alphanum(char *chr)
{
	if(  (*chr >= 'a' && *chr <= 'z') || (*chr >= 'A' && *chr <= 'Z') )
		printf("character is Alphabet: %c  decval:  %d\n", *chr, *chr);
	else if(  (*chr >= '0' && *chr <= '9') )
		printf("character is Number: %c  decval:  %d\n", *chr, *chr);
	else
		printf("character is not Alphabet or Number: %c  decval:  %d\n", *chr, *chr);

} // End of alphanum

int main()
{
	char *ch1 = "a";
	char *ch2 = "z";
	char *ch3 = "A";
	char *ch4 = "Z";
	char *ch5 = "0";
	char *ch6 = "9";
	char *ch7 = ".";
	char *ch8 = ",";
	char *ch9 = "\\";
	char *ch10 = "-";
	char *ch11 = "=";
	char *ch12 = "/";
	char *ch13 = ":";
	char *ch14 = "\"";
	
	if( ch1[0] == 'z' )
		printf("\nCharacter %c  decval: %d\n", ch1[0], ch1[0]);
	else
		printf("\nNot equal char: %c  decval: %d\n", ch1[0], ch1[0]);

	alphanum(ch1);
	printf("Character %c ret: %d\n\n", ch1[0], isalnum(ch1[0]));

	alphanum(ch2);
	printf("Character %c ret: %d\n\n", ch2[0], isalnum(ch2[0]));

	alphanum(ch3);
	printf("Character %c ret: %d\n\n", ch3[0], isalnum(ch3[0]));

	alphanum(ch4);
	printf("Character %c ret: %d\n\n", ch4[0], isalnum(ch4[0]));

	alphanum(ch5);
	printf("Character %c ret: %d\n\n", ch5[0], isalnum(ch5[0]));

	alphanum(ch6);
	printf("Character %c ret: %d\n\n", ch6[0], isalnum(ch6[0]));

	alphanum(ch7);
	printf("Character %c ret: %d\n\n", ch7[0], isalnum(ch7[0]));

	alphanum(ch8);
	printf("Character %c ret: %d\n\n", ch8[0], isalnum(ch8[0]));

	alphanum(ch9);
	printf("Character %c ret: %d\n\n", ch9[0], isalnum(ch9[0]));

	alphanum(ch10);
	printf("Character %c ret: %d\n\n", ch10[0], isalnum(ch10[0]));

	alphanum(ch11);
	printf("Character %c ret: %d\n\n", ch11[0], isalnum(ch11[0]));

	alphanum(ch12);
	printf("Character %c ret: %d\n\n", ch12[0], isalnum(ch12[0]));

	alphanum(ch13);
	printf("Character %c ret: %d\n\n", ch13[0], isalnum(ch13[0]));

	alphanum(ch14);
	printf("Character %c ret: %d\n\n", ch14[0], isalnum(ch14[0]));
	
}
