#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "product.h"
#include "date.h"

const char* typeTilte[eNofTypes] = { "Shelf", "Frozen", "Fridge", "FruitVegtable"};

void initProduct(SuperMarket* pSuperMarket,Product* pProduct)
{
	printf("enter product name up to 20 chars");
	scanf("%s ", pProduct->name);
	pProduct->theType = getTypeFromUser();
	strcpy(&pProduct->qr, makeQr(pProduct->theType, pSuperMarket));
	printf("please enter price of product");
	scanf("%f ", pProduct->price);
	printf("please enter quantity of product");
	scanf("%f ", pProduct->quantity);
	initDate(&pProduct->expiration);


}

void printProduct(SuperMarket* pSuperMarket)
{
	printf("There are %d products ", pSuperMarket->numOfItem);
	printf("Name                 Barcode       Type       Price       Count In Stock       Expiry Date \n ------------------------------------------------------------------------------------------");
	for (int i = 0; i < pSuperMarket->numOfItem; i++)
	{
		Product* pProduct = &pSuperMarket->itemsInShop[i];
		printf("%s                 %s       %s       %f       %d       %s", pProduct->name, pProduct->qr, pProduct->theType, pProduct->price, pProduct->quantity, pProduct->expiration);
	}

	
}

Type getTypeFromUser()
{
	int i, t;
	printf("Enter one of the following types\n");
	do {
		for (i = 0; i < eNofTypes; i++)
			printf("Enter %d for %s\n", i, typeTilte[i]);
		scanf("%d", &t);
	} while (t < 0 || t >= eNofTypes);
	return (Type)t;
}

