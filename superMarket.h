#pragma once
#ifndef __SUPER_MARKET_H
#define __SUPER_MARKET_H

#include "customer.h"
#include "product.h"
#include "shoppingItem.h"


typedef struct
{
	char* name;
	Customer* customerList;
	int numOfCustomers;
	Product** itemsInShop;
	int numOfItem;

}SuperMarket;

void initSuperMarket(SuperMarket* pSuperMarket);
int isRegister(SuperMarket* pSuperMarket,const char* id);
void printItemsInShop(SuperMarket* pSuperMarket, Product* product);

void printSuperMarket(SuperMarket* pSuperMarket);
void addItemToShop(SuperMarket* pSuperMarket);
void addCustomerToShop(SuperMarket* pSuperMarket);
void printByType(SuperMarket* pSuperMarket, Type* theType);
void freeSuperMarket(SuperMarket* pSuperMarket);

#endif