#include <stdio.h>

/* compile with mingw or any other C compiler: */
/* gcc.exe -o a.exe interestcalc.c */

// Declaration of global variables used
const int DAYSINMNTH[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; 
const double SYSCORR= 0.00065925; // Value dependant on OS/Compiler Platform

typedef struct Date
{
    int day, mon, yer;
}Date;

// Declaration and Definition of functions used
int GetLeapYears(Date dte);
int DateDiff(Date dt1, Date dt2);
double CalcInterest(int years, int days, double amount);

// No. of leap years of given date
int GetLeapYears(Date dte)
{
    int years = dte.yer;
	
	// If to include current leap year
    if (dte.mon <= 2)
        years--;
	
    // It is a leap year if multiple of 4 or multiple of 400
	// and not a multiple of 100.
    return years / 4 + years / 400 - years / 100;
} // End of GetLeapYears()
  
// calculate difference of days between 2 dates
int DateDiff(Date dt1, Date dt2)
{

	// No. of days between year 0001 to dt1
    long int days1 = dt1.yer * 365 + dt1.day;
    for (int i=0; i<dt1.mon - 1; i++)
        days1 += DAYSINMNTH[i];
    days1 += GetLeapYears(dt1);


	// No. of days between year 0001 to dt2
    long int days2 = dt2.yer * 365 + dt2.day;
    for (int i=0; i<dt2.mon - 1; i++)
        days2 += DAYSINMNTH[i];
    days2 += GetLeapYears(dt2);

    return (days2 - days1);
} // End of DateDiff()

double CalcInterest(int years, int days, double amount)
{
	// Public Function CalcInterest(years As Integer, days As Integer, amount As Double) As Double

	double totpi;
	double prvpi;

	totpi = 0;
	if( years > 0 )
	{
		totpi = amount;
		while( years > 0 )
		{
			years = years - 1;
			prvpi = totpi;
			totpi = prvpi + (prvpi * SYSCORR * 365);
		}

		if( days > 0 )
		{
			prvpi = totpi;
			totpi = prvpi + (prvpi * SYSCORR * days);
		}
	}
	else if( days > 0 )
	{
		totpi = amount + (amount * SYSCORR * days);
	}
	else
	{
		totpi = amount;
	}

	return totpi;

} // End of CalcInterest()

int main()
{
	int totyears = 0;
	double totintrst = 0;
	double totamt = 176320.00;
	Date dt1 = {1, 4, 2015};
	Date dt2 = {17, 2, 2018};

	printf("\nTotal loan Amount taken : %.2f , on day: %d-%d-%d \n", totamt, dt1.yer, dt1.mon, dt1.day);


	int totdays = DateDiff(dt1, dt2);
	while( totdays > 365 )
	{
		totdays = totdays - 365;
		totyears = totyears + 1;
	}
	totintrst = CalcInterest(totyears, totdays, totamt);
	printf("\nTotal Compound Interest is : %f , on day: %d-%d-%d \n", totintrst, dt2.yer, dt2.mon, dt2.day);
	printf("\nDifference of days between two dates : %d \n", DateDiff(dt1, dt2));
	printf("Total Years : %d \n", totyears);
	printf("Remaining Days after subtracting years : %d \n", totdays);
	
    return 0;
}


