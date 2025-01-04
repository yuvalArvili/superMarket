#pragma once
#ifndef __DATE_H
#define __DATE_H

typedef struct
{
	int day;
	int month;
	int year;
}Date;

void initDate(Date* pDate);
void printDate(Date* pDate);
#endif