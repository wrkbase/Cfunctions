#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* compile with mingw or any other C compiler: */
/* gcc.exe -o a.exe validate.c */

/* Validates if the datestr dd-mm-yyyy is a valid date */
int ValidateDate(char *datestr) 
{
	char *ddc = strtok(datestr, "-");
	char *mmc = strtok(NULL, "-");
	char *yyc = strtok(NULL, "-");
	int dd = atoi(ddc);
	int mm = atoi(mmc);
	int yy = atoi(yyc);

	//check year
	if(yy>=1900 && yy<=9999)
	{
		//check month
		if(mm>=1 && mm<=12)
		{
			//check days
			if((dd>=1 && dd<=31) &&
				(mm==1 || mm==3 || mm==5 || mm==7 || mm==8 || mm==10 || mm==12))
				return 1;
			// printf("Date is valid.\n");
			else if((dd>=1 && dd<=30) && (mm==4 || mm==6 || mm==9 || mm==11))
				return 1;
			// printf("Date is valid.\n");
			else if((dd>=1 && dd<=28) && (mm==2))
				return 1;
			// printf("Date is valid.\n");
			else if(dd==29 && mm==2 && (yy%400==0 ||(yy%4==0 && yy%100!=0)))
				return 1;
			// printf("Date is valid.\n");
			else
				return 0;
			// printf("Day is invalid.\n");
		}
		else
		{
			return 0;
			// printf("Month is not valid.\n");
		}
	}
	else
	{
		return 0;
		// printf("Year is not valid.\n");
	}
} // End of ValidateDate()

int main()
{
	char dt1[] = "31-02-2020";
	char date[11] = {0};

	char dt2[] = "28-02-2020";
	char date2[11] = {0};

	strncpy(date, dt1, strlen(dt1));
	strncpy(date2, dt2, strlen(dt2));

	if( ValidateDate(dt1) )
		printf ("\nDate is valid: %s \n", date);
	else
		printf ("\nDate is NOT valid: %s \n", date);


	if( ValidateDate(dt2) )
		printf ("\nDate is valid: %s \n", date2);
	else
		printf ("\nDate is NOT valid: %s \n", date2);
}
