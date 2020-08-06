#include <stdio.h>
#include <string.h> // needed for strcspn()

/* compile with mingw or any other C compiler: */
/* gcc.exe -o a.exe skstrtok.c */

/* Declaration of Global Variables Used */
typedef struct Date
{
    char day[5], mon[5], yer[5];
}Date;

/*  Same strtok funtionality copied here for now */
char *skstrtok(char *sentence, const char *delim)
{
	char *sentc = sentence;
	
	// static is needed to preserve lasts value during multiple calls.
	static char *lasts;
	int ch;
    
       //  May not work on some compilers.
       //  register int ch; 

       if(sentc == 0)
	       sentc = lasts;
       do {
	       if ((ch = *sentc++) == '\0')
		       return 0;
       } while (strchr(delim, ch));
       --sentc;
       
       // strcspn() gets no.of characters in sentence before the occurrence
       // of a character present in delim.
       lasts = sentc + strcspn(sentc, delim);
       
       if (*lasts != 0)
	       *lasts++ = 0;
       // R->L  (*last)++ deref last then incr pointer last
       return sentc;
} // End of skstrtok

int main()
{
	char dt1[] = "28-12-2019";
	char dt2[] = "27-03-2020";

	printf("\nActual Dates Date1: %s and Date2: %s \n\n", dt1, dt2);

	Date stdate, findate;
	
	// Parsing Date1
	strcpy(stdate.day, skstrtok(dt1, "-"));
	printf("Actual Dates after skstrtok Date1: %s and Date2: %s and stdate.day: %s \n", dt1, dt2, stdate.day);

	strcpy(stdate.mon, skstrtok(NULL, "-"));
	printf("Actual Dates after skstrtok Date1: %s and Date2: %s and stdate.mon: %s \n", dt1, dt2, stdate.mon);

	strcpy(stdate.yer, skstrtok(NULL, "-"));
	printf("Actual Dates after skstrtok Date1: %s and Date2: %s and stdate.yer: %s \n\n", dt1, dt2, stdate.yer);

	// Parsing Date2
	strcpy(findate.day, skstrtok(dt2, "-"));
	printf("Actual Dates after skstrtok Date1: %s and Date2: %s and findate.day: %s \n", dt1, dt2, findate.day);

	strcpy(findate.mon, skstrtok(NULL, "-"));
	printf("Actual Dates after skstrtok Date1: %s and Date2: %s and findate.mon: %s \n", dt1, dt2, findate.mon);

	strcpy(findate.yer, skstrtok(NULL, "-"));
	printf("Actual Dates after skstrtok Date1: %s and Date2: %s and findate.yer: %s \n", dt1, dt2, findate.yer);
}
