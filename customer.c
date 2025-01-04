#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "customer.h"
#include "allocations.h"


void initId(Customer* pCustomer)
{
	char temp[100];
	do {
		printf("please enter your Id number. max 9 numbers\n");
		scanf("%s ", &temp);
	} while (strlen(temp) != 9 || isNum(temp));
}



void initUserName(Customer* pCustomer)
{
	char* fullName = NULL;
	char firstName[100] = { 0 };
	char lastName[100] = { 0 };
	size_t stringSize = 0, len1, len2;
	printf("please enter your first name \n");
	myGets(firstName, sizeof(firstName));
	len1 = strlen(firstName);

	printf("please enter your last name \n");
	myGets(lastName, sizeof(lastName));
	len2 = strlen(lastName);

	cutSpace(firstName);
	cutSpace(lastName);

	makeUpper(firstName, len1);
	makeUpper(lastName, len2);

	stringSize = len1 + len2 + 2; //1 for the - , 1 for '\0'
	fullName = (char*)safeRealloc(fullName, stringSize * sizeof(char));
	if (!fullName)// error in allocation
		return NULL;

	strcat(firstName, " - ");
	strcat(firstName, lastName);
}

void initCustomer(Customer* pCustomer)
{
	initUserName(pCustomer);
	initId(pCustomer);
	strcpy(&pCustomer->shoppingCart,NULL);
}
void printCustomer(SuperMarket* pSuperMarket) {
	Customer* customer;
	if (pSuperMarket->numOfCustomers == 0) {
		printf("There are no customers in shop");
		return;
	}
	printf("There are %d listed customers ", pSuperMarket->numOfCustomers);
	for (int i = 0; i < pSuperMarket->numOfCustomers; i++)
	{
		customer = &pSuperMarket->customerList[i];
		printf("name: %s\n id: %s \n",customer->name, customer->id);
	}
	
 }

void freeCustomer(Customer* pCustomer)
{
	free(pCustomer->name);
}

