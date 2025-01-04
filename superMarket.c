#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "superMarket.h"
#include "customer.h"
#include "allocations.h"

void initSuperMarket(SuperMarket* pSuperMarket)
{
	pSuperMarket->name = createDynStr("Super Market name");
	pSuperMarket->numOfCustomers = 0;
	pSuperMarket->customerList = NULL;
	pSuperMarket->numOfItem = 0;
	pSuperMarket->itemsInShop = NULL;

}

int isRegister(SuperMarket* pSuperMarket,const char* id)
{
	for (int i = 0; i < pSuperMarket->numOfCustomers; i++)
	{
		if (strcmp(pSuperMarket->customerList[i].id,id) != 0)
			return 0;
	}
	return 1;
}

void printItemsInShop(SuperMarket* pSuperMarket, Product* product)
{
	for (int i = 0; i < pSuperMarket->numOfItem;i++) {
		printProduct(&pSuperMarket->itemsInShop[i]);
	}
}

void printSuperMarket(SuperMarket* pSuperMarket)
{
	printf("Super Market Name %s: ", pSuperMarket->name);
	printProduct(pSuperMarket);	
	printCustomer(pSuperMarket);

}

void addItemToShop(SuperMarket* pSuperMarket)
{
	Product* pProduct = (Product*)malloc(sizeof(Product));
	if (!pProduct)
		return NULL;
	
	pSuperMarket->itemsInShop = (Product*)safeRealloc(pSuperMarket->itemsInShop, (pSuperMarket->numOfItem + 1) * sizeof(Product));
	if (!pSuperMarket->itemsInShop)
	{
		free(pProduct);
		return NULL;
		
	}
	initProduct(pSuperMarket, pProduct);
	pSuperMarket->itemsInShop[pSuperMarket->numOfItem] = pProduct;
	pSuperMarket->numOfItem++;
}

void addCustomerToShop(SuperMarket* pSuperMarket)
{
	pSuperMarket->customerList = (Customer*)safeRealloc(pSuperMarket->customerList, (pSuperMarket->numOfCustomers + 1) * sizeof(Customer));
	if (!pSuperMarket->customerList)
		return NULL;
	initCustomer(&pSuperMarket->customerList[pSuperMarket->numOfCustomers]);
	pSuperMarket->numOfCustomers++;
}

void printByType(SuperMarket* pSuperMarket, Type* theType)
{
	int count = 0;
	for (int i = 0; i < pSuperMarket->numOfItem; i++)
	{
		if (theType == pSuperMarket->itemsInShop[i]->theType) {
			Product* pProduct = &pSuperMarket->itemsInShop[i];
			printf("%s                 %s       %s       %f       %d       %s", pProduct->name, pProduct->qr, pProduct->theType, pProduct->price, pProduct->quantity, pProduct->expiration);
			count++;
		}

	}
	if (count == 0) {
		printf("There are no product of type %s in market %s", theType, pSuperMarket->name);
	}

}

void freeSuperMarket(SuperMarket* pSuperMarket)
{
	free(pSuperMarket->name);
	free(pSuperMarket->customerList);
	free(pSuperMarket->itemsInShop);
}


