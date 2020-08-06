#include<stdio.h> 
// C program to illustrate sizes of 
// pointer of array 
  
/* compile with mingw or any other C compiler: */
/* gcc.exe -o a.exe intptrtoptr.c */

int intptr()
{
    int arr[] = { 3, 5, 6, 7, 9 }; 
    int *p = arr; 
    int (*ptr)[5] = &arr; 
    int* pptr[5]; 
    pptr[0] = arr+0; 
    pptr[1] = arr+1; 
    pptr[2] = arr+2; 
    pptr[3] = arr+3; 
    pptr[4] = arr+4; 
      
    printf("p = %p, ptr = %p\n", p, ptr); 
    printf("*p = %d, *ptr = %p\n", *p, ptr[0]); 
    printf("*p = %d, *ptr = %p\n", *p, ptr[1]); 
    printf("*p = %d, *ptr = %p\n", *p, ptr[2]); 
    printf("*p = %d, *ptr = %p\n", *p, ptr[3]); 
    printf("*p = %d, *ptr = %p\n", *p, ptr[4]); 
      
    for(int i = 0; i < 5; i++)
    {
	    printf("for1  ptr = %d\n", (**ptr)+i); 
	    printf("for2  ptr = %d\n", (*ptr)[i]); 
	    printf("for3 pptr = %d\n\n", *pptr[i]); 
    }

    printf("sizeof(arr) = %lu, sizeof(*arr) = %lu\n", sizeof(arr), sizeof(*arr) ); 
    printf("sizeof(p) = %lu, sizeof(*p) = %lu\n", sizeof(p), sizeof(*p)); 
    printf("sizeof(ptr) = %lu, sizeof(*ptr) = %lu\n",  sizeof(ptr), sizeof(*ptr)); 
    return 0; 
}

int main() 
{ 
	intptr();
	return 0;
} 

