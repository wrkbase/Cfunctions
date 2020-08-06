#include <stdio.h>
#include <stdlib.h> // needed for atoi()
#include <string.h> // needed for strcspn()

/* compile with mingw or any other C compiler: */
/* gcc.exe -o a.exe DateDiff.c */

/* Declaration of Global Variables Used */
const int DAYSINMNTH[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; 
typedef struct Date
{
    int day, mon, yer;
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
}

// No. of leap years of given date
int GetLeapYears(Date dt)
{
    int years = dt.yer;
	
	// If to include current leap year
    if (dt.mon <= 2)
        years--;
	
    // It is a leap year if multiple of 4 or multiple of 400
	// and not a multiple of 100.
    return years / 4 + years / 400 - years / 100;
}

/* Difference in years and days between latest date enddate and earlier date startdate */
int DateDiff(Date enddate, Date startdate)
{

	// No. of days between year 0001 to startdate
    long int days1 = startdate.yer * 365 + startdate.day;
    for (int i=0; i<startdate.mon - 1; i++)
        days1 += DAYSINMNTH[i];
    days1 += GetLeapYears(startdate);


	// No. of days between year 0001 to enddate
    long int days2 = enddate.yer * 365 + enddate.day;
    for (int i=0; i<enddate.mon - 1; i++)
        days2 += DAYSINMNTH[i];
    days2 += GetLeapYears(enddate);

    return (days2 - days1);
}

int main()
{
	char dt2[] = "27-03-2020";
	char dt1[] = "28-12-2019";

	printf("\nActual Dates dt2: %s and dt1: %s \n\n", dt2, dt1);

	char date2[11] = {0};
	char date1[11] = {0};

	// Copy to temp date2,date1 because dt2 and dt1 will be truncated
	strncpy(date2, dt2, strlen(dt2));
	strncpy(date1, dt1, strlen(dt1));

	int days = 0;
	Date findate, stdate;
	
	// Parsing Date2
	findate.day = atoi(skstrtok(dt2, "-"));
	printf("Actual Dates after skstrtok Date2: %s and Date1: %s and findate.day: %d \n", dt2, dt1, findate.day);

	findate.mon = atoi(skstrtok(NULL, "-"));
	printf("Actual Dates after skstrtok Date2: %s and Date1: %s and findate.mon: %d \n", dt2, dt1, findate.mon);

	findate.yer = atoi(skstrtok(NULL, "-"));
	printf("Actual Dates after skstrtok Date2: %s and Date1: %s and findate.mon: %d \n\n", dt2, dt1, findate.yer);

	// Parsing Date1
	stdate.day = atoi(skstrtok(dt1, "-"));
	printf("Actual Dates after skstrtok Date2: %s and Date1: %s and stdate.mon: %d \n", dt2, dt1, stdate.day);

	stdate.mon = atoi(skstrtok(NULL, "-"));
	printf("Actual Dates after skstrtok Date2: %s and Date1: %s and stdate.mon: %d \n", dt2, dt1, stdate.mon);

	stdate.yer = atoi(skstrtok(NULL, "-"));
	printf("Actual Dates after skstrtok Date2: %s and Date1: %s and stdate.mon: %d \n\n", dt2, dt1, stdate.yer);


	days = DateDiff(findate, stdate);

	printf("Days between date2: %s and date1: %s is %d days \n", date2, date1, days);
}
