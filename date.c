#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "date.h"


void initDate(Date* pDate)
{
	const char date[8];
	do {
		printf("please enter day ddmmyyyy format. \n ");
		sscanf(date, "%2d%2d%4d", &pDate->day, &pDate->month, &pDate->year);
	} while (strlen(date) > 8 || strlen(date) < 8);
	
	if (pDate->year < 2024 || pDate->year > 2030)
		printf("not valid year. max year is 2030 min year is 2024");
	else if(pDate->month < 0 || pDate->month > 12)
		printf("not valid month.");
	else if(pDate->month == 02 &&(pDate->day > 28 || pDate->day < 0))
		printf("not valid day.");
	else if (pDate->month == 04 || pDate->month == 06 || pDate->month == 09 || pDate->month == 11) {
		if(pDate->day < 0 || pDate->day > 30)
			printf("not valid day.");
	}
	else if (pDate->day < 0 || pDate->day > 31)
		printf("not valid day.");
	
}

void printDate(Date* pDate)
{
	printf(" %d/%d/%d\n", pDate->day, pDate->month, pDate->year);

}

