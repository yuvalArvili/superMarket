#pragma once
#ifndef __PRODUCT_H
#define __PRODUCT_H

#include "date.h"
#include "superMarket.h"
#include "qr.h"


#define LEN 20


typedef enum { eShelf, eFrozen, eFridge, eFruitVegtable, eNofTypes } Type;
const char* typeTilte[eNofTypes];

typedef struct
{
	char name[LEN];
	Qr qr;
	Type theType;
	float price;
	int quantity;
	Date expiration;

}Product;

void initProduct(SuperMarket* pSuperMarket, Product* pProduct);
void printProduct(SuperMarket* pSuperMarket);
Type getTypeFromUser();

#endif