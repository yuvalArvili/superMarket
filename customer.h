#pragma once
#ifndef __CUSTOMER_H
#define __CUSTOMER_H

#include "shoppingCart.h"
#include "superMarket.h"
#include "customer.h"


typedef struct
{
	char id[10];
	char* name;
	ShoppingCart shoppingCart;

}Customer;

void initUserName(Customer* pCustomer);
void initId(Customer* pCustomer);
void initCustomer(Customer* pCustomer);
void printCustomer(SuperMarket* pSuperMarket);
void freeCustomer(Customer* pCustomer);

#endif 