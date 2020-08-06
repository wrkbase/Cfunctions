#include <stdio.h>

/* compile with mingw or any other C compiler: */
/* gcc.exe -o a.exe charptr.c */

int main()
{
	char *p1 = "Hello";
	// p1[0] = 'A'; // Error: Segmentation fault
	
	char ch1 = 'Z';
	char *p2 = "Hello";
	p2 = &ch1; // OK: Value of p2 can be changed
	
	char p3[] = "Hello";
	p3[0] = 'A'; // Valid
	
	char ch2 = 'Z';
	char p4[] = "Hello";

	// Error: p4 is not a valid L-Value
	// Error: assignment to expression with array type
	//p4 = &ch2;

	return 0;
}  
